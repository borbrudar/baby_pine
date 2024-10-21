cmake_minimum_required(VERSION 3.16.0)
if(WIN32)
    #default install path, so no spaces
    set(CMAKE_INSTALL_PREFIX C:/ CACHE PATH "default path" FORCE)
endif()
set(PR_NAME baby_pine)
project(${PR_NAME} VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 17)


#---------ADD SOURCE AND HEADER FILES ---------------
set(SOURCE_FILE_NAMES
   main
   Token
)

list(TRANSFORM SOURCE_FILE_NAMES APPEND ".cpp")
list(TRANSFORM SOURCE_FILE_NAMES PREPEND "src/")

add_executable(${PROJECT_NAME} ${SOURCE_FILE_NAMES})
