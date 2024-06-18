import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material
import QtQuick.Controls.Material.impl
import QtQuick.Controls.impl

RoundButton {
    id: control
    radius: 2
    text: "hellox"
    property string pmaskUrl: ""
    property var textImageRatio: [1,2.5]
    bottomPadding: 2
    topPadding: 2
    leftPadding: 2
    rightPadding: 2
    spacing: 0

    contentItem: Rectangle{
        id: contentR
        color: "transparent"
        Image{
            x: 0
            y: 0
            width: control.display === AbstractButton.TextBesideIcon ? contentR.width * control.textImageRatio[1] / (control.textImageRatio[1] + control.textImageRatio[0]) : contentR.width;
            height: control.display === AbstractButton.TextUnderIcon ? contentR.height * control.textImageRatio[1] / (control.textImageRatio[1] + control.textImageRatio[0]) : contentR.height;
            source: control.icon.source
            sourceSize.width: 512
            sourceSize.height: 256
            visible: control.display != AbstractButton.TextOnly
        }
        Item{
            x: control.display === AbstractButton.TextBesideIcon ? contentR.width * control.textImageRatio[1] / (control.textImageRatio[1] + control.textImageRatio[0]) : 0;
            width: contentR.width - x;
            y: control.display === AbstractButton.TextUnderIcon ? contentR.height * control.textImageRatio[1] / (control.textImageRatio[1] + control.textImageRatio[0]) : 0
            height: contentR.height - y;
            visible: control.display !== AbstractButton.IconOnly;
            Text{
                anchors.fill: parent
                text: control.text
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                fontSizeMode: Text.Fit;
                minimumPixelSize: 10;
                font.pixelSize: 72
            }
        }
    }
    background: Rectangle {
        anchors.fill: parent

        radius: 2
        color: control.highlighted ? control.Material.listHighlightColor : (checked ? "yellow" : ZConfig.color)
        Ripple {
            width: parent.width
            height: parent.height

            clip: visible
            pressed: control.pressed
            anchor: control
            active: control.down || control.visualFocus || control.hovered
            color: control.Material.rippleColor
        }
        Image{
            anchors.fill: parent
            source: control.pmaskUrl;
        }
    }
    Component.onCompleted: function(){
        //propety check
        if(display===AbstractButton.TextOnly || display===AbstractButton.IconOnly){
            if(textImageRatio.length===0 && display===AbstractButton.TextOnly){
                console.warn("warn")
                textImageRatio=[1,0.0001];
            }
            if(textImageRatio.length>1 && display===AbstractButton.IconOnly){
                console.warn("warn");
                textImageRatio=[0.0001,1];
            }
        }
        else{
            if(textImageRatio.length!==2){
                console.warn("warn");
                textImageRatio=[1,1];
            }
        }
    }
}
