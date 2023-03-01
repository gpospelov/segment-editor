import QtQuick 2.2
import QtQuick.Window 2.2
import coa.pspseditor.backend 1.0

Window {
  id: root
  width: 800
  height: 800
  visible: true

  Text {
    id: modelText
    anchors.top: parent.top
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.margins: 5
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    text: segment_model.contentAsString
    font.pixelSize: 16
    height: 28
    fontSizeMode: Text.Fit
    wrapMode: Text.WordWrap
    //    minimumPixelSize: 16
  }

  SegmentGridView {
    id: segmentGridView
    anchors.margins: 5
    anchors.top: modelText.bottom
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.bottom: parent.bottom
    anchors.centerIn: parent.center
  }
}
