#include "personmodel.h"

PersonModel::PersonModel(QObject *parent)
    : QAbstractListModel{parent}
{
    addPerson(new Person("Jamie Lannister","red",33));
    addPerson(new Person("Marry Lane","cyan",26));
    addPerson(new Person("Steve Moors","yellow",44));
    addPerson(new Person("Victor Trunk","dodgerblue",30));
    addPerson(new Person("Ariel Geeny","blue",33));
    addPerson(new Person("Knut Vikran","lightblue",26));
}

int PersonModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return mPersons.size();
}

QVariant PersonModel::data(const QModelIndex &index, int role) const
{

    if (index.row() < 0 || index.row() >= mPersons.count())
        return QVariant();
    //The index is valid
    Person * person = mPersons[index.row()];

    if(role == NamesRole){
        return person->names();
    }
    if(role == FavoriteColorRole){
        return person->favoriteColor();
    }
    if(role == AgeRole){
        return person->age();
    }
    return QVariant();

}

QHash<int, QByteArray> PersonModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NamesRole] = "names";
    roles[FavoriteColorRole] = "favoriteColor";
    roles[AgeRole] = "age";
    return roles;
}

Qt::ItemFlags PersonModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsEditable;
}

bool PersonModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Person* person = mPersons[index.row()]; // The person to edit
    bool somethingChanged{false};

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
    if(somethingChanged){
        emit dataChanged(index,index, QVector<int>() << role);
        return true;
    }
    return false;

}


void PersonModel::addPerson(Person* person)
{
    const int index = mPersons.size();
    beginInsertRows(QModelIndex(),index,index);//Tell the model that you are about to add data
    mPersons.append(person);
    endInsertRows();
}

void PersonModel::addPerson()
{
    Person *person = new Person("Added Person","yellowgreen",45,this);
    addPerson(person);
}

void PersonModel::addPerson(const QString &names, const int &age)
{
    Person *person=new Person(names,"yellowgreen",age);
    addPerson(person);
}

void PersonModel::removePerson(int index)
{
    beginRemoveRows(QModelIndex(),index,index);
    mPersons.removeAt(index);
    endRemoveRows();

}

void PersonModel::removeLastPerson()
{
    removePerson(mPersons.size()-1);
}

