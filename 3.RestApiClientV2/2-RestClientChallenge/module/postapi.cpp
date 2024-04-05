#include "postapi.h"

PostAPI::PostAPI(QObject *parent) : QObject{ parent },
                                    m_networkAccessManager(new QNetworkAccessManager(this))
{
}

QJsonArray PostAPI::jsonArray() const
{
  return m_postJsonArray;
}

void PostAPI::fetchPosts()
{
  static const QUrl API_ENDPOINT("https://jsonplaceholder.typicode.com/posts");

  QNetworkRequest request;
  request.setUrl(API_ENDPOINT);

  QNetworkReply* mNetReply = m_networkAccessManager->get(request);

  connect(mNetReply, &QNetworkReply::finished, [=](){
    mNetReply->deleteLater();
    if(mNetReply->error() != QNetworkReply::NoError){
      emit error(mNetReply->errorString());
      return;
    }
    const QByteArray responseBuffer = mNetReply->readAll();
    const QJsonDocument document = QJsonDocument::fromJson(responseBuffer);
    m_postJsonArray = document.array();
  });
}
