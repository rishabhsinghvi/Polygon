#ifndef POLYGON_THREAD_POOL_H
#define POLYGON_THREAD_POOL_H

#include<future>
#include<queue>
#include<thread>
#include<mutex>
#include<utility>
#include<functional>
#include<type_traits>

namespace PolygonEngine
{
	namespace Core
	{
		class PThreadPool
		{
		private:
			std::vector<std::thread> m_Workers;
			std::queue<std::function<void()>> m_Tasks;
			std::mutex m_TaskAccessMutex;
			std::condition_variable m_WaitConditional;
			
			bool m_Running = true;

		public:
			PThreadPool(unsigned int numWorkers = std::thread::hardware_concurrency());

			PThreadPool(const PThreadPool&) = delete;

			PThreadPool operator=(const PThreadPool&) = delete;

			PThreadPool(PThreadPool&&) = default;

			~PThreadPool();

			template<typename Func, typename...Args>
			auto SubmitTask(Func&& func, Args&&... args) -> std::future<decltype(f(args...))> {
				
				std::function<decltype(func(args...))()> funcWrapper = std::bind(std::forward<Func>(func), std::forward<Args>(args)...);
				
				auto task = std::make_shared<std::packaged_task<decltype(func(args...))()>>(funcWrapper);
				std::function<void()> taskToEnqueue = [task]() {
					(*task)();
				};
				
				m_Tasks.push(taskToEnqueue);
				m_WaitConditional.notify_one();

				return taskToEnqueue->get_future();
			}

		};
	}
}


#endif