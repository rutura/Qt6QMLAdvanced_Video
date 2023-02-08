/*
 *      . Handling a QML signal in C++
 *      . Because we can hunt down a qml element emiting the signal,
 *          we can cast that to an object and connect a slot to it in C++
 *
 *      . The rest is just organizing the code
 *      . Improvise.
 *
 * */

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "appwrapper.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    AppWrapper wrapper;

    if( !wrapper.initialize())
        return -1;


    return app.exec();
}
