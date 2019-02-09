#pragma once
#include <exception>
#include <string>

class ExceptionStatisticMultiset : public std::exception {
private:
	std::string text_error;
public:
	ExceptionStatisticMultiset(const std::string &message) noexcept;
	~ExceptionStatisticMultiset() {};
	const char * what() const noexcept;
};