
#include "pch.h"
#include "gtest/gtest.h"
#include "logging/LogProcessIdLayout.h"
#include "logging/LogMessage.h"
#include "Messages.h"

namespace Logging
{

	TEST(LogProcessIdLayoutTests, Constructor) {
		LogProcessIdLayout layout;
	}

	TEST(LogProcessIdLayoutTests, Layout) {
		LogProcessIdLayout layout;
		LogMessage msg = Messages::DebugMessage();
		auto content = layout.layout(msg);
		std::cout << content << std::endl;
	}
}