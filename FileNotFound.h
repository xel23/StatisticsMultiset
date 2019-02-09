#pragma once
#include "ExceptionList.h"

class FileNotFound : public ExceptionStatisticMultiset {
public:
	FileNotFound(const std::string &message) noexcept : ExceptionStatisticMultiset(message) {};
};