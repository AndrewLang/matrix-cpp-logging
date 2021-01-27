#pragma once

#include "LogLayout.h"

#include <map>
#include <functional>
#include <queue> 

namespace Logging
{
	using LogLayoutCreator = std::function<std::shared_ptr<ILogLayout>()>;

	class LayoutNames
	{
	public:
		static constexpr const char* Name = "name";
		static constexpr const char* Level = "level";
		static constexpr const char* Timestamp = "timestamp";
		static constexpr const char* Message = "message";
		static constexpr const char* Indent = "indent";
		static constexpr const char* ThreadId = "threadid";
		static constexpr const char* ProcessId = "processid";
		static constexpr const char* Text = "text";
		static constexpr const char* None = "none";
	};


	class LogLayoutRepository
	{
	public:
		LogLayoutRepository();

		~LogLayoutRepository();

		LogLayoutRepository& initialize();

		LogLayoutRepository& add(const std::string& name, LogLayoutCreator creator);

		std::shared_ptr<ILogLayout> get(const std::string& name);

		std::vector<std::shared_ptr<ILogLayout>> parse(const std::string& format);

	private:
		std::map<std::string, LogLayoutCreator> mCreators;

		std::string toString(std::queue<char>& chars);
	};

}