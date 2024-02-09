#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QQmlComponent>
#include <QAbstractListModel>

class Person : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString names READ names WRITE setNames NOTIFY namesChanged)
    Q_PROPERTY(QString favoriteColor READ favoriteColor WRITE setFavoriteColor NOTIFY favoriteColorChanged)
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)
    QML_ELEMENT

public:
    explicit Person(QObject *parent = nullptr);
    Person(const QString &names, const QString &favoritecolor,const int &age , QObject * parent = nullptr);

    QString names() const;
    QString favoriteColor() const;
    int age() const;
    void setNames(QString names);
    void setFavoriteColor(QString favoriteColor);
    void setAge(int age);

signals:

    void namesChanged(QString names);

    void favoriteColorChanged(QString favoriteColor);

    void ageChanged(int age);


private:
    QString m_names;

    QString m_favoriteColor;

    int m_age;
};

class PersonList : public QObject
{
  Q_OBJECT
  QML_LIST_PROPERTY_ASSIGN_BEHAVIOR_APPEND
  Q_PROPERTY(QQmlListProperty<Person> persons READ getPersons NOTIFY personsChanged)
  QML_ELEMENT

public:
  explicit PersonList(QObject *parent = nullptr);

  QQmlListProperty<Person> getPersons();
  Q_INVOKABLE void refresh();
signals:
  void personsChanged();
private:
  QList<Person *> mPersonList;
};


class PersonListModel : public QAbstractListModel {
  Q_OBJECT
  QML_ELEMENT

public:
  enum Role {
    PersonNameRole = Qt::UserRole + 1,
    PersonFavoriteColorRole,
    PersonAgeRole
  };
  explicit PersonListModel(QObject *parent = nullptr);
  int rowCount(const QModelIndex &parent) const override;
  QVariant data(const QModelIndex &index, int role)  const override;
  QHash<int, QByteArray> roleNames() const override;

public slots:
  void addPerson(Person* person);
  Person* get(int index);

private:
  QList<Person*> mPersonList;
};

#endif // PERSON_H
