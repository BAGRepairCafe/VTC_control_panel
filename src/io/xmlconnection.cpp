#include "xmlconnection.hpp"
#include <QUrlQuery>
#include <iostream>

namespace VTC {

    XmlConnection::XmlConnection(QUrl url, QObject* parent)
        : QObject(parent)
        , networkAccessManager{new QNetworkAccessManager(this)}
        , url{url} { }

    QNetworkReply* XmlConnection::authenticate(QString username, QString password)
            {
                QUrl authUrl = url;
                authUrl.setPath("/auth/xml");
                QNetworkRequest request = QNetworkRequest{authUrl};

                request.setRawHeader("Accept", "*/*");
                request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
                QUrlQuery postData{QPair<QString, QString>{"vertec_username", username}, QPair<QString, QString>{"password", password}};
                request.setRawHeader("Content-Length", QString{postData.query().length()}.toStdString().c_str());

                connect(networkAccessManager, &QNetworkAccessManager::finished,
                        this, &XmlConnection::receivedAuthToken);
                return networkAccessManager->post(request, postData.query().toStdString().c_str());
            }

    void XmlConnection::receivedAuthToken(QNetworkReply* reply)
    {
        if(reply->error() == QNetworkReply::NetworkError::NoError) {
            const int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
            if (statusCode >= 200 && statusCode < 300) {
                basicAuthToken = QString(reply->readAll());
            } else {
                qDebug() << "Statscode of Authrequest: " << statusCode;
            }
        } else {
            qDebug() << "Error while making network request:"
                        << reply->error();
        }

        reply->deleteLater();
        disconnect(networkAccessManager, &QNetworkAccessManager::finished,
                this, &XmlConnection::receivedAuthToken);
    }
}
