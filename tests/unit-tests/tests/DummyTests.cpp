
#include "gtest/gtest.h"

namespace Logging {

    using namespace std;

    Test(DummyTests, WriteMessage) {
        std::cout << "Dummy message" << std::endl;
    }
}