#ifndef STAIRCHART_H
#define STAIRCHART_H

#include <QObject>
#include <QQuickPaintedItem>
#include <QtQml>

class StairChart : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit StairChart(QQuickItem *parent = nullptr);
    void paint(QPainter * painter);
signals:
public slots:
private :
    void drawStair(QPainter *painter, QRect mRect, QColor mColor, qreal barValue,int startingPoint);
    void drawScale(QPainter *painter, QRect mRect);
};

#endif // STAIRCHART_H
