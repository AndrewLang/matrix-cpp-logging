
#include "common/ArgumentNullException.h"
#include "common/TextFormatter.h"

namespace Logging
{
	using std::string;

	ArgumentNullException::ArgumentNullException(const string argument)
		:mArgument(argument)
	{
	}

	string ArgumentNullException::getArgument() const
	{
		return mArgument;
	}

	string ArgumentNullException::buildMessage() const
	{
		TextFormatter formatter;
		return formatter.format("Argument: '", mArgument, "' is NULL.");
	}
}