cmake_minimum_required(VERSION 3.5)
project(MyDCMTKProject)

# Setup the toolchain file from vcpkg
#set(CMAKE_TOOLCHAIN_FILE C:/Users/ErikZ/.vcpkg-clion/vcpkg/scripts/buildsystems/vcpkg.cmake)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find package
find_package(DCMTK CONFIG REQUIRED)


add_executable(main main.cpp)

    if ("${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}" STREQUAL "/")
        message(WARNING "No vcpkg install dir found, DCMTK definitions are not set")
    else()
        target_compile_definitions(main
            PUBLIC
                "DCMTK_PREFIX=${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}"
                "DCM_DICT_DEFAULT_PATH=${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/share/dcmtk/dicom.dic:${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/share/dcmtk/private.dic"
                "DEFAULT_CONFIGURATION_DIR=${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/etc/dcmtk/"
                "DEFAULT_SUPPORT_DATA_DIR=${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/share/dcmtk/"
        )
    endif()

#target_link_libraries(main PRIVATE ${DCMTK_LIBRARIES}) 
target_link_libraries(main PRIVATE DCMTK::DCMTK DCMTK::oflog)
target_include_directories(main PRIVATE ${DCMTK_INCLUDE_DIRS})

