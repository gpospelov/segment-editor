import QtQuick 2.2
import QtQuick.Window 2.2

ListView {
  model: segment_model
  width: 500
  spacing: 10
  anchors.verticalCenter: parent.verticalCenter
  anchors.horizontalCenter: parent.horizontalCenter
  orientation: ListView.Horizontal

  delegate: Rectangle {
    id: delegateItem
    required property string name
    required property int index

    width: 160
    height: 50
    border.width: 1
    color: index % 2 ? "steelblue" : "lightsteelblue"

    Text {
      text: name
      anchors.centerIn: parent
    }
  }
}
