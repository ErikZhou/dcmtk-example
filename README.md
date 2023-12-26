# dcmtk-example

# install dcmtk
vcpkg install dcmtk

# Modify DCMTK Port in Vcpkg for Custom Build Options 
[vcpkg-root]/ports/dcmtk/portfile.cmake
vcpkg_configure_cmake(
    SOURCE_PATH ${SOURCE_PATH}
    PREFER_NINJA
    OPTIONS
        -DDCMTK_USE_CXX11_STL=ON
)
./vcpkg remove dcmtk --recurse
./vcpkg install dcmtk

# build
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=C:/Users/ErikZ/.vcpkg-clion/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build
