#pragma once

#include <string>

namespace sw::core::pipeline
{
	class Intent
	{
	public:
		virtual ~Intent() = default;

		void cancel(const std::string& reason)
		{
			isCancelled = true;
			cancelReason = reason;
		}

		bool getCancelled() const
		{
			return isCancelled;
		}

		const std::string& getCancelReason() const
		{
			return cancelReason;
		}

	private:
		bool isCancelled = false;
		std::string cancelReason;
	};
}
