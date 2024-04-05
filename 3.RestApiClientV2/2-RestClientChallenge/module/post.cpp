#include "post.h"
#include <QJsonObject>

Post::Post(QObject *parent) : QObject{ parent } {}


int Post::userId() const
{
  return m_UserId;
}

void Post::setUserId(int newUserId)
{
  if(newUserId != m_UserId){
    m_UserId = newUserId;
    emit userIdChanged();
  }
}

int Post::id() const
{
  return m_Id;
}

void Post::setId(int newId)
{
  if(newId != m_Id){
    m_Id = newId;
    emit idChanged();
  }
}

QString Post::title() const
{
  return m_Title;
}

void Post::setTitle(QString newTitle)
{
  if(newTitle != m_Title){
    m_Title = newTitle;
    emit titleChanged();
  }
}

QString Post::body() const
{
  return m_Body;
}

void Post::setBody(QString newBody)
{
  if(m_Body != newBody){
    m_Body = newBody;
    emit bodyChanged();
  }
}

Post* Post::fromJson(const QJsonObject &jsonObject)
{
  Post* post = new Post();
  post->setUserId(jsonObject.value("userId").toInt());
  post->setId(jsonObject.value("id").toInt());
  post->setTitle(jsonObject.value("title").toString());
  post->setBody(jsonObject.value("body").toString());

  return post;
}
