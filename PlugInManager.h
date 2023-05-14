#pragma once

#include <map>

#include "Operation.h"

namespace Internal
{
	class PlugInManager
	{
	public:
		void addPlugIns(const std::pair<std::string, std::unique_ptr<PlugIn>>& plugInWithIdentifier);
		void removePlugIns(const std::string identifier);
		const std::map<std::string, std::unique_ptr<PlugIn>> getConnectedPlugIns();
		const bool isPlugInConnected(std::string identifier);

	private:
		std::vector<std::unique_ptr<PlugIn>> plugIns;
	};

	class PlugIn
	{
	public:

	};
}
