#include "pch.h"
#include "gtest/gtest.h"
#include "logging/LogMessage.h"
#include "logging/LogLevels.h"

namespace Logging
{
	TEST(LogMessageTests, Constructor) {
		LogMessage message(LogLevels::Default()->debug(), "jasoom", "I come from jasoom", "08-07-2020 10:10:10");

		EXPECT_EQ("jasoom", message.getName());
		EXPECT_EQ("I come from jasoom", message.getMessage());
		EXPECT_EQ("Debug", message.getLevel()->getName());
		EXPECT_EQ("08-07-2020 10:10:10", message.getTimmestamp());
		EXPECT_EQ(0, message.getIndent());
	}

	TEST(LogMessageTests, Debug) {
		LogMessage msg = LogMessage::debug("jasoom", "I came from jasoom", "08-07-2020 10:10:10", 1);

		EXPECT_EQ("jasoom", msg.getName());
		EXPECT_EQ("I came from jasoom", msg.getMessage());
		EXPECT_EQ("Debug", msg.getLevel()->getName());
		EXPECT_EQ("08-07-2020 10:10:10", msg.getTimmestamp());
		EXPECT_EQ(1, msg.getIndent());
	}

	TEST(LogMessageTests, Info) {
		LogMessage msg = LogMessage::info("jasoom", "I came from jasoom", "08-07-2020 10:10:10", 1);

		EXPECT_EQ("jasoom", msg.getName());
		EXPECT_EQ("I came from jasoom", msg.getMessage());
		EXPECT_EQ("Info", msg.getLevel()->getName());
		EXPECT_EQ("08-07-2020 10:10:10", msg.getTimmestamp());
		EXPECT_EQ(1, msg.getIndent());
	}

	TEST(LogMessageTests, Warn) {
		LogMessage msg = LogMessage::warn("jasoom", "I came from jasoom", "08-07-2020 10:10:10", 1);

		EXPECT_EQ("jasoom", msg.getName());
		EXPECT_EQ("I came from jasoom", msg.getMessage());
		EXPECT_EQ("Warn", msg.getLevel()->getName());
		EXPECT_EQ("08-07-2020 10:10:10", msg.getTimmestamp());
		EXPECT_EQ(1, msg.getIndent());
	}

	TEST(LogMessageTests, Error) {
		LogMessage msg = LogMessage::error("jasoom", "I came from jasoom", "08-07-2020 10:10:10", 1);

		EXPECT_EQ("jasoom", msg.getName());
		EXPECT_EQ("I came from jasoom", msg.getMessage());
		EXPECT_EQ("Error", msg.getLevel()->getName());
		EXPECT_EQ("08-07-2020 10:10:10", msg.getTimmestamp());
		EXPECT_EQ(1, msg.getIndent());
	}

	TEST(LogMessageTests, Fatal) {
		LogMessage msg = LogMessage::fatal("jasoom", "I came from jasoom", "08-07-2020 10:10:10", 1);

		EXPECT_EQ("jasoom", msg.getName());
		EXPECT_EQ("I came from jasoom", msg.getMessage());
		EXPECT_EQ("Fatal", msg.getLevel()->getName());
		EXPECT_EQ("08-07-2020 10:10:10", msg.getTimmestamp());
		EXPECT_EQ(1, msg.getIndent());
	}
}