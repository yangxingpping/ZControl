import QtQuick
import QtQml
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Controls.Material.impl

Window {
    width: 800
    height: 640
    visible: true
    title: qsTr("Hello World")

    TableView {
        anchors.fill: parent
        columnSpacing: 1
        rowSpacing: 1
        clip: true

        model: cc

        delegate: Rectangle {
            implicitWidth: 100
            implicitHeight: 50
            Text {
                anchors.fill: parent
                text: name
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            TableView.editDelegate: TextField {
                 anchors.fill: parent
                 text: name
                 horizontalAlignment: TextInput.AlignHCenter
                 verticalAlignment: TextInput.AlignVCenter
                 Component.onCompleted: selectAll()

                 TableView.onCommit: {
                     display = text
                     // display = text is short-hand for:
                     // let index = TableView.view.modelIndex(column, row)
                     // TableView.view.model.setData(index, text, Qt.DisplayRole)
                 }
             }
        }
    }

    /*
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
        anchors.centerIn: parent
        width: 400
        height: 100
        ZRowButton{
            anchors.fill: parent
            buttons: abc
        }
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
    */
}
