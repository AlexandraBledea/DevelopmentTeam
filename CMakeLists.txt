cmake_minimum_required(VERSION 3.19)
project(Develpoment_Team)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw73_64\\lib\\cmake\\")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Charts)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Charts Qt5::Gui Qt5::Widgets)

include_directories(Issue)
include_directories(Member)
include_directories(Repository)
include_directories(Service)
include_directories(Observer)
include_directories(TableModel)
include_directories(MemberWindow)

add_executable(Develpoment_Team main.cpp
        Member/Member.cpp
        Member/Member.h
        Issue/Issue.cpp
        Issue/Issue.h
        Repository/Repository.cpp
        Repository/Repository.h Service/Service.cpp Service/Service.h Observer/Observer.h MemberWindow/MemberWindow.cpp MemberWindow/MemberWindow.h TableModel/TableModel.cpp TableModel/TableModel.h)
if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})