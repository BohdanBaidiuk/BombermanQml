import QtQuick 2.0
import Game 1.0

Rectangle {
    id: main
    width: 600
    height: width
    color: "green"

    Grid
    {
        anchors.fill: parent
        id: grid
        width: parent.width; height: width
        rows: 7
        columns: 7

        Repeater
        {
            id: beforeTheItem
            model:GameBoardModel{

            }

            //parent.rows * parent.columns
            Rectangle
            {
                width: parent.width / parent.columns;
                height: parent.height / parent.rows;
                color: "white"
                border.width: 1
                Text {
                    anchors.centerIn: parent
                    text: display
                }
            }
        }
    }
    focus: true;

    Keys.onLeftPressed: player.moveLeft()
    Keys.onRightPressed: player.moveRight()
    Keys.onDownPressed: player.moveDown()
    Keys.onUpPressed: player.moveUp()

    Rectangle
    {
        property int step: parent.width / 10
        id: player
        x: parent.width / (10 * 2 * 2); y: parent.width / (10 * 2 * 2)
        width: parent.width / (10 * 2);height: width
        color: "black"

        function moveLeft()
        {
            if( x > step )
                x = x - step;
        }
        function moveRight()
        {
            if( x < (parent.width - step) )
                x = x + step;
        }
        function moveUp()
        {
            if( y > step )
                y = y - step;
        }
        function moveDown()
        {
            if( y < (parent.height - step) )
                y = y + step;
        }
    }
}
