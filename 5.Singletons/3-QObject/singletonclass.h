#ifndef SINGLETONCLASS_H
#define SINGLETONCLASS_H

#include <QObject>
#include <QQmlEngine>
#include <QJSEngine>
#include <QTimer>

class SingletonClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int someProperty READ someProperty WRITE setSomeProperty NOTIFY somePropertyChanged)
public:
    explicit SingletonClass(QObject *parent = nullptr);

    int someProperty() const;

    void setSomeProperty(int someProperty);

    static QObject *singletonProvider(QQmlEngine *engine, QJSEngine *scriptEngine);

signals:

    void somePropertyChanged(int someProperty);

private :

    int m_someProperty;
    QTimer * m_timer;
};

#endif // SINGLETONCLASS_H
