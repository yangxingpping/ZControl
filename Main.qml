import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Controls.Material.impl

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    ZRectangle{
        x: 0
        y: 0
        width: 50
        height: 100
        radius: [5,5,0,5]
        color: "red"
    }
    Rectangle{
        id: r
        anchors.centerIn: parent
        width: 300;
        height: 100;
        color: "blue";
        ZRowButton{
            btnWidth: 100
            btnHeigth: 64
            buttons: abc
            anchors.fill: parent
        }
    }
    Component.onCompleted: function(){
        console.log(abc);
    }
}
