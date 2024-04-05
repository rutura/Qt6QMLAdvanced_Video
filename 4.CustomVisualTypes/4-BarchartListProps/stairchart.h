#ifndef STAIRCHART_H
#define STAIRCHART_H

#include <QObject>
#include <QQuickPaintedItem>
#include <QtQml>
#include "stair.h"

class StairChart : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QQmlListProperty<Stair> stairs READ stairs NOTIFY stairsChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QColor bgColor READ bgColor WRITE setBgColor NOTIFY bgColorChanged)
    Q_CLASSINFO("DefaultProperty", "stairs")


public:
    explicit StairChart(QQuickItem *parent = nullptr);

    void paint(QPainter * painter);
    QQmlListProperty<Stair> stairs();
    QString title() const;
    QColor bgColor() const;

signals:

    void stairsChanged();
    void titleChanged(QString title);
    void bgColorChanged(QColor bgColor);

public slots:

void setTitle(QString title);
void setBgColor(QColor bgColor);

private :
    static void appendStair(QQmlListProperty<Stair>* list, Stair * stair);
    void drawStair(QPainter *painter, QRect mRect, QColor mColor, qreal barValue,int startingPoint);
    void drawScale(QPainter *painter, QRect mRect);
    QList<Stair*> m_stairs;
    QString m_title;
    QColor m_bgColor;
};

#endif // STAIRCHART_H
