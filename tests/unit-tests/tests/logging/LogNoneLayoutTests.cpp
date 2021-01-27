
#include "pch.h"
#include "gtest/gtest.h"
#include "logging/LogNoneLayout.h"
#include "logging/LogMessage.h"
#include "Messages.h"

namespace Logging
{
	using namespace Tests;
	TEST(LogNoneLayoutTests, Constructor) {
		LogNoneLayout layout;
	}

	TEST(LogNoneLayoutTests, Layout) {
		LogNoneLayout layout;
		LogMessage msg = Messages::DebugMessage();
		auto content = layout.layout(msg);

		EXPECT_EQ("", content);
	}
}