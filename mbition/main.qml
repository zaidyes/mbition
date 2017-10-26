import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Window {
    id: window
    visible: true
    width: 400
    height: 400


    ColumnLayout {
        id: layout
        anchors.fill: parent
        spacing: 6

        Rectangle {
            id: summaryRect
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumHeight: childrenRect.height + 10
            Layout.minimumWidth: layout.width
            color: "light gray"
            Text{
                id: heading
                text: "<b>CPU Processor Info<\b>"
                font.pixelSize: 16
            }

            Text {
                id: text1
                text: summary
                font.pixelSize: 14
                anchors.top: heading.bottom
            }
        }

        ListView {
            id: listview
            Layout.fillWidth: true
            Layout.fillHeight: true
            width: window.width - 5
            height: window.height - 5
            y: summary.y + summary.height +20
            anchors.margins: 10
            model: procInfoModel
            delegate: Rectangle {
                height: childrenRect.height + 10
                width: childrenRect.width
                color: index % 2 == 0 ? "dark gray" : "gray"
                radius: 1
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.horizontalCenter: parent.horizontalCenter
                Column {
                    Text { text: "<b>Processor Id</b>: " + modelData.processorId }
                    Text { text: "<b>Vendor Id</b>: " + modelData.vendorId }
                    Text { text: "<b>Model Name</b>: " + modelData.modelName }
                    Text { text: "<b>Clock Speed</b>: " + modelData.clockSpeed }
                    Text { text: "<b>Cache Size</b>: " + modelData.cacheSize }
                    Text { text: "<b>Physical Id</b>: " + modelData.physicalId }
                    Text { text: "<b>Core Id</b>: " + modelData.coreId }
                }
            }
        }


    }

}
