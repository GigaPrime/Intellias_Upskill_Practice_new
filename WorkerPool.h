#pragma once

#include <queue>
#include <thread>

#include "Task.h"

namespace Internal
{
	class WorkerPool
	{
	public:
		Result addTask(const std::unique_ptr<Task> task);

	private:
		WorkerPool();

		std::unique_ptr<WorkerPool> workerPool;

		void addTaskToActiveQueue(const std::unique_ptr<Task> task);
		void addTaskToNonActiveQueue(const std::unique_ptr<Task> task);
		void storeTaskToCache(const std::unique_ptr<Task> task);
		const std::unique_ptr<Task> getTaskFromCache();

		void processTask();

		std::priority_queue<Task> activeTasks;
		std::priority_queue<Task> nonActiveTasks;
		std::vector<std::thread> threads;
	};
}
