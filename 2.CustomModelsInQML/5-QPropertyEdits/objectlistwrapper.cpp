#include <QDebug>
#include "objectlistwrapper.h"
#include "person.h"

ObjectListWrapper::ObjectListWrapper(QObject *parent) : QObject(parent)
{
    populateModelWithData();
}

bool ObjectListWrapper::initialize(QGuiApplication * app)
{
    resetModel();

    const QUrl url(u"qrc:/QPropertyEdits/main.qml"_qs);
    QObject::connect(&mEngine, &QQmlApplicationEngine::objectCreated,
                         app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    mEngine.load(url);

    if (mEngine.rootObjects().isEmpty())
        return false;

    return true;

}

void ObjectListWrapper::setNames(int index, const QString &names)
{
    qDebug() << "Changing names to : " << names;
    if(index >= mPersons.size())
        return;
    Person * person = static_cast<Person *> (mPersons.at(index));
    if( names!= person->names())
    {
        person->setNames(names);

    }
    printPersons();
}

void ObjectListWrapper::setAge(int index, const int &age)
{
    if(index >= mPersons.size())
        return;
    Person * person = static_cast<Person *> (mPersons.at(index));
    if( age!= person->age())
    {
        person->setAge(age);
    }
    printPersons();
}

void ObjectListWrapper::setFavoriteColor(int index, const QString &favoriteColor)
{
    if(index >= mPersons.size())
        return;
    Person * person = static_cast<Person *> (mPersons.at(index));
    if( favoriteColor!= person->favoriteColor())
    {
        person->setFavoriteColor(favoriteColor);

    }
    printPersons();
}

QList<QObject *> ObjectListWrapper::persons() const
{
    return mPersons;
}

void ObjectListWrapper::addPerson()
{
    mPersons.append(new Person("New Person","green",32,this));
    emit mypersonsChanged(mPersons);
}

QList<QObject *> ObjectListWrapper::mypersons() const
{
    return mPersons;
}

void ObjectListWrapper::setMypersons(QList<QObject *> mypersons)
{
    if (mPersons == mypersons)
        return;

    mPersons = mypersons;
    emit mypersonsChanged(mPersons);
}

void ObjectListWrapper::populateModelWithData()
{
    mPersons.append(new Person("John Doe","green",32,this));
    mPersons.append(new Person("Mary Green","blue",23,this));
    mPersons.append(new Person("Mitch Nathson","dodgerblue",30,this));
}

void ObjectListWrapper::resetModel()
{
    mEngine.rootContext()->setContextProperty("Wrapper",this);
    mEngine.rootContext()->setContextProperty("myModel",QVariant::fromValue(persons()));

}

void ObjectListWrapper::printPersons()
{
    qDebug() << "-------------Persons--------------------";
    foreach (QObject * obj, mPersons) {
        Person * person = static_cast<Person *> (obj);
        qDebug() << person->names() << " " << person->age() << " " << person->favoriteColor();
    }
}
