import QtQuick 2.12
import com.blikoon.Football 1.0

FootballTeam{
    id : team1
    title: "Rayon Sports"
    coatch: "Raul Shungu"
    captain: Player {
        name: "Muti Johnson"
        playing: false
        position: "Middle Field"
    }
    players: [

        Player {
            name: "Player One"
            playing: true
            position: "Position One"
        },
        Player {
            name: "Player Two"
            playing: true
            position: "Position Two"
        },
        Player {
            name: "Player Eleven"
            playing: true
            position: "Player Eleven"
        },
        Player {
            name: "Player Twelve"
            playing: true
            position: "Player Twelve"
        },
        Player {
            name: "Player Thirteen"
            playing: false
            position: "Player Thirteen"
        }
    ]
}



