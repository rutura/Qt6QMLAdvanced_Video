#ifndef POST_H
#define POST_H

#include <QObject>
#include <QQmlEngine>
#include  <QQmlComponent>

class Post : public QObject
{
  Q_OBJECT
  Q_PROPERTY(int userId READ userId WRITE setUserId NOTIFY userIdChanged)
  Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
  Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged )
  Q_PROPERTY(QString body READ body WRITE setBody NOTIFY bodyChanged )
  QML_ELEMENT
public:
  explicit Post(QObject *parent = nullptr);

  int userId() const;
  void setUserId(int newUserId);

  int id() const;
  void setId(int newId);

  QString title() const;
  void setTitle(QString newTitle);

  QString body() const;
  void setBody(QString newBody);

  static Post* fromJson(const QJsonObject &jsonObject);

signals:
  void userIdChanged();
  void idChanged();
  void titleChanged();
  void bodyChanged();
private:
  int m_UserId;
  int m_Id;
  QString m_Title;
  QString m_Body;
};

#endif// POST_H
