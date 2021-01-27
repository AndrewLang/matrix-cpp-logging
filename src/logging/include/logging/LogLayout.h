#pragma once

#include "LogMessage.h"

namespace Logging
{
	class ILogLayout
	{	
	public:
		virtual ~ILogLayout() = default;

		virtual std::string layout(const LogMessage& message) = 0;

	protected:
		ILogLayout() = default;
	};

	class LogLayout : public ILogLayout
	{
	protected:
		std::string layout(const LogMessage& message)  override;
	};
}