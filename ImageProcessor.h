#pragma once

#include "TaskBuilder.h"
#include "PlugInManager.h"
#include "Result.h"
#include "WorkerPool.h"

class ImageProcessor final
{
public:
	const std::unique_ptr<ImageProcessor> GetInstance();

	//Here the Task is created and passed to the WorkerPool. Result is created and returned back;
	std::unique_ptr<Internal::Result> processTask(const std::string& imagePath, const std::vector<std::string>& operations);

private:
	ImageProcessor() {};

	const std::unique_ptr<ImageProcessor> imageProcessor = std::make_unique<ImageProcessor>();
	const std::unique_ptr<Internal::WorkerPool> workerPool = std::make_unique<Internal::WorkerPool>();
	const std::unique_ptr<Internal::PlugInManager> plugInManager = std::make_unique<Internal::PlugInManager>();
};
