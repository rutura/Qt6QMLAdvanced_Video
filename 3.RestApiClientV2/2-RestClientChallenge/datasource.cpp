#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include "datasource.h"

DataSource::DataSource(QObject *parent) : QObject(parent),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{

}

void DataSource::fetchPosts()
{

    //Initialize our API data
    const QUrl API_ENDPOINT("https://jsonplaceholder.typicode.com/posts");

    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);

    mNetReply = mNetManager->get(request);
    connect(mNetReply,&QIODevice::readyRead,this,&DataSource::dataReadyRead);
    connect(mNetReply,&QNetworkReply::finished,this,&DataSource::dataReadFinished);
}

void DataSource::addPost(Post *post)
{
    emit preItemAdded();
    mPosts.append(post);
    emit postItemAdded();
}

void DataSource::addPost()
{
    Post *post = new Post("Test Post Added First",this);
    addPost(post);
}

void DataSource::addPost(const QString &postParam)
{
    Post *post = new Post(postParam,this);
    addPost(post);
}

void DataSource::removePost(int index)
{
    emit preItemRemoved(index);
    mPosts.removeAt(index);
    emit postItemRemoved();
}

void DataSource::removeLastPost()
{
    if ( !mPosts.isEmpty()){
        removePost(mPosts.size()-1);
    }
}

QList<Post *> DataSource::dataItems()
{
    return mPosts;
}

void DataSource::dataReadyRead()
{
    mDataBuffer->append(mNetReply->readAll());
}

void DataSource::dataReadFinished()
{


    //Parse the JSON
        if( mNetReply->error())
             {
                 qDebug() << "Error : " << mNetReply->errorString();
             }else
             {
                //qDebug() << "Data fetch finished : " << QString(*mDataBuffer);

                //Turn the data into a json document
                QJsonDocument doc = QJsonDocument::fromJson(*mDataBuffer);

                //Turn document into json array
                QJsonArray array = doc.array();

                for ( int i = 0; i < array.size(); i++)
                {
                    QJsonObject object = array.at(i).toObject();
                    QVariantMap map = object.toVariantMap();
                    QString title = map["title"].toString();
                    //mPosts.append(title);
                    addPost(title);

                }

                //Clear the buffer
                mDataBuffer->clear();
             }
}
