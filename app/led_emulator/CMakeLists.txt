find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.0)

qt_add_executable(appLedEmulator
  main.cpp
  pixelstate.h
  pixelstate.cpp
) 

qt_add_qml_module(appLedEmulator
  URI LedEmulator
  VERSION 1.0
  QML_FILES
    Main.qml
    LedSpot.qml
  SOURCES
    qmlanimationengine.h
    qmlanimationengine.cpp
)

target_link_libraries(appLedEmulator
  PRIVATE
    Qt6::Quick
    pixel_animations
)

include(GNUInstallDirs)
install(TARGETS appLedEmulator
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
