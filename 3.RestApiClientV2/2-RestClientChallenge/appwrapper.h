#ifndef APPWRAPPER_H
#define APPWRAPPER_H
#include <QQmlApplicationEngine>
#include <QGuiApplication>

#include <QObject>
#include "datasource.h"
#include "postmodel.h"

class AppWrapper : public QObject
{
    Q_OBJECT
public:
    explicit AppWrapper(QObject *parent = nullptr);
    bool initialize(QGuiApplication * app);

private:
    QQmlApplicationEngine mEngine;
    PostModel mPostModel;
};

#endif // APPWRAPPER_H
