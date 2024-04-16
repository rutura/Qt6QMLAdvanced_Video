/*
 *      . This example shows that we can even parse a custom qml type
 *      . We use the footbal team we built earlier in the course as
 *          a use case.
 *      . To set up this project, we start with a console app
 *      . add the modules (Core,Gui,Qml) in the CMakeLists.txt file
 *      . and store our main.qml file in the rousource file named qml.qrc
 *      . the actual main.qml file lives in a folder named qml on the file
 *          system.
 *
 *      . Use the Qt5 course as a reference and improvise.
 *
 * */


#include <QCoreApplication>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlProperty>
#include <QDebug>
#include <player.h>
#include <footballteam.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Register Types
    qmlRegisterType<Player>("com.blikoon.Football", 1,0, "Player");
    qmlRegisterType<FootBallTeam>("com.blikoon.Football", 1,0, "FootballTeam");

    QQmlEngine engine;
    QQmlComponent component(&engine, QUrl("qrc:/qml/main.qml"));

    FootBallTeam * team = qobject_cast<FootBallTeam* > (component.create()); // FootBallTeam is the root element in the QML file

    if(team && team->captain()){
        qDebug() << "Team : " << team->title() << " , captain is : " << team->captain()->name();
        qDebug() << "The players are : ";

        for ( int i = 0; i < team->playerCountCustom() ; i++){
            qDebug() << " " << team->playerCustom(i)->name();
        }
    }
    return a.exec();
}
