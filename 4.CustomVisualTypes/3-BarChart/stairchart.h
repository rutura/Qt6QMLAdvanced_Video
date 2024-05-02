#ifndef STAIRCHART_H
#define STAIRCHART_H

#include <QObject>
#include <QQmlEngine>
#include <QQuickPaintedItem>
#include <QtQml>

class StairChart : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit StairChart(QQuickItem *parent = nullptr);

signals:

    // QQuickPaintedItem interface
public:
    void paint(QPainter *painter);

private:
    void drawStair(QPainter *painter, QRect mRect, QColor mColor, qreal barValue,int startingPoint);
    void drawScale(QPainter *painter, QRect mRect);
};

#endif // STAIRCHART_H
