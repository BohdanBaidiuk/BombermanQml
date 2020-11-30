import QtQuick 2.0
import Bomberman 1.0

Rectangle {
    id: main
    width: grid.width
    height: grid.height
    color: "black"
    property int widthHeight :72

    Grid
    {
        anchors.centerIn: parent
        id: grid
        width: widthHeight * 9
        height: widthHeight * 9
        rows: 9
        columns: 9
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
                    AnimatedImage{
                        anchors.fill: parent
                        width: 50
                        height: 50
                        source:piece
                        focus: true
                        Keys.onLeftPressed: gridModel.model.moveUnit(-1)
                        Keys.onRightPressed: gridModel.model.moveUnit(+1)
                        Keys.onDownPressed: gridModel.model.moveUnit(+9)
                        Keys.onUpPressed: gridModel.model.moveUnit(-9)
                        Keys.onSpacePressed: gridModel.model.setBomb()

                    }
                }
            }
        }
    }
}
