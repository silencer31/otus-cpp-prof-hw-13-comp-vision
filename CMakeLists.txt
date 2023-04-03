cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(comp_vision VERSION ${PROJECT_VERSION})

configure_file(version.h.in version.h)

#Main target 
add_executable(comp_vision main.cpp)
add_library(lib_comp_vision lib.cpp)

set_target_properties(comp_vision lib_comp_vision PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(lib_comp_vision 
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(comp_vision PRIVATE
    lib_comp_vision
)

if (MSVC)
    target_compile_options(comp_vision PRIVATE
        /W4
    )
    target_compile_options(lib_comp_vision PRIVATE
        /W4
    )
else ()
    target_compile_options(comp_vision PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(lib_comp_vision PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS comp_vision RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()