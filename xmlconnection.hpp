#ifndef XMLCONNECTION_HPP
#define XMLCONNECTION_HPP

#include <QNetworkReply>
#include <QString>
#include <QUrl>


namespace VTC {
    class XmlConnection : public QObject
    {
        QNetworkAccessManager* networkAccessManager;
        QString basicAuthToken;
        const QUrl url;
    public:
        XmlConnection(QUrl url, QObject* parent = nullptr);
        [[nodiscard]] QNetworkReply* authenticate(QString username, QString password);
        ~XmlConnection();

    public slots:
        void receivedAuthToken(QNetworkReply* reply);
    };
}

#endif // XMLCONNECTION_HPP
