#include "pch.h"
#include "gtest/gtest.h"
#include "common/TextFormatter.h"

namespace Logging
{
	TEST(TextFormatterTest, FormatSingle)
	{
		TextFormatter formatter;
		std::string expect = "hello world";
		auto actual = formatter.format(expect);

		EXPECT_EQ(expect + Consts::Space, actual);
	}

	TEST(TextFormatterTest, FormatMultiple)
	{
		TextFormatter formatter;
		std::string expect = "hello";
		std::string expect1 = "world";

		auto actual = formatter.format(expect, expect1);

		EXPECT_EQ(expect + Consts::Space + expect1 + Consts::Space, actual);
	}
}