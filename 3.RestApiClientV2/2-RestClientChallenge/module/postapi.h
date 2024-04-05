#ifndef POSTAPI_H
#define POSTAPI_H

#include <QObject>
#include <QQmlEngine>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include  <QQmlComponent>

class PostAPI : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QJsonArray jsonArray READ jsonArray CONSTANT)
  QML_ELEMENT
public:
  explicit PostAPI(QObject *parent = nullptr);
  QJsonArray jsonArray() const;
public slots:
  void fetchPosts();
signals:
  void error(QString errorString);
private:
  QJsonArray m_postJsonArray;
  QNetworkAccessManager* m_networkAccessManager;
};

#endif// POSTAPI_H
