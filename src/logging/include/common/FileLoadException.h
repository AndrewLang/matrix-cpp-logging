#pragma once
#include "BaseException.h"

namespace Logging
{
	class FileLoadException : public BaseException
	{
	public:
		FileLoadException(const std::string fileName);

	protected:
		std::string buildMessage() const override;

	private: 
		const std::string mFileName;
	};

}