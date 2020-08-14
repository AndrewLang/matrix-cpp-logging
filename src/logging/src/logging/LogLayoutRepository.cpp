#include "common/MapExtensions.h"
#include "logging/LogLayoutRepository.h"
#include "logging/LogNameLayout.h"
#include "logging/LogLevelLayout.h"
#include "logging/LogIndentLayout.h"
#include "logging/LogMessageLayout.h"
#include "logging/LogNoneLayout.h"
#include "logging/LogProcessIdLayout.h"
#include "logging/LogThreadIdLayout.h"
#include "logging/LogTimestampLayout.h"

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
			;

		return *this;
	}

	LogLayoutRepository& LogLayoutRepository::add(const std::string name, LogLayoutCreator creator)
	{
		creators.insert(std::make_pair(name, creator));

		return *this;
	}

	std::shared_ptr<ILogLayout> LogLayoutRepository::get(const std::string name)
	{
		auto creator = Maps::get<std::string, LogLayoutCreator>(creators, name);

		if(creator == nullptr)
			creator = Maps::get<std::string, LogLayoutCreator>(creators, LayoutNames::None);
				
		if (creator != nullptr)
			return creator();
		else
			return nullptr;
	}
}