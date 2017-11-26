import QtQuick 2.6
import QtQuick.Window 2.2


ListView {
    width: 200; height: 300
    model: dadesParser
    delegate: Rectangle {
        height: 25
        width: 100
        Text {
            text: modelData;
            leftPadding: 5;
        }
    }
}





