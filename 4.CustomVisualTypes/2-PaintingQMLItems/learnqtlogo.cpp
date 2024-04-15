#include <QPainter>
#include "learnqtlogo.h"

LearnQtLogo::LearnQtLogo(QQuickItem *parent) : QQuickPaintedItem(parent),
  m_bgColor(Qt::white),
  m_textColor(Qt::blue),
  m_text("Learn GUI"),
  m_topic(QTCPP)
{
    setWidth(128);
    setHeight(128);
}

void LearnQtLogo::paint(QPainter *painter)
{
    //Draw the image
    QString imagePath = ":/images/LearnQt.png";
    if( m_topic == QTQUICK){
        imagePath = ":/images/LearnQtQuick.png";
    }
    QImage mImage(imagePath);
    QImage scaledImage = mImage.scaled(width() , height());
    QRect mRect(mImage.rect());
    painter->drawImage(mRect,scaledImage);

    //Draw the rectangle at the bottom
    painter->setBrush(bgColor());
    painter->drawRect(mRect.bottomLeft().x(),
                      mRect.bottomLeft().y()-33,
                      width(),33);

    //Draw the text
    painter->setPen(textColor());
    auto txtPos = mRect.bottomLeft();
    txtPos.rx() += 10;
    txtPos.ry() -= 10;
    painter->setFont(QFont ("Consolas", 10, QFont::Bold));
    painter->drawText(txtPos,text());
}

QColor LearnQtLogo::bgColor() const
{
    return m_bgColor;
}

QColor LearnQtLogo::textColor() const
{
    return m_textColor;
}

QString LearnQtLogo::text() const
{
    return m_text;
}

LearnQtLogo::QtTopic LearnQtLogo::topic() const
{
    return m_topic;
}

void LearnQtLogo::setBgColor(QColor bgColor)
{
    if (m_bgColor == bgColor)
        return;

    m_bgColor = bgColor;
    emit bgColorChanged(m_bgColor);
}

void LearnQtLogo::setTextColor(QColor textColor)
{
    if (m_textColor == textColor)
        return;

    m_textColor = textColor;
    emit textColorChanged(m_textColor);
}

void LearnQtLogo::setText(QString text)
{
    if (m_text == text)
        return;

    m_text = text;
    emit textChanged(m_text);
}

void LearnQtLogo::setTopic(LearnQtLogo::QtTopic topic)
{
    if (m_topic == topic)
        return;

    m_topic = topic;
    emit topicChanged(m_topic);
}
