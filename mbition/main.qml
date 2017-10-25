import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import com.prototype.cpuinfoparser 1.0

Window {
    id: window
    visible: true
    width: 360
    height: 360

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }

        /*Text {
            id: text1
            text: summary//cpuInfoParser.cpuSummary
            font.pixelSize: 20
        }*/

        ListView {
            id: listview
            width: window.width - 5
            height: window.height - 5
            model: procInfoModel
            delegate: Rectangle {
                height: 25
                width: 100
                Text {
                    text: modelData.processorId
                }
            }
        }
    }

    Column {
        id: column
        x: 0
        y: 0
        width: 360
        height: 360


    }


}
