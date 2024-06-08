import QtQuick
import QtQuick.Controls

Row{
    id: r
    anchors.fill: parent
    spacing: 5
    property var buttons: ["ok", "cancel"]
    property int btnWidth: 74
    property int btnHeigth: 26
    Repeater{
        model: r.buttons
        ZButton{
            width: r.btnWidth
            height: r.btnHeigth
            text: modelData
        }
    }
}

