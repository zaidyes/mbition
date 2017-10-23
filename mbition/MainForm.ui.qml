import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import com.prototype.cpuinfoparser 1.0

Window {
    property alias mouseArea: mouseArea

    visible: true
    width: 500
    height: 500


    signal start()

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    Text {
        id: display
        anchors.centerIn: parent
        text: "Waiting..."
    }

    Button {
            x: 193
            y: 167
            text: qsTr("Uppercase me!")

            onClicked:
                // emit the submitTextField signal
                start()
        }

    CPUInfoParser {

        onFinished: display.text ="Parse finished:" + result

    }
}

