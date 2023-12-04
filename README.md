# arraylist

important file to include is /cmake-build-debug/libarraylist.a for compilation

files arraylist.h and arraylist.c for editing

## Link library like

```
...

# Libraries
add_library(arraylist STATIC lib/arraylist/arraylist.c)

...

# Executable
target_link_libraries(projectname PRIVATE arraylist ${CMAKE_CURRENT_SOURCE_DIR}/lib/arraylist/libarraylist.a)
```

## Full Example
```
cmake_minimum_required(VERSION 3.27)
project(dijkstra C)

add_library(arraylist STATIC lib/arraylist/arraylist.c)

set(CMAKE_C_STANDARD 23)

add_executable(dijkstra main.c)
target_link_libraries(dijkstra PRIVATE arraylist ${CMAKE_CURRENT_SOURCE_DIR}/lib/arraylist/libarraylist.a)
```
