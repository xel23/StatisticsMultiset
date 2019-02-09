#pragma once
#include "ExceptionList.h"

class UnexpextedType : public ExceptionStatisticMultiset {
public:
	UnexpextedType(const std::string &message) noexcept : ExceptionStatisticMultiset(message) {};
};