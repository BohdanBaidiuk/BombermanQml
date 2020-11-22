import QtQuick 2.0
import Game 1.0

Rectangle {
    id: main
    width: 600
    height: width
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
            model:GameBoardModel{
                
            }
            Rectangle
            {
                width: widthHeight
                height: widthHeight
                color: "white"
                border.width: 1
                Image {
                    id: name
                    //anchors.fill: parent
                    width: widthHeight
                    height: widthHeight
                    fillMode: Image.PreserveAspectCrop
                    source: image
                    Image{
                        //                     property int step: parent.width / 20
                        width: 50
                        height: 50
                        //                       x : parent.width / (20 * 2 * 2); y: parent.width / (20 * 2 * 2)
                        source:unit
                        focus: true
                        Keys.onLeftPressed: beforeTheItem.model.moveAvatar(-7)
                        Keys.onRightPressed: beforeTheItem.model.moveAvatar(+7)
                        Keys.onDownPressed: beforeTheItem.model.moveAvatar(+1)
                        Keys.onUpPressed: beforeTheItem.model.moveAvatar(-1)
                        
                        //                        Keys.onLeftPressed: player.moveLeft()
                        //                        Keys.onRightPressed: player.moveRight()
                        //                        Keys.onDownPressed: player.moveDown()
                        //                        Keys.onUpPressed: player.moveUp()
                        //                        function moveLeft()
                        //                        {
                        //                            if(beforeTheItem.model.moveAvatar(-7))
                        //                                x = x - step;
                        //                        }
                        //                        function moveRight()
                        //                        {
                        //                            if(beforeTheItem.model.moveAvatar(+7))
                        //                                x = x + step;
                        //                        }
                        //                        function moveUp()
                        //                        {
                        //                            if(beforeTheItem.model.moveAvatar(-1))
                        //                                y = y - step;
                        //                        }
                        //                        function moveDown()
                        //                        {
                        //                            if(beforeTheItem.model.moveAvatar(+1))
                        //                                y = y + step;
                        //                        }
                    }
                }
                //                Text {
                //                    id: txt
                //                    anchors.centerIn: parent
                //                    text: display
                //                }
                
            }
        }
    }
}
