#pragma once

#include <memory>
#include <future>

#include "Image.h"
#include "Operation.h"
#include "Result.h"

namespace Internal
{
	class Task final
	{
	public:
		// TaskBuilder call here
		static std::unique_ptr<Task> createTask(const std::string& imagePath, const std::vector<std::string>& operations); 
		const std::vector<std::unique_ptr<Operation>> getOperationList() const;
		const std::unique_ptr<Image> getImage() const;
		const std::string getTaskPriority() const;

	private:
		Task() {};
		
		void defineTaskPriority();

		std::unique_ptr<Image> image;
		std::vector<std::unique_ptr<Operation>> operations;
		std::string taskPriority;
		std::promise<Result> result;
	};
}
