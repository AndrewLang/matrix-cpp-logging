#pragma once
#include "TextFormatter.h"


namespace Logging
{
	class BaseException : public std::exception
	{
	public:
		BaseException();
		
		virtual char const * what() const noexcept;

	protected:
		virtual std::string buildMessage() const;
	};

}