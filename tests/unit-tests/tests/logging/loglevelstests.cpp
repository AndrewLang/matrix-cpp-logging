#include "pch.h"
#include "gtest/gtest.h"
#include "logging/LogLevels.h"

namespace Logging
{
	TEST(LogLevelsTests, Constructor) {
		EXPECT_EQ("All", LogLevels::Default()->all()->getName());
		EXPECT_EQ("Debug", LogLevels::Default()->debug()->getName());
		EXPECT_EQ("Info", LogLevels::Default()->info()->getName());
		EXPECT_EQ("Warn", LogLevels::Default()->warn()->getName());
		EXPECT_EQ("Error", LogLevels::Default()->error()->getName());
		EXPECT_EQ("Fatal", LogLevels::Default()->fatal()->getName());
		EXPECT_EQ("None", LogLevels::Default()->none()->getName());

		EXPECT_EQ(0, LogLevels::Default()->all()->getValue());
		EXPECT_EQ(1000, LogLevels::Default()->debug()->getValue());
		EXPECT_EQ(2000, LogLevels::Default()->info()->getValue());
		EXPECT_EQ(3000, LogLevels::Default()->warn()->getValue());
		EXPECT_EQ(4000, LogLevels::Default()->error()->getValue());
		EXPECT_EQ(5000, LogLevels::Default()->fatal()->getValue());
		EXPECT_EQ(99999, LogLevels::Default()->none()->getValue());
	}

	TEST(LogLevelsTests, SingleInstance) {
		auto levels1 = LogLevels::Default();
		auto levels2 = LogLevels::Default();

		EXPECT_EQ("Debug", levels1->debug()->getName());
		EXPECT_EQ("Debug", levels2->debug()->getName());
	}

}