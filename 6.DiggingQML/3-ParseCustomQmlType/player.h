#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class Player : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(bool playing READ playing WRITE setPlaying NOTIFY playingChanged)
    Q_PROPERTY(QString position READ position WRITE setPosition NOTIFY positionChanged)
public:
    explicit Player(QObject *parent = nullptr);

    QString name() const;
    bool playing() const;
    QString position() const;
    void setName(QString name);
    void setPlaying(bool playing);
    void setPosition(QString position);

signals:
    void nameChanged(QString name);
    void playingChanged(bool playing);
    void positionChanged(QString position);


private :
    QString m_name;
    bool m_playing;
    QString m_position;
};

#endif // PLAYER_H
