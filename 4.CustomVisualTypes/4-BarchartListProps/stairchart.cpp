
#include <QPainter>
#include <QPen>
#include <QBrush>
#include "stairchart.h"

StairChart::StairChart(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    setWidth(400);
    setHeight(400);
}

void StairChart::drawStair(QPainter *painter, QRect mRect,
                           QColor mColor, qreal barValue,int startingPoint)
{
    painter->setPen(mColor);
    painter->setBrush(QBrush(mColor));

    painter->drawRect(mRect.bottomLeft().x()+startingPoint,
                      mRect.bottomLeft().y()-barValue,
                      50,
                      barValue);
}

void StairChart::drawScale(QPainter *painter, QRect mRect)
{
    QPen mPen;
    mPen.setWidth(2);
    mPen.setColor(Qt::black);
    painter->setPen(mPen);

    painter->drawLine(mRect.bottomLeft()+QPoint(0,0),mRect.bottomLeft()+QPoint(20,0));
    painter->drawText(mRect.bottomLeft()+QPoint(3,-10),"0");

    painter->drawLine(mRect.bottomLeft()+QPoint(0,-100),mRect.bottomLeft()+QPoint(20,-100));
    painter->drawText(mRect.bottomLeft()+QPoint(3,-110),"100");

    painter->drawLine(mRect.bottomLeft()+QPoint(0,-200),mRect.bottomLeft()+QPoint(20,-200));
    painter->drawText(mRect.bottomLeft()+QPoint(3,-210),"200");

    painter->drawLine(mRect.bottomLeft()+QPoint(0,-300),mRect.bottomLeft()+QPoint(20,-300));
    painter->drawText(mRect.bottomLeft()+QPoint(3,-310),"300");
}

void StairChart::paint(QPainter *painter)
{
    QRect mRect(0,0,width(),height());

    painter->save();
    QPen mPen;
    mPen.setColor(Qt::gray);
    mPen.setWidth(3);
    painter->setPen(mPen);
    painter->setBrush(QBrush(bgColor()));
    painter->drawRect(mRect);

    //Draw Title
    painter->drawText(mRect.topLeft()+QPoint(30,30),
                      title());

    //Draw the stairs
    for ( int i = 0 ; i < m_stairs.size() ; i++){

        Stair * stair = m_stairs[i];
        painter->setPen(stair->color());
        painter->setBrush(QBrush(stair->color()));

        QRect stairRect(mRect.bottomLeft().x()+stair->from(),
                        mRect.bottomLeft().y()-stair->value(),
                        50,stair->value());

        painter->drawRect(stairRect);

        painter->setPen(Qt::white);
        painter->setBrush(QBrush(Qt::white));

        painter->drawRect(stairRect.topLeft().x()+10,
                          stairRect.topLeft().y()+10,
                          25,25);

        painter->setFont(QFont("Consolas", 10, QFont::Bold));
        painter->setPen(Qt::black);
        painter->drawText(stairRect.adjusted(15,15,0,0),stair->text());

    }

    /*
    //Draw the border
    QPen mPen;
    mPen.setColor(Qt::red);
    mPen.setWidth(4);

    painter->setPen(mPen);
    painter->drawRect(mRect);

    //Draw bars
    painter->setBrush(QBrush(Qt::yellow));
    painter->setPen(Qt::yellow);

    //Draw first bar
    drawStair(painter, mRect , Qt::red,200,50);
    drawStair(painter, mRect , Qt::blue,120,100);

    drawStair(painter, mRect , Qt::yellow,300,150);
    drawStair(painter, mRect , Qt::black,50,200);
    drawStair(painter, mRect , Qt::green,350,250);
    drawStair(painter, mRect , Qt::blue,100,300);
    */

    //Draw scale
    //QPen mPen;
    painter->setFont(QFont("Consolas", 10));
    drawScale(painter, mRect);

    painter->restore();
}

QQmlListProperty<Stair> StairChart::stairs()
{
    return QQmlListProperty<Stair>(this,this,&StairChart::appendStair,
                                   nullptr,
                                   nullptr,
                                   nullptr);
}

QString StairChart::title() const
{
    return m_title;
}

QColor StairChart::bgColor() const
{
    return m_bgColor;
}

void StairChart::setTitle(QString title)
{
    if (m_title == title)
        return;

    m_title = title;
    emit titleChanged(m_title);
}

void StairChart::setBgColor(QColor bgColor)
{
    if (m_bgColor == bgColor)
        return;

    m_bgColor = bgColor;
    emit bgColorChanged(m_bgColor);
}

void StairChart::appendStair(QQmlListProperty<Stair> *list, Stair *stair)
{
    StairChart * chart = qobject_cast<StairChart*> ( list->object);
    if ( chart){
        stair->setParent(chart);
        chart->m_stairs.append(stair);
        emit chart->stairsChanged();
    }
}
