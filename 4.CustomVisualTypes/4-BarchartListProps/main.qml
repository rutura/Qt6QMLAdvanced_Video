/*

        . Enabling list properties for our StairChart type
        . Use the Qt5 course as a reference and improvise.

  */

import QtQuick
//import com.blikoon.charts
import BarchartListProps

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("bar chart with list properties")

    StairChart{
        title: "Wheat Consumption by 2030 in Mills of Tons"
        bgColor: "lightgray"

        //This syntax is just a syntactic sugar.
        Stair{
            from: 50
            value: 250
            color: "yellowgreen"
            text: "RW"
        }
        Stair{
            from: 100
            value: 300
            color: "cyan"
            text: "JP"
        }
        Stair{
            from: 150
            value: 122
            color: "red"
            text: "VT"
        }

        /*
        stairs: [
            Stair{
                from: 50
                value: 250
                color: "red"
                text: "RW"
            },
            Stair{
                from: 100
                value: 320
                color: "yellow"
                text: "CN"
            },
            Stair{
                from: 150
                value: 133
                color: "lightblue"
                text: "DE"
            },
            Stair{
                from: 200
                value: 202
                color: "steelblue"
                text: "FR"
            },
            Stair{
                from: 250
                value: 250
                color: "skyblue"
                text: "US"
            },
            Stair{
                from: 300
                value: 200
                color: "beige"
                text: "ZA"
            },
            Stair{
                from: 350
                value: 300
                color: "cyan"
                text: "JP"
            },
            Stair{
                from: 400
                value: 122
                color: "red"
                text: "VT"
            }

        ]
        */
    }
}
