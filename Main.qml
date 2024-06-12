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
        x: 10
        y: 10
        width: 50
        height: 100
        radius: [5,5,0,15]
        color: "red"
    }
    Rectangle{
        id: r
        anchors.centerIn: parent
        width: 600;
        height: 100;
        color: "blue";
        ZRowButton{
            buttons: abc
            anchors.fill: parent
        }
    }
    Component.onCompleted: function(){
        console.log("hello=%1".arg(ZConfig.color));
    }
}
