#pragma once

#include "TaskBuilder.h"
#include "PlugInManager.h"
#include "Result.h"
#include "WorkerPool.h"

class ImageProcessor final
{
public:
	const std::unique_ptr<ImageProcessor> GetInstance();

	ResultOutput processTask(const std::string& imagePath, const std::vector<std::string>& operations);

private:
	ImageProcessor() {};

	void instantiateTaskBuilde();
	void instantiateWorkerPool();

	const std::unique_ptr<ImageProcessor> imageProcessor = std::make_unique<ImageProcessor>();
	std::unique_ptr<Internal::TaskBuilder> taskBuilder = nullptr;
	std::unique_ptr<Internal::WorkerPool> workerPool = nullptr;
	std::unique_ptr<Internal::PlugInManager> plugInManager = nullptr;
};
