import QtQuick 2.4
import QtQuick.Window 2.2

Window {
    visible: true
    MainForm {
        id: mainform
        anchors.fill: parent
        mouseArea.onClicked: {
            Qt.quit();
        }

    }
}

Text {
        id: helloText
        text: "Hello world!"
        y: 30
        anchors.horizontalCenter: page.horizontalCenter
        font.pointSize: 24; font.bold: true
}
