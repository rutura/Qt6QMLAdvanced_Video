#ifndef JOKEMODEL_H
#define JOKEMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "datasource.h"

class PostModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(DataSource * datasource READ datasource WRITE setDatasource)

    enum ModelRoles{
        PostDataRole = Qt::UserRole + 1
    };
public:
    explicit PostModel(QObject *parent = nullptr);


    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role);

    Qt::ItemFlags flags(const QModelIndex& index) const;

    QHash<int, QByteArray> roleNames() const; //Allows to expose our custom roles( names,favoritecolor,age) to a qml ListView

    DataSource *datasource() const;
    void setDatasource(DataSource * datasource);

signals:

private :
    DataSource * m_datasource;
    bool signalsConnected {false};
};

#endif // JOKEMODEL_H
