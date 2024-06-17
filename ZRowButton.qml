import QtQuick
import QtQuick.Controls

Row{
    id: r
    anchors.fill: parent
    spacing: 1
    property var buttons: null
    Repeater{
        model: r.buttons
        ZButton{
            display: AbstractButton.TextUnderIcon
            palette.buttonText: "red"
            radius: r.btnRadius
            width: r.width / r.buttons.rowCount()
            height: r.height
            text: optVal2
            pmaskUrl: maskUrl
            icon.source: iconUrl
            icon.color: "transparent"
            Component.onCompleted: function(){
                console.log("model data=%1 %2".arg(iconUrl).arg(optVal2))
            }
        }
    }
}

