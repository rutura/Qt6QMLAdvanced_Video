#ifndef FOOTBALLTEAM_H
#define FOOTBALLTEAM_H

#include <QObject>
#include <QVector>
#include <QQmlListProperty>
#include "player.h"

class FootBallTeam : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString coatch READ coatch WRITE setCoatch NOTIFY coatchChanged)
    Q_PROPERTY(Player * captain READ captain WRITE setCaptain NOTIFY captainChanged)
    Q_PROPERTY(QQmlListProperty<Player> players READ players  NOTIFY playersChanged)



public:
    explicit FootBallTeam(QObject *parent = nullptr);

    QString title() const;
    QString coatch() const;
    Player *captain() const;
    void setTitle(QString title);
    void setCoatch(QString coatch);
    void setCaptain(Player * captain);


    QQmlListProperty<Player> players() ;

    //Helper methods
    void appendPlayerCustom(Player*);
    int playerCountCustom() const;
    Player *playerCustom(int) const;
    void clearPlayersCustom();

signals:
    void titleChanged(QString title);
    void coatchChanged(QString coatch);
    void captainChanged(Player * captain);
    void playersChanged();




private:
    //Callback Methods
    static void appendPlayer(QQmlListProperty<Player>*, Player*);
    static qsizetype playerCount(QQmlListProperty<Player>*);
    static Player* player(QQmlListProperty<Player>*, qsizetype);
    static void clearPlayers(QQmlListProperty<Player>*);




    QString m_title;
    QString m_coatch;
    Player * m_captain;
    QVector<Player*> m_players;
};

#endif // FOOTBALLTEAM_H
