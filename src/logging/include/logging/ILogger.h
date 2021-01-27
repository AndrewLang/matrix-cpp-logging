#pragma once
#include "common/TextFormatter.h"
#include "common/StringExtensions.h"
#include "common/Consts.h"
#include "LogLevel.h"
#include "LogMessage.h"

#include <string>
#include <map>
#include <functional>


namespace Logging
{	
	class ILogger
	{
	public:

		virtual ~ILogger() = default;

		virtual bool isEnabled(std::shared_ptr<LogLevel> level) = 0;

		virtual ILogger& log(LogMessage& message) = 0;

		virtual std::string getName() = 0;

		virtual void setName(const std::string value) = 0;

		template< typename ... Args >
		ILogger& debug(Args ... args)
		{			
			auto content = buildMessage(args...);
			auto message = LogMessage::debug(getName(), content);
			return log(message);
		}
		
		template< typename ... Args >
		ILogger& info(Args ... args)
		{
			auto content = buildMessage(args...);
			auto message = LogMessage::info(getName(), content);
			return log(message);
		}

		template< typename ... Args >
		ILogger& warn(Args ... args)
		{
			auto content = buildMessage(args...);
			auto message = LogMessage::warn(getName(), content);
			return log(message);
		}

		template< typename ... Args >
		ILogger& error(Args ... args)
		{
			auto content = buildMessage(args...);
			auto message = LogMessage::error(getName(), content);
			return log(message);
		}

		template< typename ... Args >
		ILogger& fatal(Args ... args)
		{			
			auto content = buildMessage(args...);
			auto message = LogMessage::fatal(getName(), content);
			return log(message);
		}

	private:
		
		template< typename TKey >
		std::string format(const TKey& text)
		{
			std::stringstream stream;
			stream << text << Consts::Space;
			return stream.str();
		}

		template< typename TKey, typename ... Args >
		std::string format(const TKey& first, Args ... args)
		{
			return format(first) + format(args...);
		}

		template< typename ... Args >
		std::string buildMessage(Args ... args)
		{			
			return format("", args...);
		}

	protected:
		ILogger() = default;

	};
}