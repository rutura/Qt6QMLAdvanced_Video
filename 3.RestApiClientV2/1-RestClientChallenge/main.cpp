#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include "appwrapper.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Material");

    AppWrapper wrapper;

    if ( !wrapper.initialize(&app))
        return -1;

    return app.exec();
}
