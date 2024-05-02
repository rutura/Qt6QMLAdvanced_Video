#include "post.h"

Post::Post(const QString & post,QObject *parent) : QObject(parent),
    m_post(post)
{

}

QString Post::post() const
{
    return m_post;
}

void Post::setPost(QString post)
{
    if (m_post == post)
        return;
    m_post = post;
    emit postChanged(m_post);
}
