import QtQuick 2.14
import QtQuick.Controls 2.14
import QtCharts 2.3

Page {
    id: chartPage
    rightPadding: 80
    bottomPadding: 80
    leftPadding: 80
    topPadding: 80
    Connections {
        target: graphData
        onWValueChanged: {
            var sensorName = graphData.wSensor;
            var sensorValue = graphData.wValue

            var serie = chartView.series(sensorName)
            ||chartView.createSeries(ChartView.SeriesTypeLine, sensorName ,axisX, yAxis );
            console.log(sensorName, sensorValue.x, sensorValue.y);

            if(serie.count > 80)
                serie.remove(0);
            serie.append(sensorValue.x, sensorValue.y)
            axisX.min = serie.at(0).x
            axisX.max = serie.at(serie.count-1).x

        }
    }

    ChartView {

        id: chartView
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

        CategoryAxis {
            id: yAxis
            min: 0
            max: 100

            CategoryRange {
                label: "low"
                endValue: 60


            }
            CategoryRange {
                label: "normal"
                endValue: 70
            }
            CategoryRange {
                label: "high"
                endValue: 80
            }
            CategoryRange {
                label: "extremely high"

                endValue: 90
            }

        }

        SplineSeries {
            id: splineSeries1
            axisX: axisX
             axisY: yAxis
        }


    }



}

