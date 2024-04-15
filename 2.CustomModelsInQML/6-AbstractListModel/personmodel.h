#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QtQml>
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
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex& index) const;
    QHash<int, QByteArray> roleNames() const;

    void addPerson( Person *person);
    Q_INVOKABLE void addPerson();
    Q_INVOKABLE void addPerson(const QString & names,const int & age);
    Q_INVOKABLE void removePerson(int index);
    Q_INVOKABLE void removeLastPerson();

signals:

public slots:
private :
    QList<Person*> mPersons;
};

#endif // PERSONMODEL_H
