import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import LedEmulator

Window {
  width: 640
  height: 500
  visible: true
  title: "Led Emulator"

  AnimationEngine {
    id: animationEngine

    pixelCount: 21
  }

  Repeater {
    model: animationEngine.pixelColors

    LedSpot {
      id: spot

      required property int index
      required property color modelData

      color: modelData

      x: d.positions[index].x
      y: d.positions[index].y
    }
  }

  Column {
    anchors.right: parent.right
    anchors.top: parent.top
    anchors.margins: 24

    ComboBox {
      anchors.right: parent.right

      textRole: "text"
      valueRole: "value"

      model: [
        { text: "Cycle", value: AnimationEngine.CycleAnimation },
        { text: "Shift", value: AnimationEngine.ShiftAnimation },
        { text: "Oscillation", value: AnimationEngine.OscillationAnimation }
      ]

      onActivated: animationEngine.animationType = currentValue

      Component.onCompleted: currentIndex = indexOfValue(animationEngine.animationType)
    }
  }

  QtObject {
    id: d

    property var positions: [
      {"x":359,"y":307},
      {"x":394,"y":253},
      {"x":402,"y":196},
      {"x":401,"y":138},
      {"x":396,"y":80},
      {"x":361,"y":30},
      {"x":299,"y":31},
      {"x":264,"y":77},
      {"x":247,"y":134},
      {"x":247,"y":198},
      {"x":254,"y":254},
      {"x":287,"y":310},
      {"x":24,"y":287},
      {"x":75,"y":312},
      {"x":136,"y":294},
      {"x":142,"y":217},
      {"x":84,"y":170},
      {"x":143,"y":126},
      {"x":138,"y":58},
      {"x":75,"y":41},
      {"x":28,"y":82}]
  }
}
