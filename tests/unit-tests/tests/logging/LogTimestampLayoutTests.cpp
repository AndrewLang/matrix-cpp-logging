
#include "pch.h"
#include "gtest/gtest.h"
#include "logging/LogTimestampLayout.h"
#include "logging/LogMessage.h"
#include "Messages.h"

namespace Logging
{	
	TEST(LogTimestampLayoutTests, Constructor) {
		LogTimestampLayout layout;
	}

	TEST(LogTimestampLayoutTests, Layout) {
		LogTimestampLayout layout;
		LogMessage msg = Messages::DebugMessage();
		auto content = layout.layout(msg);

		EXPECT_EQ("08-11-2020 12:11:10", content);
	}
}