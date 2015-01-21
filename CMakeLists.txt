project(spreadsheet)
find_package(KDE4 REQUIRED)
include(KDE4Defaults)
include_directories(${KDE4_INCLUDES})


set(QT_USE_QTTEST TRUE)

kde4_add_executable(spreadsheet 
					main.cpp
					spreadsheetmainwindow.cpp
					spreadsheetmodel.cpp
					)

kde4_add_executable(testspreadsheetwindow
					testspreadsheet.cpp
					spreadsheetmodel.cpp
					spreadsheetmainwindow.cpp
					)

kde4_add_executable(testspreadsheetmodel
					testspreadsheetmodel.cpp
					spreadsheetmodel.cpp
					)

target_link_libraries(spreadsheet ${KDE4_KDECORE_LIBS} ${KDE4_KDEUI_LIBS})
target_link_libraries(testspreadsheetwindow ${KDE4_KDECORE_LIBS} ${KDE4_KDEUI_LIBS} ${QT_QTTEST_LIBRARY})
target_link_libraries(testspreadsheetmodel ${KDE4_KDECORE_LIBS} ${QT_QTTEST_LIBRARY})

