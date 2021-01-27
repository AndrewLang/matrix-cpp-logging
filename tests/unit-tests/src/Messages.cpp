#include "Messages.h"

using namespace Logging;

namespace Tests
{
	Logging::LogMessage Messages::DebugMessage()
	{
		return LogMessage::debug("Jasoom", "I come from Jasoom", "08-11-2020 12:11:10", 1);
	}
}