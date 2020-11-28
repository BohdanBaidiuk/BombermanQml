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
            id: gridModel
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
                    source: imageMap
                    Image{
                        anchors.fill: parent
                        width: 50
                        height: 50

                        source:piece
                        focus: true
                        Keys.onLeftPressed: gridModel.model.moveUnit(-1)
                        Keys.onRightPressed: gridModel.model.moveUnit(+1)
                        Keys.onDownPressed: gridModel.model.moveUnit(+7)
                        Keys.onUpPressed: gridModel.model.moveUnit(-7)
                       // Keys.onEnterPressed: gridModel.model.
                    }
                }
            }
        }
    }
}
