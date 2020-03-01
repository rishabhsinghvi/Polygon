#ifndef POLYGON_THREAD_POOL_H
#define POLYGON_THREAD_POOL_H

#include<future>
#include<queue>
#include<thread>
#include<mutex>
#include<utility>
#include<functional>
#include<type_traits>

namespace Polygon
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

			template<typename Func, typename ... Args>
			std::future<std::invoke_result_t<Func(Args...)>> SubmitTask(Func&& func, Args&& ... args)
			{
				using return_type = typename std::invoke_result_t(Func(Args)...);

				auto task = std::make_shared< std::packaged_task<return_type()> >(
					std::bind(std::forward<Func>(func), std::forward<Args>(args)...)
					);

				{
					std::unique_lock<std::mutex> lock(m_TaskAccessMutex);

					if (m_Running)
					{
						m_Tasks.emplace([task]() { (*task)(); });
					}
				}

				m_WaitConditional.notify_one();
				return task->get_future();
			}

		};
	}
}


#endif