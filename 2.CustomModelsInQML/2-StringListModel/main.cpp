#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QStringList continentList;
    continentList.append("Africa");
    continentList.append("Europe");
    continentList.append("America");
    continentList.append("Asia");
    continentList.append("Oceania");
    continentList.append("Antarctica");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("continentModel",continentList);

    engine.rootContext()->setContextProperties(QList<QQmlContext::PropertyPair>{
        {"itemList1", QStringList{"List1Item1", "List1Item2", "List1Item3"}},
        {"itemList2",QStringList{"List2Item1", "List2Item2", "List2Item3"}}
    });

    const QUrl url(u"qrc:/StringListModel/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
