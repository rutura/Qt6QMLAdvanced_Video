#ifndef POSTMODEL_H
#define POSTMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QQmlEngine>
#include  <QQmlComponent>
#include "post.h"
#include "postapi.h"

class PostModel : public QAbstractListModel
{
  Q_OBJECT
  Q_PROPERTY(PostAPI* postAPI READ postAPI WRITE setPostAPI NOTIFY postAPIChanged)
  QML_ELEMENT

public:
  enum Role {
    UserIdRole = Qt::UserRole + 1,
    IdRole,
    TitleRole,
    BodyRole
  };
  PostModel(QObject *parent = nullptr);
  PostAPI* postAPI() const;
  void setPostAPI(PostAPI* newPostAPI);

public slots:
  void refresh();
  void removeLast();

signals:
  void postAPIChanged();
  void error(QString errorString);

private:
  QPointer<PostAPI> m_postAPI;
  QList<Post*> m_postList;

  // QAbstractItemModel interface
public:
  int rowCount(const QModelIndex &parent) const override;
  QVariant data(const QModelIndex &index, int role) const override;
  QHash<int, QByteArray> roleNames() const override;
};

#endif// POSTMODEL_H
