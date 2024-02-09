#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QQuickStyle>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQuickStyle::setStyle("Material");

    /**
     *Setup to expose a moddel as a context property
     */

    // QList<QObject *> personList;
    // personList.append(new Person("John Doe C++","green",32,&engine));
    // personList.append(new Person("Mary Green","blue",23,&engine));
    // personList.append(new Person("Mitch Nathson","dodgerblue",30,&engine));
    // personList.append(new Person("Daniel Sten","red",67,&engine));
    // personList.append(new Person("John Doe C++","green",32,&engine));
    // personList.append(new Person("Mary Green","blue",23,&engine));
    // personList.append(new Person("Mitch Nathson","dodgerblue",30,&engine));
    // personList.append(new Person("Daniel Sten","red",67,&engine));
    // personList.append(new Person("John Doe C++","green",32,&engine));
    // personList.append(new Person("Mary Green","blue",23,&engine));
    // personList.append(new Person("Mitch Nathson","dodgerblue",30,&engine));
    // personList.append(new Person("Daniel Sten","red",67,&engine));
    // personList.append(new Person("John Doe C++","green",32,&engine));
    // personList.append(new Person("Mary Green","blue",23,&engine));
    // personList.append(new Person("Mitch Nathson","dodgerblue",30,&engine));
    // personList.append(new Person("Daniel Sten","red",67,&engine));

    // //Expose the list
    // engine.rootContext()->setContextProperty("personModel",QVariant::fromValue(personList));

    const QUrl url(u"qrc:/4a-EditableObjectListModel/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
