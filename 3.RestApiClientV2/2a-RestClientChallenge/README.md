# 2a-RestClientChallenge

This demonstrates how to use a REST API client to provide data for a list model. 

## REST Api client
Our client
```
https://jsonplaceholder.typicode.com/posts
```

Testing the client

```bash
❯ curl "https://jsonplaceholder.typicode.com/posts"
```
Sample output
```json
[
  {
    "userId": 1,
    "id": 1,
    "title": "sunt aut facere repellat provident occaecati excepturi optio reprehenderit",
    "body": "quia et suscipit\nsuscipit recusandae consequuntur expedita et cum\nreprehenderit molestiae ut ut quas totam\nnostrum rerum est autem sunt rem eveniet architecto"
  },
  {
    "userId": 1,
    "id": 2,
    "title": "qui est esse",
    "body": "est rerum tempore vitae\nsequi sint nihil reprehenderit dolor beatae ea dolores neque\nfugiat blanditiis voluptate porro vel nihil molestiae ut reiciendis\nqui aperiam non debitis possimus qui neque nisi nulla"
  },
  ...
]
```

## Model 

A model with response properties

```cpp
class Post : public QObject
{
  Q_OBJECT
  Q_PROPERTY(int userId READ userId WRITE setUserId NOTIFY userIdChanged)
  Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
  Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged )
  Q_PROPERTY(QString body READ body WRITE setBody NOTIFY bodyChanged )
  QML_ELEMENT
  ...
```

## API Handler

An API handler to handle requests, get and store response in a json array

```cpp
class PostAPI : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QJsonArray jsonArray READ jsonArray CONSTANT)
  QML_ELEMENT
  ...
```

Also expose a method to invoke requests. It can be a ```Q_INVOKABLE```  or a ```public slots:```

## ListModel 

A C++ list model that is as a QML element. 

```cpp
class PostModel : public QAbstractListModel
{
  Q_OBJECT
  Q_PROPERTY(PostAPI* postAPI READ postAPI WRITE setPostAPI NOTIFY postAPIChanged)
  QML_ELEMENT

public:
  enum Role {
    UserIdRole = Qt::UserRole + 1,
    IdRole,
    TitleRole,
    BodyRole
  };
  ...
```

Should include a qml-accessible method to get the ```QJsonArray``` from the API handler and build a list of ```QObject```s. 

## QML 

Create objects in qml and call them