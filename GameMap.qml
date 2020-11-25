import QtQuick 2.0
import Bomberman 1.0

Rectangle {
    id: main
    width: 600
    height: 600
    color: "black"
    property int widthHeight :72

    Grid
    {
        anchors.centerIn: parent
        id: grid
        width: widthHeight * 7
        height: widthHeight * 7
        rows: 7
        columns: 7
        Repeater
        {
            id: beforeTheItem
            model:BombermanModel{

            }
            Rectangle
            {
                width: widthHeight
                height: widthHeight
                color: "white"
                border.width: 1
                Image {
                    id: name
                    anchors.fill: parent
                    width: widthHeight
                    height: widthHeight
                    //source: image
                    Image{
                        anchors.fill: parent
                        width: 50
                        height: 50

                        //source:unit
                        focus: true
                        Keys.onLeftPressed: beforeTheItem.model.moveAvatar(-7)
                        Keys.onRightPressed: beforeTheItem.model.moveAvatar(+7)
                        Keys.onDownPressed: beforeTheItem.model.moveAvatar(+1)
                        Keys.onUpPressed: beforeTheItem.model.moveAvatar(-1)
                    }
                }
            }
        }
    }
}
