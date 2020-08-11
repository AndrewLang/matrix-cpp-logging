
#include "pch.h"
#include "gtest/gtest.h"
#include "logging/LogNameLayout.h"
#include "logging/LogMessage.h"

namespace Logging
{
	LogMessage DebugMessage()
	{
		return LogMessage::debug("Jasoom", "I come from Jasoom", "08-11-2020 12:11:10", 1);
	}

	TEST(LogNameLayoutTests, Constructor) {
		LogNameLayout layout;
	}

	TEST(LogNameLayoutTests, Layout) {
		LogNameLayout layout;
		LogMessage msg = DebugMessage();
		auto content = layout.layout(msg);

		EXPECT_EQ("[Jasoom]", content);
	}
}