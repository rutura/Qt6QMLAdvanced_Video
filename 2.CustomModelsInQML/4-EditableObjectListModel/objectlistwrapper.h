#ifndef OBJECTLISTWRAPPER_H
#define OBJECTLISTWRAPPER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QQmlContext>
#include "person.h"

class ObjectListWrapper : public QObject
{
    Q_OBJECT
public:
    explicit ObjectListWrapper(QObject *parent = nullptr);
    bool initialize(QGuiApplication * app);

    Q_INVOKABLE void setNames(int index, const QString & names);
    Q_INVOKABLE void setAge(int index, const int & age);
    Q_INVOKABLE void setFavoriteColor(int index,const QString & favoriteColor);
    Q_INVOKABLE QList<QObject *> persons() const;
    Q_INVOKABLE void addPerson();

signals:

public slots:

private:
    void populateModelWithData();
    void resetModel();
    void printPersons();

    QList<QObject*> mPersons;//This should be QObject*, Person* is not going to work in QML
    QQmlApplicationEngine mEngine;
};

#endif // OBJECTLISTWRAPPER_H
