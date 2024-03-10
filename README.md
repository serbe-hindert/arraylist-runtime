# arraylist

Implementation of arraylist datastructure for datatypes only known at runtime in C. For datatypes known at compile time look at https://github.com/serbe-hindert/arraylist-compiletime

Generate the .a file via the CMakeLists.txt provided or any build-system really.

## Link library like

```
...

# Libraries
add_library(arraylist STATIC lib/arraylist/arraylist-runtime.c)

...

# Executable
target_link_libraries(projectname PRIVATE arraylist ${CMAKE_CURRENT_SOURCE_DIR}/lib/arraylist/libarraylist-runtime.a)
```

## Full Example
```
cmake_minimum_required(VERSION 3.27)
project(dijkstra C)

add_library(arraylist STATIC lib/arraylist/arraylist-runtime.c)

set(CMAKE_C_STANDARD 23)

add_executable(dijkstra main.c)
target_link_libraries(dijkstra PRIVATE arraylist ${CMAKE_CURRENT_SOURCE_DIR}/lib/arraylist/libarraylist-runtime.a)
```
