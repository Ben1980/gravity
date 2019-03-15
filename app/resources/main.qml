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
            text: randomizer.text
            font: randomizer.font
            color: randomizer.down ? "#17a81a" : "#21be2b"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }

        background: Rectangle {
            implicitWidth: 100
            implicitHeight: 40
            color: "Transparent"
            border.color: randomizer.down ? "#17a81a" : "#21be2b"
            border.width: 1
            radius: 5
        }
    }

    Slider {
        id: control
        value: 200
        from: 100
        to: 1000
        snapMode: Slider.SnapAlways
        stepSize: 100
        onMoved: model.submit()

        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.margins: 20

        background: Rectangle {
            x: control.leftPadding
            y: control.topPadding + control.availableHeight / 2 - height / 2
            implicitWidth: window.width - randomizer.width - 60
            implicitHeight: 4
            width: control.availableWidth
            height: implicitHeight
            radius: 2
            color: "#bdbebf"

            Rectangle {
                width: control.visualPosition * parent.width
                height: parent.height
                color: "#21be2b"
                radius: 2
            }
        }

        handle: Rectangle {
            x: control.leftPadding + control.visualPosition * (control.availableWidth - width)
            y: control.topPadding + control.availableHeight / 2 - height / 2
            implicitWidth: 26
            implicitHeight: 26
            radius: 13
            color: control.pressed ? "#f0f0f0" : "#f6f6f6"
            border.color: "#bdbebf"
        }
    }

    Label {
        id: nbpText
        font.pixelSize: 15
        text: qsTr("Number Of Particles:")
        color: "#21be2b"

        anchors.left: parent.left
        anchors.top: parent.top
        anchors.margins: 10
    }
    Label {
        id: cpsText
        font.pixelSize: 15
        text: qsTr("Calculations per Second:")
        color: "#21be2b"

        anchors.left: parent.left
        anchors.top: nbpText.bottom
        anchors.margins: 10
    }

    property alias nbp: nbpValue.text
    property alias cps: cpsValue.text

    Label {
        id: nbpValue
        font.pixelSize: 15
        text: qsTr("1000")
        color: "#21be2b"

        anchors.left: nbpText.right
        anchors.top: parent.top
        anchors.margins: 10
    }
    Label {
        id: cpsValue
        font.pixelSize: 15
        text: qsTr("100")
        color: "#21be2b"

        anchors.left: cpsText.right
        anchors.top: nbpValue.bottom
        anchors.margins: 10
    }
}