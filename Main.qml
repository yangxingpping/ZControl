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
        ZColumnButton{
            btnWidth: 100
            btnHeigth: 64
            buttons: ["first", "second", "third"]
            anchors.fill: parent

        }
    }
}
