import QtQuick
import QtQml
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Controls.Material.impl

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    ZRectangle{
        id: r1
        x: 10
        y: 10
        width: 50
        height: 100
        radius: [5,5,0,15]
        color: "yellow"
    }

    Rectangle{
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        width: 200
        height: 100
        ZButton{
            anchors.fill: parent
            icon.source: "qrc:/res/demo.svg"
            text: "cc"
            display: AbstractButton.TextUnderIcon;
        }
    }
    Component.onCompleted: function(){
        console.log("hello=%1".arg(ZConfig.color));
    }
}
