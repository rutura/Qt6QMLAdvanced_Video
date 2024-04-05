#include "postmodel.h"

PostModel::PostModel(QObject *parent) : QAbstractListModel(parent)
{

}

int PostModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_datasource->dataItems().count();
}

QVariant PostModel::data(const QModelIndex &index, int role) const
{
    if( index.row() < 0 || index.row() >= m_datasource->dataItems().count()){
        return QVariant();
    }
    Post * post = m_datasource->dataItems().at(index.row());
    if( role == PostDataRole){
        return post->post();
    }
    return QVariant();
}

bool PostModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Post * post = m_datasource->dataItems().at(index.row());
    bool somethingChanged = false;

    switch (role) {
        case  PostDataRole :
        if ( post->post() != value.toString()){
            post->setPost(value.toString());
            somethingChanged = true;
        }
    }

    if ( somethingChanged){
        emit dataChanged(index,index,QVector<int> () << role);
        return true;
    }
    return false;
}

Qt::ItemFlags PostModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> PostModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[PostDataRole] = "post";
    return roles;
}

DataSource *PostModel::datasource() const
{
    return m_datasource;
}

void PostModel::setDatasource(DataSource *datasource)
{
    beginResetModel();

    if( m_datasource && signalsConnected)
        m_datasource->disconnect(this);

    m_datasource = datasource;

    connect(m_datasource,&DataSource::preItemAdded,this,[=](){
        const int index = m_datasource->dataItems().count();
        beginInsertRows(QModelIndex(),index,index);
    });

    connect(m_datasource,&DataSource::postItemAdded,this,[=](){
        endInsertRows();
    });

    connect(m_datasource,&DataSource::preItemRemoved,this,[=](int index){
        beginRemoveRows(QModelIndex(),index,index);
    });

    connect(m_datasource,&DataSource::postItemRemoved,this,[=](){
        endRemoveRows();
    });


    endResetModel();
}
