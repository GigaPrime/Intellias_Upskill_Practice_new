#pragma once

#include "Task.h"
#include "Image.h"

// parallelize Task and Image

namespace Internal
{
	class TaskBuilder final
	{
	public:
		const std::unique_ptr<TaskBuilder> getInastance();

		std::unique_ptr<Task> buildTask(const std::string& imagePath, const std::vector<std::string>& operations);

	private:
		const std::unique_ptr<TaskBuilder> taskBuilder = nullptr;

		const std::unique_ptr<Image> createImage(const std::string& imagePath) const;
		const bool isCreatedImageValid(std::unique_ptr<Image> image) const;

		std::unique_ptr<Task> createTask(const std::unique_ptr<Image> image, const std::vector<std::string>& operations) const;
		void convertOperationStringToOperationType(const std::string operation) const;

		void passTaskToWorkerPool(std::unique_ptr<Task> task) const;
	};
}
