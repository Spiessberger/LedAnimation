set(SOURCE_FILES
  animation.cpp
  color.cpp
  cycleanimation.cpp
  oscillationanimation.cpp
  parallelanimation.cpp
  pixelcontroller.cpp
  shiftanimation.cpp
  slicedpixelcontroller.cpp
)

set(HEADER_FILES
  include/pixel_animations/animation.h
  include/pixel_animations/animationinterface.h
  include/pixel_animations/color.h
  include/pixel_animations/cycleanimation.h
  include/pixel_animations/oscillationanimation.h
  include/pixel_animations/parallelanimation.h
  include/pixel_animations/pixelcontroller.h
  include/pixel_animations/shiftanimation.h
  include/pixel_animations/slicedpixelcontroller.h
)

add_library(pixel_animations
  ${SOURCE_FILES}
  ${HEADER_FILES}
)

target_include_directories(pixel_animations
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(GNUInstallDirs)
install(TARGETS pixel_animations
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
