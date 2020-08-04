#include "common/BaseException.h"

namespace Logging
{
	using std::string;

	BaseException::BaseException()
	{
	}

	char const * BaseException::what() const noexcept
	{
		return buildMessage().c_str();
	}

	string BaseException::buildMessage() const
	{
		return "";
	}	

}