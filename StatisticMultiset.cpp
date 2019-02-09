#include "StatisticMultiset.h"

template<class T>
StatisticMultiset<T>::StatisticMultiset()
{
	menu();
}

template<class T>
StatisticMultiset<T>::~StatisticMultiset()
{
}

template<class T>
void StatisticMultiset<T>::AddNum(T num)
{
	cache.reset();
	storage.insert(num);
	std::cout << "Added number: " << num << std::endl;
}

template<class T>
void StatisticMultiset<T>::AddNum(const std::multiset<T>& numbers)
{
	cache.reset();
	storage.insert(numbers.begin(), numbers.end());
	std::cout << "Added multiset: ";
	for (auto i : numbers) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

template<class T>
void StatisticMultiset<T>::AddNum(const std::vector<T>& numbers)
{
	cache.reset();
	storage.insert(numbers.begin(), numbers.end());
	std::cout << "Added vector: ";
	for (auto i : numbers) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

template<class T>
void StatisticMultiset<T>::AddNum(const std::list<T>& numbers)
{
	cache.reset();
	storage.insert(numbers.begin(), numbers.end());
	std::cout << "Added list: ";
	for (auto i : numbers) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

template<class T>
void StatisticMultiset<T>::AddNum(const StatisticMultiset & a_stat_set)
{
	cache.reset();
	storage.insert(a_stat_set.storage.begin(), a_stat_set.storage.end());
	std::cout << "Added stat_set: ";
	for (auto i : a_stat_set.storage) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

template<class T>
void StatisticMultiset<T>::AddNumFromFile(const char * filename)
{
	cache.reset();
	std::ifstream in(filename);
	int _num;
	if (in.is_open()) {
		while (!in.eof()) {
			in >> _num;
			storage.insert(_num);
		}
	}
	else throw FileNotFound("File " + (std::string)filename + "not found");
	in.close();
}

template<class T>
T StatisticMultiset<T>::GetMax() const
{
	if (!storage.empty()) {
		return *(--storage.end());
	}
	else throw EmptyStatisticMultiset("StatisticMultiset is empty!");
}

template<class T>
T StatisticMultiset<T>::GetMin() const
{
	if (!storage.empty()) {
		return *(storage.begin());
	}
	else throw EmptyStatisticMultiset("StatisticMultiset is empty!");
}

template<class T>
float StatisticMultiset<T>::GetAvg() const 
{
	if (!storage.empty()) {
		if (cache.wasChangedAvg()) {
			cache.setAvg(static_cast<float> (std::for_each(storage.begin(), storage.end(), Sum()).sum) / storage.size());
			return cache.getAvg();
		}
		else return cache.getAvg();
	}
	else throw EmptyStatisticMultiset("StatisticMultiset is empty!");
}

template<class T>
int StatisticMultiset<T>::counterUnder(float threshold, const std::multiset<T>& ms) const
{
	int counter = 0;
	for (auto i : ms) {
		if (threshold > i) ++counter;
		else break;
	}
	return counter;
}

template<class T>
int StatisticMultiset<T>::counterAbove(float threshold, const std::multiset<T>& ms) const
{
	int counter = 0;
	for (auto i : ms) {
		if (threshold > i) ++counter;
		else break;
	}
	return storage.size() - counter;
}

template<class T>
int StatisticMultiset<T>::GetCountUnder(float threshold) const
{
	if (!storage.empty()) {
		if (cache.wasChangedUnder()) {
			cache.setUnder(static_cast<T>(threshold), counterUnder(threshold, storage));
			return cache.getUnder(static_cast<T>(threshold));
		}
		else if (cache.isHaveUnder(static_cast<T>(threshold))) {
			std::cout << "<---------------from cache-------------->" << std::endl;
			return cache.getUnder(static_cast<T>(threshold));
		}
		else {
			cache.setUnder(static_cast<T>(threshold), counterUnder(threshold, storage));
			return cache.getUnder(static_cast<T>(threshold));
		}
	}
	else throw EmptyStatisticMultiset("StatisticMultiset is empty!");
}

template<class T>
int StatisticMultiset<T>::GetCountAbove(float threshold) const
{
	if (!storage.empty()) {
		if (cache.wasChangedAbove()) {
			cache.setAbove(static_cast<T>(threshold), counterAbove(threshold, storage));
			return cache.getAbove(static_cast<T>(threshold));
		}
		else if (cache.isHaveAbove(static_cast<T>(threshold))) {
			std::cout << "<---------------from cache-------------->" << std::endl;
			return cache.getAbove(static_cast<T>(threshold));
		}
		else {
			cache.setAbove(static_cast<T>(threshold), counterAbove(threshold, storage));
			return cache.getAbove(static_cast<T>(threshold));
		}
	}
	else throw EmptyStatisticMultiset("StatisticMultiset is empty!");
}

template<class T>
void StatisticMultiset<T>::menuAddNum()
{
	std::cout << "1. Add number manually" << std::endl
		<< "2. Add number from <multiset>" << std::endl
		<< "3. Add number from <vector>" << std::endl
		<< "4. Add number from <list>" << std::endl
		<< "5. Add number from StaticticMultiset" << std::endl 
		<< "6. Add number from file"
		<< "Select an action: " << std::endl;
	int chose;
	std::cin >> chose;
	switch (chose) {
	case 1: {
		std::cout << "Enter number: ";
		T _num;
		std::cin >> _num;
		AddNum(_num);
		break;
	}
	case 2: AddNum(setExample); break;
	case 3: AddNum(vectorExample); break;
	case 4: AddNum(listExample); break;
	case 5: break;
	case 6: {
		std::cout << "Enter file name: ";
		std::string filename;
		std::cin >> filename;
		AddNumFromFile(filename.c_str());
		break;
	}
	default: throw UnexpextedType("Action is impossible");
	}
}

template<class T>
void StatisticMultiset<T>::menu()
{
	int flag = 1;
	while (flag) {
		std::cout << "1. Add number" << std::endl
			<< "2. Get max" << std::endl
			<< "3. Get min" << std::endl
			<< "4. Get average" << std::endl
			<< "5. Get count under" << std::endl
			<< "6. Get count above" << std::endl
			<< "7. Exit" << std::endl
			<< "Select an action: ";
		int chose;
		std::cin >> chose;
		switch (chose) {
		case 1: menuAddNum(); break;
		case 2: std::cout << "Max number: " << GetMax() << std::endl; break;
		case 3: std::cout << "Min number: " << GetMin() << std::endl; break;
		case 4: std::cout << "Average number: " << GetAvg() << std::endl; break;
		case 5: {
			float _num;
			std::cout << "Enter your float number: ";
			std::cin >> _num;
			std::cout << "Count of under " << _num << ": " << GetCountUnder(_num) << std::endl; break;
		}
		case 6: {
			float _num;
			std::cout << "Enter your float number: ";
			std::cin >> _num;
			std::cout << "Count of above " << _num << ": " << GetCountAbove(_num) << std::endl; break;
		}
		case 7: flag = 0; break;
		default: throw UnexpextedType("Action is impossible");
		}
	}
}
