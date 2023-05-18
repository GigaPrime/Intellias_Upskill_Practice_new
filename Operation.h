#pragma once

#include <any>
#include <string>

namespace Internal
{
	// Operation is a kinda wrapper over the PlugIn::perform(Image& image) method
	class Operation
	{
	public:
		virtual void perform(Image& image) const = 0;
		virtual void perform(Image& image, std::any param, ...) const = 0;
	};
}

