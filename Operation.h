#pragma once

#include <any>
#include <functional>
#include <string>

#include "PlugInManager.h"

namespace Internal
{
	// Operation is a kinda wrapper over the PlugIn::perform(Image& image) method
	class Operation
	{
	public:
		std::function<void()> getPlugInsFucntions(const std::string& plugInDirectory);

		virtual void perform(Image& image) const = 0;
		virtual void perform(Image& image, std::any param, ...) const = 0;
	};
}

