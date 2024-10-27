cmake_minimum_required(VERSION 3.16)

set(PROJECT_SOURCES

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(module-37_task-1
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        ../calculator.ui
        ../include/calculatormainwindow.h
        main.cpp
        calculatormainwindow.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET module-37_task-1 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(module-37_task-1 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(module-37_task-1
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(module-37_task-1 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

target_include_directories(module-37_task-1 PUBLIC ${MY_INCLUDE_DIR})



# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.module-37_task-1)
endif()
set_target_properties(module-37_task-1 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS module-37_task-1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(module-37_task-1)
endif()






