#include "person.h"
#include <QQmlListProperty>

Person::Person(QObject *parent) : QObject(parent)
{

}

Person::Person(const QString &names, const QString &favoritecolor, const int &age, QObject *parent):
    QObject(parent),m_names(names),m_favoriteColor(favoritecolor),m_age(age)
{

}

QString Person::names() const
{
    return m_names;
}

QString Person::favoriteColor() const
{
    return m_favoriteColor;
}

int Person::age() const
{
    return m_age;
}

void Person::setNames(QString names)
{
    if (m_names == names)
        return;
    qDebug() << "Names changed from qml list model";
    m_names = names;
    emit namesChanged(m_names);
}

void Person::setFavoriteColor(QString favoriteColor)
{
    if (m_favoriteColor == favoriteColor)
        return;

    m_favoriteColor = favoriteColor;
    emit favoriteColorChanged(m_favoriteColor);
}

void Person::setAge(int age)
{
    if (m_age == age)
        return;
    qDebug() << "Age changed from qml list model";
    m_age = age;
    emit ageChanged(m_age);
}

PersonList::PersonList(QObject *parent): QObject(parent)
{
  mPersonList = QList<Person*>{
    new Person("John Doe C++","green",32, this),
    new Person("Mary Green","blue",23, this),
    new Person("Mitch Nathson","dodgerblue",30, this),
    new Person("Daniel Sten","red",67, this),
    // new Person("John Doe C++","green",32, this),
    // new Person("Mary Green","blue",23, this),
    // new Person("Mitch Nathson","dodgerblue",30, this),
    // new Person("Daniel Sten","red",67, this),
    // new Person("John Doe C++","green",32, this),
    // new Person("Mary Green","blue",23, this),
    // new Person("Mitch Nathson","dodgerblue",30, this),
    // new Person("Daniel Sten","red",67, this),
    // new Person("John Doe C++","green",32,this),
    // new Person("Mary Green","blue",23, this),
    // new Person("Mitch Nathson","dodgerblue",30, this),
    // new Person("Daniel Sten","red",67,this)
  };
}

QQmlListProperty<Person> PersonList::getPersons()
{
  return QQmlListProperty<Person>(this, &mPersonList);
}

void PersonList::refresh()
{
  emit personsChanged();
}

