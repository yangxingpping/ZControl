import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Controls.Material.impl

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Rectangle{
        id: r
        anchors.centerIn: parent
        width: 596;
        height: 394;
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
