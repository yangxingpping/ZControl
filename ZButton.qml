import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Controls.Material.impl

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
    contentItem: Rectangle {
        color: "transparent"
        Text{
            anchors.centerIn: parent
            text: control.text
            font: control.font
            opacity: enabled ? 1.0 : 0.3
            color: textColor
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }
    }

    background: Rectangle {
        anchors.fill: parent
        Image{
            anchors.fill: parent
            visible: control.iconurl.length > 0;
            source: control.iconurl;
            sourceSize.width: 500
            sourceSize.height: 500
        }

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
