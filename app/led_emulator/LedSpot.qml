import QtQuick 2.15

Item {
    id: root

    property color color

    width: 30
    height: 30

    Rectangle {
      width: root.width
      height: root.width
      radius: width / 2
      color: root.color
    }
}
