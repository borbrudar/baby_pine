cmake_minimum_required(VERSION 3.16.0)
if(WIN32)
    #default install path, so no spaces
    set(CMAKE_INSTALL_PREFIX C:/ CACHE PATH "default path" FORCE)
endif()
set(PROJECT_NAME baby_pine)
project(${PROJECT_NAME} VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 20)


#---------ADD SOURCE AND HEADER FILES ---------------
set(SOURCE_FILE_NAMES
   main
   Token
   Scanner
   ErrorLogger
)

list(TRANSFORM SOURCE_FILE_NAMES APPEND ".cpp")
list(TRANSFORM SOURCE_FILE_NAMES PREPEND "src/")


add_executable(${PROJECT_NAME} ${SOURCE_FILE_NAMES})
target_include_directories(${PROJECT_NAME} PUBLIC include)
