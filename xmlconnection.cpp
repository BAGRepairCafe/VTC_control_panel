#include "xmlconnection.hpp"
#include <iostream>

namespace VTC {

    XmlConnection::XmlConnection(QUrl url, QObject* parent)
        : QObject(parent)
        , networkAccessManager{new QNetworkAccessManager(this)}
        , url{url}
            {
            }

    QNetworkReply* XmlConnection::authenticate(QString username, QString password)
            {
                auto request = QNetworkRequest{url};
                request.setRawHeader("user-agent", "curl/7.79.1");
                request.setRawHeader("accept", "*/*");

                connect(networkAccessManager, &QNetworkAccessManager::finished,
                        this, &XmlConnection::receivedAuthToken);
                return networkAccessManager->get(request);
            }

    XmlConnection::~XmlConnection() {
        delete this->networkAccessManager;
    }

    void XmlConnection::receivedAuthToken(QNetworkReply* reply)
    {
        if(reply->error() == QNetworkReply::NetworkError::NoError) {
            qDebug() << QString(reply->readAll());
            qDebug () << "Statscode: " << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        } else {
            qDebug() << "Error while making network request:"
                        << reply->error();
        }
    }
}
