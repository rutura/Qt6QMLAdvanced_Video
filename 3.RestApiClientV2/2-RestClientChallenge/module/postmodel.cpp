#include "postmodel.h"
#include <QJsonObject>

PostModel::PostModel(QObject *parent): QAbstractListModel{parent}
{}

PostAPI *PostModel::postAPI() const
{
  return m_postAPI;
}

void PostModel::setPostAPI(PostAPI *newPostAPI)
{
  if(m_postAPI != newPostAPI){
    m_postAPI = newPostAPI;
    emit postAPIChanged();
  }
}

void PostModel::refresh()
{
  if(m_postAPI == nullptr)return;
  // m_postAPI->fetchPosts(); // can be executed from qml
  QJsonArray postJsonArray = m_postAPI->jsonArray();
  if(postJsonArray.isEmpty()){
    emit error("Post array is empty");
    return;
  }
  beginResetModel();
  for(int i = 0; i< postJsonArray.count(); ++i){
    QJsonObject object = postJsonArray.at(i).toObject();
    Post* post = Post::fromJson(object);
    m_postList << post;
  }
  endResetModel();
}

void PostModel::removeLast()
{
  if(m_postList.empty()) return;
  beginRemoveRows(QModelIndex(),m_postList.length() - 1, m_postList.length() - 1);// index of load
  m_postList.removeLast();
  endRemoveRows();
}

int PostModel::rowCount(const QModelIndex &parent) const
{
  return m_postList.length();
}

QVariant PostModel::data(const QModelIndex &index, int role) const
{
  if(index.isValid() && index.row() >= 0 && index.row() < m_postList.length()){
    switch ((Role)role) {
    case UserIdRole:
      return m_postList[index.row()]->userId();
    case IdRole:
      return m_postList[index.row()]->id();
    case TitleRole:
      return m_postList[index.row()]->title();
    case BodyRole:
      return m_postList[index.row()]->body();
    }
  }
  return {};
}

QHash<int, QByteArray> PostModel::roleNames() const
{
  static const QHash<int, QByteArray> names {
    { UserIdRole, "userId" },
    { IdRole, "id" },
    { TitleRole, "title" },
    { BodyRole, "body" },
    };
  return names;
}
