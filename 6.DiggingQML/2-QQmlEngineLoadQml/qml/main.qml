import QtQuick 2.12

Item {
    objectName: "My Root Item";
    Item{
        id : child1
        objectName: "Child1"
        property int age: 13
        property string names: "Steve Barker"
    }
    Rectangle{
        id : chilRect
        objectName: "childRect"
        width: 200
        height: 300
        color: "green"
    }
    Item{
        id : child2
        objectName: "Child2"
        property string car: "Peugot"
    }
    Item{
        id : child3
        objectName: "Child2"
        property string car: "Ford"

    }
    Item{
        id : child4
        objectName: "deepChild"
        property string level : "level1";
        Item{
            objectName: "deepChild"
            property string level: "level2"
            Item{
                objectName: "deepChild"
                property string level: "level3"
            }
        }
    }
    Item{
        id : child5
        objectName: "deepChild"
        property string level : "level1clone";

    }
}
