#include <QDebug>
#include "singletonclass.h"

SingletonClass::SingletonClass(QObject *parent) : QObject(parent),
    m_someProperty(0),
    m_timer(new QTimer(this))
{
    qDebug() << "Singleton instance created";
    connect(m_timer,&QTimer::timeout,[=](){
        setSomeProperty(m_someProperty+3);
    });
    m_timer->start(2000);

}

int SingletonClass::someProperty() const
{
    return m_someProperty;
}

void SingletonClass::setSomeProperty(int someProperty)
{
    if (m_someProperty == someProperty)
        return;

    m_someProperty = someProperty;
    emit somePropertyChanged(m_someProperty);
}

QObject *SingletonClass::singletonProvider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    SingletonClass * example = new SingletonClass();
    return example;

}
