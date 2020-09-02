#include "pch.h"
#include "gtest/gtest.h"
#include "logging/ConsoleColorRender.h"
#include "logging/LogLevels.h"
#include "common/VectorExtensions.h"

namespace Logging
{
	ConsoleColorRenderer createRenderer() {
		auto config = std::make_shared<ConsoleLoggerConfig>();
		config->addStyle(LogLevels::Debug)
			.addStyle(LogLevels::Info, "47")
			.addStyle(LogLevels::Warn, "226")
			.addStyle(LogLevels::Error, "226", "124", "bold")
			.addStyle(LogLevels::Fatal, "142", "", "bold,underline");

		ConsoleColorRenderer renderer;

		renderer.initialize(config);

		return renderer;
	}

	TEST(ConsoleColorRenderTests, Constructor) {
		auto render = createRenderer();
	}

	TEST(ConsoleColorRenderTests, VerifyStyles) {
		auto renderer = createRenderer();

		auto config = renderer.getConfig();
		auto actual = Vectors::firstOrDefault<ConsoleStyleConfig>(config->styles, [](ConsoleStyleConfig x) {return x.level == LogLevels::Debug; });
		EXPECT_EQ("", actual.foreColor);
		EXPECT_EQ("", actual.backColor);
		EXPECT_EQ("", actual.style);

		actual = Vectors::firstOrDefault<ConsoleStyleConfig>(config->styles, [](ConsoleStyleConfig x) {return x.level == LogLevels::Info; });
		EXPECT_EQ("47", actual.foreColor);
		EXPECT_EQ("", actual.backColor);
		EXPECT_EQ("", actual.style);

		actual = Vectors::firstOrDefault<ConsoleStyleConfig>(config->styles, [](ConsoleStyleConfig x) {return x.level == LogLevels::Warn; });
		EXPECT_EQ("226", actual.foreColor);
		EXPECT_EQ("", actual.backColor);
		EXPECT_EQ("", actual.style);

		actual = Vectors::firstOrDefault<ConsoleStyleConfig>(config->styles, [](ConsoleStyleConfig x) {return x.level == LogLevels::Error; });
		EXPECT_EQ("226", actual.foreColor);
		EXPECT_EQ("124", actual.backColor);
		EXPECT_EQ("bold", actual.style);

		actual = Vectors::firstOrDefault<ConsoleStyleConfig>(config->styles, [](ConsoleStyleConfig x) {return x.level == LogLevels::Fatal; });
		EXPECT_EQ("142", actual.foreColor);
		EXPECT_EQ("", actual.backColor);
		EXPECT_EQ("bold,underline", actual.style);

	}

	TEST(ConsoleColorRenderTests, RenderDebug) {
		auto renderer = createRenderer();
		auto actual = renderer.render(LogLevels::Debug, "Jasoom");

		EXPECT_EQ("\x1B[mJasoom\x1B[m", actual);
	}

	TEST(ConsoleColorRenderTests, RenderInfo) {
		auto renderer = createRenderer();
		auto actual = renderer.render(LogLevels::Info, "Jasoom");

		EXPECT_EQ("\x1B[38;5;47mJasoom\x1B[m", actual);
	}

	TEST(ConsoleColorRenderTests, RenderWarn) {
		auto renderer = createRenderer();
		auto actual = renderer.render(LogLevels::Warn, "Jasoom");

		EXPECT_EQ("\x1B[38;5;226mJasoom\x1B[m", actual);
	}

	TEST(ConsoleColorRenderTests, RenderError) {
		auto renderer = createRenderer();
		auto actual = renderer.render(LogLevels::Error, "Jasoom");

		EXPECT_EQ("\x1B[38;5;226;48;5;124;1mJasoom\x1B[m", actual);
	}

	TEST(ConsoleColorRenderTests, RenderFatal) {
		auto renderer = createRenderer();
		auto actual = renderer.render(LogLevels::Fatal, "Jasoom");

		EXPECT_EQ("\x1B[38;5;142;1;4mJasoom\x1B[m", actual);
	}
}