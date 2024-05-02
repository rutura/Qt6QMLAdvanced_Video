#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QObject>
#include <QQmlEngine>
#include <QAbstractListModel>
#include "person.h"

class PersonModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
    enum PersonRoles{
        NamesRole = Qt::UserRole + 1,
        FavoriteColorRole,
        AgeRole
    };

public:
    explicit PersonModel(QObject *parent = nullptr);

signals:

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);


    //Helper function
    Q_INVOKABLE void addPerson(Person* person);
    Q_INVOKABLE void addPerson();
    Q_INVOKABLE void addPerson(const QString & names,const int & age);
    Q_INVOKABLE void removePerson(int index);
    Q_INVOKABLE void removeLastPerson();

private:
    QList<Person*> mPersons;
};

#endif // PERSONMODEL_H
