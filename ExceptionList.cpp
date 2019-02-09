#include "ExceptionList.h"

ExceptionStatisticMultiset::ExceptionStatisticMultiset(const std::string & message) noexcept : text_error(message){}

const char * ExceptionStatisticMultiset::what() const noexcept
{
	return text_error.c_str();
}
