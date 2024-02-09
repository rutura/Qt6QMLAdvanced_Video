/*
        . Exploring how to paint QML Items from C++.
        . We use the QQuickPaintedItem class for that purpose
        . We :
            . Inherit the class
            . Override the paint method and do our painting in there
                . The chief weapon here is to use the QPainter API

        . We build a logo class we intend to back our logos in QML
        . The class exposes the properties we intend to manipulate on the QML side :
                Q_PROPERTY(QColor bgColor READ bgColor WRITE setBgColor NOTIFY bgColorChanged)
                Q_PROPERTY(QColor textColor READ textColor WRITE setTextColor NOTIFY textColorChanged)
                Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
                Q_PROPERTY(QtTopic topic READ topic WRITE setTopic NOTIFY topicChanged)

         . We register the type to QML :
                qmlRegisterType<LearnQtLogo>("com.blikoon.logos",1,0,"Logo");

         . And use the type in QML :
                Logo{
                    id : mLogo1
                    text: "Learn QT"
                    bgColor: "blue"
                    textColor: "red"
                }

                Logo{
                    id : mLogo2
                    anchors.top : mLogo1.bottom
                    anchors.topMargin: 20
                    text: "Go Fluid"
                    bgColor: "beige"
                    textColor: "black"
                    topic: Logo.QTQUICK
                }


  */

import QtQuick
import com.blikoon.logos

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QQuickPaintedItem")

    Logo{
        id : mLogo1
        text: "Learn QT"
        bgColor: "blue"
        textColor: "red"
    }

    Logo{
        id : mLogo2
        anchors.top : mLogo1.bottom
        anchors.topMargin: 20
        text: "Go Fluid"
        bgColor: "beige"
        textColor: "black"
        // topic: Logo.QTQUICK
    }
}
