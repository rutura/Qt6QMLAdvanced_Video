
#include <QDebug>
#include "personmodel.h"

PersonModel::PersonModel(QObject *parent) : QAbstractListModel(parent),
    m_signalConnected(false)
{
    setDataSource( new DataSource(this));
}

int PersonModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_dataSource->dataItems().size();
}

QVariant PersonModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_dataSource->dataItems().size())
        return QVariant();
    //The index is valid
    Person * person = m_dataSource->dataItems().at(index.row());
    if( role == NamesRole)
        return person->names();
    if( role == FavoriteColorRole)
        return person->favoriteColor();
    if( role == AgeRole)
        return person->age();
    return QVariant();
}

bool PersonModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Person * person = m_dataSource->dataItems().at(index.row());
    bool somethingChanged = false;

    switch (role) {
    case NamesRole:
    {
        if( person->names()!= value.toString()){
            qDebug() << "Changing names for " << person->names();
            person->setNames(value.toString());
            somethingChanged = true;
        }
    }
        break;
    case FavoriteColorRole:
    {
        if( person->favoriteColor()!= value.toString()){
            qDebug() << "Changing color for " << person->names();
            person->setFavoriteColor(value.toString());
            somethingChanged = true;
        }
    }
        break;
    case AgeRole:
    {
        if( person->age()!= value.toInt()){
            qDebug() << "Changing age for " << person->names();
            person->setAge(value.toInt());
            somethingChanged = true;
        }
    }

    }

    if( somethingChanged){
        emit dataChanged(index,index,QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags PersonModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> PersonModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NamesRole] = "names";
    roles[FavoriteColorRole] = "favoriteColor";
    roles[AgeRole] = "age";
    return roles;
}

DataSource *PersonModel::dataSource() const
{
    return m_dataSource;
}

QQmlListProperty<Person> PersonModel::persons()
{
    return QQmlListProperty<Person>(this, this,
                                    &PersonModel::appendPerson,
                                    &PersonModel::personCount,
                                    &PersonModel::person,
                                    &PersonModel::clearPersons);
}

void PersonModel::addPerson(const QString &names, const QString &favoriteColor, const int &age)
{
    Person * person = new Person(this);
    person->setNames(names);
    person->setFavoriteColor(favoriteColor);
    person->setAge(age);

    m_dataSource->addPerson(person);
}

void PersonModel::removeLastItem()
{
    m_dataSource->removePerson(m_dataSource->personCount()-1);
}

void PersonModel::appendPerson(QQmlListProperty<Person> * list, Person * person)
{
    reinterpret_cast<PersonModel *> (list->data)->dataSource()->addPerson(person);
}

qsizetype PersonModel::personCount(QQmlListProperty<Person> * list)
{
    return reinterpret_cast<PersonModel *> (list->data)->dataSource()->personCount();
}

Person *PersonModel::person(QQmlListProperty<Person> * list, qsizetype index)
{
    return reinterpret_cast<PersonModel *> (list->data)->dataSource()->personAt(index);
}

void PersonModel::clearPersons(QQmlListProperty<Person> * list)
{
    reinterpret_cast<PersonModel *> (list->data)->dataSource()->clearPersons();
}

void PersonModel::setDataSource(DataSource *dataSource)
{


    beginResetModel();

    if( m_dataSource && m_signalConnected)
        m_dataSource->disconnect(this);

    m_dataSource = dataSource;

    connect(m_dataSource,&DataSource::prePersonAdded,this,[=](){
        const int index = m_dataSource->dataItems().size();
        beginInsertRows(QModelIndex(),index,index);
    });

    connect(m_dataSource,&DataSource::postPersonAdded,this,[=](){
        endInsertRows();
    });

    connect(m_dataSource,&DataSource::prePersonRemoved,this,[=](int index){
        beginRemoveRows(QModelIndex(), index, index);
    });

    connect(m_dataSource,&DataSource::postPersonRemoved,this,[=](){
        endRemoveRows();
    });


    m_signalConnected = true;


    endResetModel();

}

