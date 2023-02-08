#ifndef SINGLETONCLASS_H
#define SINGLETONCLASS_H

#include <QObject>
#include <QQmlEngine>
#include <QJSEngine>

class SingletonClass : public QObject
{
    Q_OBJECT
public:
    explicit SingletonClass(QObject *parent = nullptr);

    static QJSValue singletonProvider(QQmlEngine *engine, QJSEngine *scriptEngine);

signals:

public slots:
};

#endif // SINGLETONCLASS_H
