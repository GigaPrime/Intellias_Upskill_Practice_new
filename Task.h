#pragma once

#include <memory>
#include <future>

#include "Image.h"
#include "Operation.h"
#include "PlugInManager.h"
#include "Result.h"

namespace Internal
{
	class Task
	{
	public:
		static Task createTask(const std::unique_ptr<Image> image, const std::vector<Operation>& operatoins);
		const std::vector<std::shared_ptr<Operation>> getOperationList() const;
		const std::unique_ptr<Image> getImage() const;
		const std::string getTaskPriority() const;

	private:
		Task() {};
		
		void setOperations();
		void defineTaskPriority();

		std::unique_ptr<Image> image;
		std::vector<std::shared_ptr<Operation>> operations;
		std::string taskPriority;
		std::future<Result> result;
	};
}

