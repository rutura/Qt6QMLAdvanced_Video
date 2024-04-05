#include "datasource.h"

DataSource::DataSource(QObject *parent) : QObject(parent)
{
    addPerson(new Person("Jamie Lannister","red",33));
    addPerson(new Person("Marry Lane","cyan",26));
    addPerson(new Person("Steve Moors","yellow",44));
    addPerson(new Person("Victor Trunk","dodgerblue",30));
    addPerson(new Person("Ariel Geeny","blue",33));
    addPerson(new Person("Knut Vikran","lightblue",26));

}

QList<Person *> DataSource::dataItems()
{
    return mPersons;
}

void DataSource::addPerson(Person *person)
{
    emit prePersonAdded();
    mPersons.append(person);
    emit postPersonAdded();
}

void DataSource::addPerson()
{
    Person *person = new Person("Added Person","yellowgreen",45,this);
    addPerson(person);
}

void DataSource::addPerson(const QString &names, const int &age)
{
    Person *person=new Person(names,"yellowgreen",age);
    addPerson(person);
}

void DataSource::removePerson(int index)
{
    emit prePersonRemoved(index);
    mPersons.removeAt(index);
    emit postPersonRemoved();
}

void DataSource::removeLastPerson()
{
    removePerson(mPersons.size()-1);
}
