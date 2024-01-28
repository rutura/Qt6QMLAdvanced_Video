#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class Person : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString names READ names WRITE setNames NOTIFY namesChanged)
    Q_PROPERTY(QString favoriteColor READ favoriteColor WRITE setFavoriteColor NOTIFY favoriteColorChanged)
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)


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

#endif // PERSON_H
