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
    }

    ListView {
        id: listview
        x: 5
        y: 5
        width: window.width - 5
        height: window.height - 5
        model: parsedModel
            delegate: Rectangle {
                height: 25
                width: 100
                Text { text: modelData }
            }
    }
}
