#include "stair.h"

Stair::Stair(QObject *parent) : QObject(parent)
{

}

QColor Stair::color() const
{
    return m_color;
}

int Stair::value() const
{
    return m_value;
}

QString Stair::text() const
{
    return m_text;
}

int Stair::from() const
{
    return m_from;
}

void Stair::setColor(QColor color)
{
    if (m_color == color)
        return;

    m_color = color;
    emit colorChanged(m_color);
}

void Stair::setValue(int value)
{
    if (m_value == value)
        return;

    m_value = value;
    emit valueChanged(m_value);
}

void Stair::setText(QString text)
{
    if (m_text == text)
        return;

    m_text = text;
    emit textChanged(m_text);
}

void Stair::setFrom(int from)
{
    if (m_from == from)
        return;

    m_from = from;
    emit fromChanged(m_from);
}
