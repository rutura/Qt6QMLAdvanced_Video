#include <QPainter>
#include "learnqtlogo.h"

LearnQtLogo::LearnQtLogo(QQuickItem *parent)
    : QQuickPaintedItem{parent},
    m_bgColor(Qt::white),
    m_textColor(Qt::blue),
    m_text("Learn Gui"),
    m_topic(QTCPP)
{

    setWidth(128);
    setHeight(128);
}

void LearnQtLogo::paint(QPainter *painter)
{
    //Draw the image
    QString imagePath = ":/images/LearnQt.png";
    if(m_topic == QTQUICK){
        imagePath = ":/images/LearnQtQuick.png";
    }

    QImage mImage(imagePath);
    QImage scaledImage = mImage.scaled(width(),height());
    QRect mRect = (mImage.rect());
    painter->drawImage(mRect,scaledImage);


    //Draw the rectangle at the bottom
    painter->setBrush(bgColor());
    painter->drawRect(mRect.bottomLeft().x(),mRect.bottomLeft().y()-33, width(),33);

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

void LearnQtLogo::setBgColor(const QColor &newBgColor)
{
    if (m_bgColor == newBgColor)
        return;
    m_bgColor = newBgColor;
    emit bgColorChanged();
}

QColor LearnQtLogo::textColor() const
{
    return m_textColor;
}

void LearnQtLogo::setTextColor(const QColor &newTextColor)
{
    if (m_textColor == newTextColor)
        return;
    m_textColor = newTextColor;
    emit textColorChanged();
}

QString LearnQtLogo::text() const
{
    return m_text;
}

void LearnQtLogo::setText(const QString &newText)
{
    if (m_text == newText)
        return;
    m_text = newText;
    emit textChanged();
}

LearnQtLogo::QtTopic LearnQtLogo::topic() const
{
    return m_topic;
}

void LearnQtLogo::setTopic(const LearnQtLogo::QtTopic &newTopic)
{
    if (m_topic == newTopic)
        return;
    m_topic = newTopic;
    emit topicChanged();
}
