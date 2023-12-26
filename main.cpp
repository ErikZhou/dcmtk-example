#include <dcmtk/config/osconfig.h>   // make sure OS specific configuration is included first
#include <dcmtk/dcmdata/dctk.h>

int main() {
    OFString version = OFFIS_DCMTK_VERSION_STRING;
    std::cout << "Using DCMTK version " << version << std::endl;
    return 0;
}

