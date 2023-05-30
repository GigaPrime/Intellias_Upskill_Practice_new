#include <filesystem>
#include <exception>

#include "PlugInManager.h"

void Internal::PlugInManager::addPlugIns(const std::string& plugInPath)
{
	// All the filesystem checks from here and from the image.cpp could be moved to the separate
	// service component
	if (!std::filesystem::exists(plugInPath))
	{
		throw std::runtime_error(std::string("PlugIn path " + plugInPath + " doesn't exist or is not valid"));
		return;
	}

	plugInHandle = LoadLibraryA(plugInPath.c_str());
}

void Internal::PlugInManager::removePlugIns(const std::string identifier)
{
	if (plugInHandle != nullptr)
	{
		FreeLibrary(plugInHandle);
		plugInHandle = nullptr;
	}
}

template<typename Function>
Function Internal::PlugInManager::getFunction(const std::string& functionName)
{
	if (plugInHandle != nullptr)
	{
		auto functionAddress = GetProcAddress(plugInHandle, functionName.c_str());
		if (functionAddress != nullptr)
		{
			return reinterpret_cast<Function>(functionAddress);
		}
		return nullptr;
	}
}