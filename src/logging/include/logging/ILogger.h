#pragma once
#include "common/TextFormatter.h"
#include "common/StringExtensions.h"
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
		std::string name;

		virtual bool isEnabled(std::shared_ptr<LogLevel> level) = 0;

		virtual ILogger& log(LogMessage& message) = 0;

		template< typename ... Args >
		ILogger& debug(Args ... args)
		{			
			auto content = buildMessage(args...);
			auto message = LogMessage::debug(name, content);
			return log(message);
		}
		
		template< typename ... Args >
		ILogger& info(Args ... args)
		{
			auto content = buildMessage(args...);
			auto message = LogMessage::info(name, content);
			return log(message);
		}

		template< typename ... Args >
		ILogger& warn(Args ... args)
		{
			auto content = buildMessage(args...);
			auto message = LogMessage::warn(name, content);
			return log(message);
		}

		template< typename ... Args >
		ILogger& error(Args ... args)
		{
			auto content = buildMessage(args...);
			auto message = LogMessage::error(name, content);
			return log(message);
		}

		template< typename ... Args >
		ILogger& fatal(Args ... args)
		{			
			auto content = buildMessage(args...);
			auto message = LogMessage::fatal(name, content);
			return log(message);
		}

	private:
		
		template< typename TKey >
		std::string format(const TKey& text)
		{
			std::stringstream stream;
			stream << text << SPACE;
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
		

	};
}