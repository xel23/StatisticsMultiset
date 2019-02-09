#include "StatisticMultiset.h"
#include "StatisticMultiset.cpp"

int main() {
	try {
		StatisticMultiset<int> test;
	}
	catch (const std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
}