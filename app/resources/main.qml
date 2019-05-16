import QtQuick 2.11
import QtQuick.Window 2.3
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
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
        onClicked: {
            calculationSettings.open()
        }

        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 20

        contentItem: Text {
            id: randomizerText
            text: randomizer.text
            font: randomizer.font
            color: randomizer.down ? "#17a81a" : "#21be2b"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }

        background: Rectangle {
            id: randomizerBackground
            implicitWidth: 100
            implicitHeight: 40
            color: "Transparent"
            border.color: randomizer.down ? "#17a81a" : "#21be2b"
            border.width: 1
            radius: 5
        }
    }

    Slider {
        id: slider
        value: 200
        from: 100
        to: 1000
        snapMode: Slider.SnapAlways
        stepSize: 100
        onMoved: {
            randomizerText.color = "#e63900"
            randomizerBackground.border.color = "#e63900"
            nbpValue.text = value
            nbpValue.color = "#e63900"
        }

        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.margins: 20

        background: Rectangle {
            x: slider.leftPadding
            y: slider.topPadding + slider.availableHeight / 2 - height / 2
            implicitWidth: window.width - randomizer.width - 60
            implicitHeight: 4
            width: slider.availableWidth
            height: implicitHeight
            radius: 2
            color: "#bdbebf"

            Rectangle {
                width: slider.visualPosition * parent.width
                height: parent.height
                color: "#21be2b"
                radius: 2
            }
        }

        handle: Rectangle {
            x: slider.leftPadding + slider.visualPosition * (slider.availableWidth - width)
            y: slider.topPadding + slider.availableHeight / 2 - height / 2
            implicitWidth: 26
            implicitHeight: 26
            radius: 13
            color: slider.pressed ? "#f0f0f0" : "#f6f6f6"
            border.color: "#bdbebf"
        }
    }

    Label {
        id: nbpText
        font.pointSize: 13
        text: qsTr("Number Of Particles:")
        color: "#21be2b"

        anchors.left: parent.left
        anchors.top: parent.top
        anchors.margins: 10
    }
    Label {
        id: cpsText
        font.pointSize: 13
        text: qsTr("Calculations per Second:")
        color: "#21be2b"

        anchors.left: parent.left
        anchors.top: nbpText.bottom
        anchors.margins: 10
    }

    Label {
        id: nbpValue
        font.pointSize: 13
        text: slider.value
        color: "#21be2b"

        anchors.left: nbpText.right
        anchors.top: parent.top
        anchors.margins: 10
    }
    Label {
        id: cpsValue
        font.pointSize: 13
        text: qsTr("100")
        color: "#21be2b"

        anchors.left: cpsText.right
        anchors.top: nbpValue.bottom
        anchors.margins: 10
    }

    Dialog {
        id: calculationSettings
        title: "Calculation Settings"
        modal: true

        implicitWidth: 300
        implicitHeight: 200

        x: (window.width - width) / 2
        y: (window.height - height) / 2
        parent: ApplicationWindow.overlay

        property double epsilon : 0.01
        property int numberOfTimesteps : 1000

        contentItem:ColumnLayout {
            implicitWidth: calculationSettings.width

            RowLayout {
                Layout.fillWidth: true

                Label {
                    font.pointSize: 13
                    text: qsTr("Timestep Size:")
                }
                TextInput {
                    id: epsilonInput
                    validator: DoubleValidator{bottom: 0.01;}
                    focus: true
                    font.pointSize: 13
                    text: calculationSettings.epsilon
                    cursorVisible: false
                }
                Label {
                    font.pointSize: 13
                    text: "S"
                }
            }
            RowLayout {
                Layout.fillWidth: true

                Label {
                    font.pointSize: 13
                    text: qsTr("Number of Timesteps:")
                }
                TextInput {
                    id: nbTimestepsInput
                    validator: IntValidator{bottom: 2;}
                    font.pointSize: 13
                    text: calculationSettings.numberOfTimesteps
                    cursorVisible: false
                }
            }
        }

        footer: DialogButtonBox {
            standardButtons: DialogButtonBox.Ok | DialogButtonBox.Cancel

            onAccepted: {
                randomizerText.color = "#21be2b"
                randomizerBackground.border.color = "#21be2b"
                nbpValue.color = "#21be2b"
                controller.randomizeClicked(slider.value, calculationSettings.numberOfTimesteps, calculationSettings.epsilon)
            }
        }
    }
}