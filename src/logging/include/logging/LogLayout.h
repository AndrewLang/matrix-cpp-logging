#pragma once

#include "LogMessage.h"

namespace Logging
{

	class ILogLayout
	{
	private:

	public:
		virtual std::string layout(const LogMessage& message) = 0;
	};

	class LogLayout : public ILogLayout
	{
	protected:
		static constexpr const char* BracketLeft = "[";
		static constexpr const char* BracketRight = "]";
	};
}