#include "pch.h"
#include "gtest/gtest.h"
#include "logging/LogLevels.h"

namespace Logging
{
	TEST(LogLevelsTests, Constructor) {
		EXPECT_EQ("All", LogLevels::All->getName());
		EXPECT_EQ("Debug", LogLevels::Debug->getName());
		EXPECT_EQ("Info", LogLevels::Info->getName());
		EXPECT_EQ("Warn", LogLevels::Warn->getName());
		EXPECT_EQ("Error", LogLevels::Error->getName());
		EXPECT_EQ("Fatal", LogLevels::Fatal->getName());
		EXPECT_EQ("None", LogLevels::None->getName());

		EXPECT_EQ(0, LogLevels::All->getValue());
		EXPECT_EQ(100, LogLevels::Debug->getValue());
		EXPECT_EQ(200, LogLevels::Info->getValue());
		EXPECT_EQ(300, LogLevels::Warn->getValue());
		EXPECT_EQ(400, LogLevels::Error->getValue());
		EXPECT_EQ(500, LogLevels::Fatal->getValue());
		EXPECT_EQ(99999, LogLevels::None->getValue());
	}

}