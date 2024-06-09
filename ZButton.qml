import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Controls.Material.impl
import QtQuick.Controls.impl

RoundButton {
    id: control
    radius: 6
    height: 26
    width : 74
    anchors.horizontalCenter: Text.horizontalCenter
    text: "hello"
    property string iconurl: ""
    property color textColor: "#375278"
    property color normalBkColor: "#ffffff"
    contentItem: IconLabel {
        spacing: control.spacing
        mirrored: control.mirrored
        display: control.display

        icon: control.icon
        text: control.text

        font: control.font
        color: control.checked || control.highlighted ? control.palette.brightText :
               control.flat && !control.down ? (control.visualFocus ? control.palette.highlight : control.palette.windowText) : control.palette.buttonText
    }

    background: Rectangle {
        anchors.fill: parent

        radius: 6
        color: control.highlighted ? control.Material.listHighlightColor : (checked ? "yellow" : control.normalBkColor)
        Ripple {
            width: parent.width
            height: parent.height

            clip: visible
            pressed: control.pressed
            anchor: control
            active: control.down || control.visualFocus || control.hovered
            color: control.Material.rippleColor
        }
    }

    font.pixelSize: 10 // mainBottomBasePane.height > 450 ? 10 : 7
    spacing: 0
}
