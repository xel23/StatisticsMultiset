#pragma once
#include "ExceptionList.h"

class EmptyStatisticMultiset : public ExceptionStatisticMultiset {
public:
	EmptyStatisticMultiset(const std::string &message) noexcept : ExceptionStatisticMultiset(message) {};
};