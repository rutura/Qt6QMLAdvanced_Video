#ifndef STAIR_H
#define STAIR_H

#include <QObject>
#include <QColor>
#include <QtQml>

class Stair : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged) //Color of the Stair rect fill
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)  //Value of the Stair e.g 143
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)  //Text of the Stair e.g RW
    Q_PROPERTY(int from READ from WRITE setFrom NOTIFY fromChanged)      //Starting point of the Stair horizontally e.g 50 . All stairs are 50 wide

public:
    explicit Stair(QObject *parent = nullptr);

    QColor color() const;
    int value() const;
    QString text() const;
    int from() const;
    void setColor(QColor color);
    void setValue(int value);
    void setText(QString text);
    void setFrom(int from);

signals:
    void colorChanged(QColor color);
    void valueChanged(int value);
    void textChanged(QString text);
    void fromChanged(int from);

private :
    QColor m_color;
    int m_value;
    QString m_text;
    int m_from;
};

#endif // STAIR_H
