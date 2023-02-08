#ifndef APPWRAPPER_H
#define APPWRAPPER_H

#include <QObject>
#include <QQmlApplicationEngine>

class AppWrapper : public QObject
{
    Q_OBJECT
public:
    explicit AppWrapper(QObject *parent = nullptr);

    bool initialize();

signals:

public slots:
private slots :
    void respondToClick(QString msg, const QVariant & object);

private:
    QQmlApplicationEngine mEngine;

signals:

};

#endif // APPWRAPPER_H
