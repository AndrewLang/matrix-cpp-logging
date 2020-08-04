
#include "gtest/gtest.h"

namespace Logging {
	using namespace std;

	TEST(DummyTests, WriteMessage) {
		std::cout << "Dummy message" << std::endl;
	}

}