#pragma once

#include <map>

#include "Image.h"

namespace Internal
{
	class PlugInManager
	{
	public:
		// Here a default PlugIn directory should be parsed for the PlugIn files in there
		// PlugIn instance (with the internal logic) would be created and added to the 
		// std::map<std::string, std::unique_ptr<PlugIn>> plugIns
		void addPlugIns(const std::pair<std::string, std::unique_ptr<PlugIn>>& plugInWithIdentifier);
		void removePlugIns(const std::string identifier);
		const std::map<std::string, std::unique_ptr<PlugIn>> getConnectedPlugIns();
		const bool isPlugInConnected(std::string identifier);

	private:
		std::map<std::string, std::unique_ptr<PlugIn>> plugIns;
	};

	class PlugIn
	{
	public:
		virtual const std::string getPlugInName() const = 0;
		virtual void setParams(const std::any& param, ...) = 0;
		virtual void perform(Image& image) const = 0;
	};

	class ConcretePlugIn : public PlugIn
	{
	public:
		const std::string getPlugInName() const;
		void setParams(const std::any& param, ...);
		void perform(Image& image) const;
	private:
		const std::string name;
		// some internal logic here passed from the separate plugIn file
		// parsed from the default plugIn directory
	};
}
