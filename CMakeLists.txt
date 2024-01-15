# See the build system documentation in IDF programming guide
# for more information about component CMakeLists.txt files.

idf_component_register(
    SRCS    "tm1637.cpp"     # list the source files of this component
    INCLUDE_DIRS "./include"        # optional, add here public include directories
    REQUIRES "driver"        # optional, list the public requirements (component names)
)
