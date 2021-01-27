#pragma once
#include "common/TextFormatter.h"
#include "common/StringExtensions.h"
#include "common/Consts.h"

#if defined(_WIN32)
#include <Windows.h>
#endif

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <time.h>
#include <stdio.h>

namespace Logging
{
	class VsOutput
	{
	public:

		template<typename ... Args >
		static void debug(Args&& ... args)
		{
			TextFormatter formatter;
			auto message = formatter.format(args...);

			message = StringExtensions::wrapBySquare(StringExtensions::getTimestamp()) + Consts::Space + message;

			logMessage(message);

		}

		template<typename ... Args >
		static void debugLine(Args&& ... args)
		{
			TextFormatter formatter;
			auto message = formatter.format(args...);
			message = StringExtensions::wrapBySquare(StringExtensions::getTimestamp()) + Consts::Space + message + StringExtensions::NewLine;

			logMessage(message);
		}

		/*Write message to VsOutput without prepend timestamp*/
		template<typename ... Args >
		static void writeLine(Args&& ... args)
		{
			TextFormatter formatter;
			auto message = formatter.format(args...);
			message = message + Consts::NewLine;

			logMessage(message);
		}

		template<typename ... Args >
		static void debugWithName(std::string name, Args&& ... args)
		{
			TextFormatter formatter;
			auto message = StringExtensions::wrapBySquare(StringExtensions::getTimestamp())
				+ SPACE
				+ StringExtensions::paddingString(name)
				+ SPACE
				+ formatter.format(args...)
				+ StringExtensions::NewLine;

			logMessage(message);
		}

	private:

		inline static void logMessage(const std::string message)
		{			

#if defined(_WIN32)
			OutputDebugStringA(message.c_str());
#endif
		}
	};

}
