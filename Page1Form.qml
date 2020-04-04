import QtQuick 2.14
import QtQuick.Controls 2.14

Page {
    id: page
    rightPadding: 80
    bottomPadding: 80
    leftPadding: 80
    topPadding: 80

    Row {
        id: row
        spacing: 80
        Repeater {
                model: sensorModel
                TempPanel {
                    id: column
                    spacing: 10
                    name: model.address
                    current: model.current.toFixed(1)
                }

        }

    }
}

/*##^##
Designer {
    D{i:1;anchors_height:400;anchors_width:200}
}
##^##*/
