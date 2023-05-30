#pragma once

#include <map>
#include <Windows.h>

#include "Image.h"

namespace Internal
{
	class PlugInManager
	{
	public:
		// Here a default PlugIn directory should be parsed for the PlugIn files in there
		void addPlugIns(const std::string& plugInPath);
		void removePlugIns(const std::string identifier);
		
		template<typename Function>
		Function getFunction(const std::string& functionName);

	private:
		std::map<std::string, std::string> plugIns;
		HMODULE plugInHandle = nullptr;
	};
}
