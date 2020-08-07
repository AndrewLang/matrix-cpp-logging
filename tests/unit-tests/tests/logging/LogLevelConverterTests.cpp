#include "pch.h"
#include "gtest/gtest.h"
#include "logging/LogLevelConverter.h"


namespace Logging
{	TEST(LogLevelConverterTests, ConvertToString) {
		LogLevelConverter converter;

		EXPECT_EQ("Debug", converter.toString(LogLevelEnum::Debug));
		EXPECT_EQ("Trace", converter.toString(LogLevelEnum::Trace));
		EXPECT_EQ("Information", converter.toString(LogLevelEnum::Information));
		EXPECT_EQ("Warning", converter.toString(LogLevelEnum::Warning));
		EXPECT_EQ("Error", converter.toString(LogLevelEnum::Error));
		EXPECT_EQ("Fatal", converter.toString(LogLevelEnum::Fatal));
		EXPECT_EQ("None", converter.toString(LogLevelEnum::None));
	}

}