#ifndef JOKE_H
#define JOKE_H

#include <QObject>

class Post : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString post READ post WRITE setPost NOTIFY postChanged)
public:
    explicit Post(const QString & post, QObject *parent = nullptr);

    QString post() const;

    void setPost(QString post);

signals:
    void postChanged(QString post);

private :
    QString m_post;
};

#endif // JOKE_H
