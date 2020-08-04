#include "gtest/gtest.h"
#include "common/ArgumentNullException.h"

namespace Logging
{
	TEST(ArgumentNullExceptionTests, Constructor) {
		ArgumentNullException exception("test");

		ASSERT_EQ("test", exception.getArgument());
	}

}