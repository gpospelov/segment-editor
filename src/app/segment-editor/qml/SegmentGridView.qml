import QtQuick 2.15
import QtQml.Models 2.15

// See origin, Remy van Elst
// https://raymii.org/s/tutorials/Qml_Drag_and_Drop_example_including_reordering_the_Cpp_Model.html

GridView {
  id: root
  width: 600
  height: 600
  cellWidth: 250
  cellHeight: 250

  displaced: Transition {
    NumberAnimation {
      properties: "x, y"
      easing.type: Easing.OutQuad
    }
  }

  model: DelegateModel {
    id: visualModel
    model: segment_model

    // each square play the role of drag-able item, and the role of drop area
    delegate: DropArea {
      id: delegateRoot
      required property color color
      required property string name

      property int modelIndex

      width: root.cellWidth
      height: root.cellHeight

      onEntered: function (drag) {
        var from = (drag.source as SegmentTile).visualIndex
        var to = segmentTile.visualIndex
        visualModel.items.move(from, to)
      }

      onDropped: function (drag) {
        var from = modelIndex
        var to = (drag.source as SegmentTile).visualIndex
        segment_model.move(from, to)
      }

      property int visualIndex: DelegateModel.itemsIndex

      SegmentTile {
        id: segmentTile
        width: root.cellWidth * 0.8
        height: root.cellHeight * 0.8
        dragParent: root
        visualIndex: delegateRoot.visualIndex
        color: delegateRoot.color

        // Note: assignment, not property binding. The goal is to save modelIndex property at
        // the moment of press event, and use it later as a "from" while moving.
        onPressed: delegateRoot.modelIndex = visualIndex

        // content of the draggable square
        Text {
          anchors.fill: parent
          anchors.centerIn: parent
          horizontalAlignment: Text.AlignHCenter
          verticalAlignment: Text.AlignVCenter
          color: "white"
          anchors.margins: 5
          fontSizeMode: Text.Fit
          minimumPixelSize: 10
          font.pixelSize: 30
          text: delegateRoot.name
        }
      }
    }
  }
}
