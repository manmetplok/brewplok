import QtQuick 2.14
import QtQuick.Controls 2.14
import QtCharts 2.3

Page {
    id: chartPage
    rightPadding: 80
    bottomPadding: 80
    leftPadding: 80
    topPadding: 80


    ChartView {
        title: "Numerical Data for Dummies"
        anchors.fill: parent
        legend.visible: false
        backgroundColor: "#000000"
        antialiasing: true

        ValueAxis {
            id: axisX
            min: 0
            max: 100
            tickCount: 10
        }

        SplineSeries {
            id: series1
            axisX: axisX
            axisY: CategoryAxis {
                min: 0
                max: 100
                CategoryRange {
                    label: "critical"
                    endValue: 2
                }
                CategoryRange {
                    label: "low"
                    endValue: 4
                }
                CategoryRange {
                    label: "normal"
                    endValue: 7
                }
                CategoryRange {
                    label: "high"
                    endValue: 15
                }
                CategoryRange {
                    label: "extremely high"

                    endValue: 30
                }

            }

        }
    }

}

