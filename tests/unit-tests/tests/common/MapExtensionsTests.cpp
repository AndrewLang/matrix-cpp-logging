#include "gtest/gtest.h"
#include "common/MapExtensions.h"
#include "Rectangle.h"

namespace Logging
{
	using namespace std;

	TEST(MapExtensionsTests, Get)
	{
		map<int, string> map = {
			{1, "slot1"},
			{2, "slot2"}
		};

		auto actual = Maps::get<int, string>(map, 1);
		ASSERT_EQ(actual, "slot1");
	}

	TEST(MapExtensionsTests, Contains)
	{
		map<int, string> map = {
			{1, "slot1"},
			{2, "slot2"}
		};

		auto actual = Maps::contains<int, string>(map, 1);
		EXPECT_TRUE(actual);

		actual = Maps::contains<int, string>(map, 2);
		EXPECT_TRUE(actual);

		actual = Maps::contains<int, string>(map, 3);
		EXPECT_FALSE(actual);
	}
}