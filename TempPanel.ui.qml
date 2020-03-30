import QtQuick 2.14
import QtQuick.Controls 2.14

Column {
    id: root
    property string name: "Sensor"
    Text {
        id: element235
        color: "#ffffff"
        text: root.name
        property string property0: "none.none"
        textFormat: Text.PlainText
        font.bold: false
        font.pixelSize: 40
    }
    
    Text {
        id: element
        color: "#ffffff"
        text: qsTr("Target Temperature")
        anchors.left: parent.left
        anchors.leftMargin: 0
        lineHeight: 1.2
        font.pixelSize: 20
    }
    
    Text {
        id: temp1
        color: "#61df0e"
        text: qsTr("61°C")
        anchors.left: parent.left
        anchors.leftMargin: 0
        lineHeight: 1.2
        horizontalAlignment: Text.AlignLeft
        font.underline: false
        font.pixelSize: 60
    }
    
    Text {
        id: element6
        color: "#ffffff"
        text: qsTr("Target Temperature")
        anchors.left: parent.left
        lineHeight: 1.2
        font.pixelSize: 20
        anchors.leftMargin: 0
    }
    
    Text {
        id: temp4
        color: "#61df0e"
        text: qsTr("61°C")
        font.underline: false
        anchors.left: parent.left
        horizontalAlignment: Text.AlignLeft
        lineHeight: 1.2
        font.pixelSize: 60
        anchors.leftMargin: 0
    }
    
    
    
}
