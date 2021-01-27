#include "common/MapExtensions.h"
#include "common/StringExtensions.h"
#include "logging/LogLayoutRepository.h"
#include "logging/LogNameLayout.h"
#include "logging/LogLevelLayout.h"
#include "logging/LogIndentLayout.h"
#include "logging/LogMessageLayout.h"
#include "logging/LogNoneLayout.h"
#include "logging/LogProcessIdLayout.h"
#include "logging/LogThreadIdLayout.h"
#include "logging/LogTimestampLayout.h"
#include "logging/LogTextLayout.h"


namespace Logging
{
	LogLayoutRepository::LogLayoutRepository()
	{
	}

	LogLayoutRepository::~LogLayoutRepository()
	{
	}

	LogLayoutRepository& LogLayoutRepository::initialize()
	{
		add(LayoutNames::Name, []() { return std::make_shared<LogNameLayout>(); })
			.add(LayoutNames::Level, []() { return std::make_shared<LogLevelLayout>(); })
			.add(LayoutNames::Timestamp, []() { return std::make_shared<LogTimestampLayout>(); })
			.add(LayoutNames::Message, []() { return std::make_shared<LogMessageLayout>(); })
			.add(LayoutNames::Indent, []() { return std::make_shared<LogIndentLayout>(); })
			.add(LayoutNames::ThreadId, []() { return std::make_shared<LogThreadIdLayout>(); })
			.add(LayoutNames::ProcessId, []() { return std::make_shared<LogProcessIdLayout>(); })
			.add(LayoutNames::None, []() { return std::make_shared<LogNoneLayout>(); })
			.add(LayoutNames::Text, []() {return std::make_shared<LogTextLayout>(); })
			;

		return *this;
	}

	LogLayoutRepository& LogLayoutRepository::add(const std::string& name, LogLayoutCreator creator)
	{
		mCreators.insert(std::make_pair(name, creator));

		return *this;
	}

	std::shared_ptr<ILogLayout> LogLayoutRepository::get(const std::string& name)
	{
		auto creator = Maps::get<std::string, LogLayoutCreator>(mCreators, name);

		if (creator != nullptr)
			return creator();
		else
			return nullptr;
	}
	
	std::vector<std::shared_ptr<ILogLayout>> LogLayoutRepository::parse(const std::string & format)
	{
		std::vector<std::shared_ptr<ILogLayout>> layouts;

		if (Strings::notNullOrEmpty(format))
		{
			const char left = '{';
			const char right = '}';
			
			std::queue<char> word;

			for (auto& c : format)
			{
				if (c == left || c == right)
				{
					std::string name = toString(word);
					if (Strings::notNullOrEmpty(name))
					{
						auto layout = get(name);
						if (layout == nullptr)
						{
							layout = std::make_shared<LogTextLayout>(name);
						}
						layouts.push_back(layout);
					}

					continue;
				}

				word.push(c);
			}
		}

		return layouts;
	}
	
	std::string LogLayoutRepository::toString(std::queue<char>& chars)
	{
		std::stringstream stream;
		while (!chars.empty())
		{
			stream << chars.front();
			chars.pop();
		}
		return stream.str();
	}
}