#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QObject>
#include "person.h"

class DataSource : public QObject
{
    Q_OBJECT
public:
    explicit DataSource(QObject *parent = nullptr);

    QList<Person *> dataItems();

    void addPerson( Person *person);
    Q_INVOKABLE void addPerson();
    Q_INVOKABLE void addPerson(const QString & names,const int & age);
    Q_INVOKABLE void removePerson(int index);
    Q_INVOKABLE void removeLastPerson();

signals:
    void prePersonAdded();
    void postPersonAdded();
    void prePersonRemoved(int index);
    void postPersonRemoved();

public slots:
private :
    QList<Person*> mPersons;

};

#endif // DATASOURCE_H
