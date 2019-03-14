import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import Viewer 1.0

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Gravity")

    Squircle {
        id: view
        SequentialAnimation on t {
            NumberAnimation { to: 1; duration: 2500; easing.type: Easing.InQuad }
            NumberAnimation { to: 0; duration: 2500; easing.type: Easing.OutQuad }
            loops: Animation.Infinite
            running: true
        }
    }

    Button {
        id: randomizer
        text: qsTr("Randomize")
        onClicked: model.submit()

        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 20

        contentItem: Text {
            text: control.text
            font: control.font
            opacity: enabled ? 1.0 : 0.3
            color: control.down ? "#17a81a" : "#21be2b"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }

        background: Rectangle {
            implicitWidth: 100
            implicitHeight: 40
            opacity: enabled ? 1 : 0.3
            border.color: control.down ? "#17a81a" : "#21be2b"
            border.width: 1
            radius: 2
        }
    }
}