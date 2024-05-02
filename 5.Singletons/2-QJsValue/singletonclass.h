#ifndef SINGLETONCLASS_H
#define SINGLETONCLASS_H

#include <QObject>
#include <QQmlEngine>
#include <QJSEngine>

class SingletonClass : public QObject
{
    Q_OBJECT
    /*
    QML_SINGLETON
    QML_ELEMENT
    */
public:
    explicit SingletonClass(QObject *parent = nullptr);

    static QJSValue singletonProvider(QQmlEngine *engine, QJSEngine *scriptEngine);
    //Q_INVOKABLE QJSValue getJsValue();
};

#endif // SINGLETONCLASS_H
