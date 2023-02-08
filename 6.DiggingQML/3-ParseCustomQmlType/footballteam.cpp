#include <QDebug>
#include "footballteam.h"

FootBallTeam::FootBallTeam(QObject *parent) : QObject(parent)
{

}

QString FootBallTeam::title() const
{
    return m_title;
}

QString FootBallTeam::coatch() const
{
    return m_coatch;
}

Player *FootBallTeam::captain() const
{
    return m_captain;
}

void FootBallTeam::setTitle(QString title)
{
    if (m_title == title)
        return;

    m_title = title;
    emit titleChanged(m_title);
}

void FootBallTeam::setCoatch(QString coatch)
{
    if (m_coatch == coatch)
        return;

    m_coatch = coatch;
    emit coatchChanged(m_coatch);
}

void FootBallTeam::setCaptain(Player *captain)
{
    if (m_captain == captain)
        return;

    m_captain = captain;
    emit captainChanged(m_captain);
}

QQmlListProperty<Player> FootBallTeam::players()
{
    return QQmlListProperty<Player>(this,this,&FootBallTeam::appendPlayer,
                                    &FootBallTeam::playerCount,
                                    &FootBallTeam::player,
                                    &FootBallTeam::clearPlayers);
}

void FootBallTeam::appendPlayerCustom(Player * player)
{
    qDebug() << "Adding player to vector"<< player->name();
    m_players.append(player);
}

int FootBallTeam::playerCountCustom() const
{
    return m_players.count();
}

Player *FootBallTeam::playerCustom(int index) const
{
    return m_players.at(index);
}

void FootBallTeam::clearPlayersCustom()
{
    m_players.clear();
}

void FootBallTeam::appendPlayer(QQmlListProperty<Player> * list, Player * player)
{
    reinterpret_cast<FootBallTeam*>(list->data)->appendPlayerCustom(player);
}

qsizetype FootBallTeam::playerCount(QQmlListProperty<Player> * list)
{
    return reinterpret_cast<FootBallTeam*>(list->data)->playerCountCustom();
}

Player *FootBallTeam::player(QQmlListProperty<Player> * list, qsizetype index)
{
    return reinterpret_cast<FootBallTeam*>(list->data)->playerCustom(index);
}

void FootBallTeam::clearPlayers(QQmlListProperty<Player> * list)
{
    reinterpret_cast<FootBallTeam*>(list->data)->clearPlayersCustom();
}
