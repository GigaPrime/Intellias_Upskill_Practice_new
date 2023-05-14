#pragma once

#include "Image.h"
#include "Task.h"

namespace Internal
{
	class Result
	{
	public:
		const bool isTaskSucessful(const std::unique_ptr<Task> task);
		// If task already handles image (it's allowed modify the original one, qithout creating a copy
		// what result should return except a boolean flag? 
		// Does task have to get some ID from the beginning to understand which path it's regarding to?
	};
}
