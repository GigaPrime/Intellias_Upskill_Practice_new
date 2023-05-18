#pragma once

#include "PlugInManager.h"
#include "Task.h"

namespace Internal
{
	class TaskBuilder final
	{
	public:
		std::unique_ptr<Task> buildTask(const std::string& imagePath, const std::vector<std::string>& operations);

	private:
		const std::unique_ptr<Task> createTask(const std::unique_ptr<Image> image, const std::vector<std::unique_ptr<Operation>>& operations) const;
		const std::unique_ptr<Image> createImage(const std::string& imagePath) const;

		// Here the PLugInManager is asked for the available plugIns
		// std::string PlugIn::getPlugInName() should return exactly the same name as the 
		// operation string obtained as a parametr 
		const std::vector<std::unique_ptr<Operation>> createOperations(const std::vector<std::string>& operations) const;
	};
}
