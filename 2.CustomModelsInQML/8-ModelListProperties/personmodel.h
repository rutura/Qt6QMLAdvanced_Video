#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QAbstractListModel>
#include <QtQml>
#include <QObject>
#include <QQmlListProperty>
#include "person.h"
#include "datasource.h"

class PersonModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(DataSource *  dataSource READ dataSource WRITE setDataSource NOTIFY dataSourceChanged)
    Q_PROPERTY(QQmlListProperty<Person> persons READ persons  NOTIFY personsChanged)
    Q_CLASSINFO("DefaultProperty", "persons")

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
    void setDataSource(DataSource * dataSource);
    DataSource *dataSource() const;
    QQmlListProperty<Person> persons() ;

    //QML Helper Methods
    Q_INVOKABLE void addPerson(const QString & names, const QString & favoriteColor, const int & age);
    Q_INVOKABLE void removeLastItem();

signals:
    void dataSourceChanged(DataSource * dataSource);
    void personsChanged(QQmlListProperty<Person> persons);
private :

    //Methods
    static void appendPerson(QQmlListProperty<Person>*, Person*);
    static qsizetype personCount(QQmlListProperty<Person>*);
    static Person* person(QQmlListProperty<Person>*, qsizetype);
    static void clearPersons(QQmlListProperty<Person>*);

    DataSource * m_dataSource;
    bool m_signalConnected;
    QQmlListProperty<Person> m_persons;
};

#endif // PERSONMODEL_H
