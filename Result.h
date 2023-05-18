#pragma once

#include "Image.h"
#include "Task.h"

namespace Internal
{
	class Result
	{
	public:
		Result(const std::future<Image>& image);
		std::promise<Image> getImage();
	private:
		std::future<Image> modifiedImage;
	};
}
