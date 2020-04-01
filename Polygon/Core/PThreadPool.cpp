#include "PThreadPool.h"

namespace PolygonEngine
{
	namespace Core
	{
		PThreadPool::PThreadPool(unsigned int numWorkers)
		{
			m_Workers.reserve(numWorkers);
			for (auto i = 0; i < numWorkers; i++)
			{
				m_Workers.emplace_back([this] {
					while (true)
					{
						std::function<void()> _task;

						{
							std::unique_lock<std::mutex> lock(m_TaskAccessMutex);
							m_WaitConditional.wait(lock, [this] { return !m_Running || !m_Tasks.empty(); });

							if (!m_Running && !m_Tasks.empty())
								return;

							_task = std::move(m_Tasks.front());
							m_Tasks.pop();

						}
						_task();
					}
					});
			}

		}


		PThreadPool::~PThreadPool()
		{
			{
				std::lock_guard<std::mutex> lock(m_TaskAccessMutex);
				m_Running = false;
			}

			m_WaitConditional.notify_all();
			for (auto& worker : m_Workers)
			{
				worker.join();
			}
		}
	}
}