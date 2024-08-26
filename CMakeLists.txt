cmake_minimum_required(VERSION 3.5)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(fashion_mnist VERSION ${PROJECT_VERSION})

find_package(Boost COMPONENTS program_options filesystem REQUIRED)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost Not found")
endif()

include_directories(${Boost_INCLUDE_DIR})

configure_file(version.h.in version.h)

#Main target 
add_executable(fashion_mnist
	main.cpp
	helpers.cpp
	logreg_classifier.cpp
	options_reader/options_reader.cpp
)

add_library(lib_fashion_mnist
	lib.cpp
)

set_target_properties(
	fashion_mnist
	lib_fashion_mnist
	PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(lib_fashion_mnist 
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(fashion_mnist PRIVATE
    ${Boost_LIBRARIES}
    lib_fashion_mnist
)

if (MSVC)
    target_compile_options(fashion_mnist PRIVATE
        /W4
    )
    target_compile_options(lib_fashion_mnist PRIVATE
        /W4
    )
else ()
    target_compile_options(fashion_mnist PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(lib_fashion_mnist PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS fashion_mnist RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()