#pragma once
#include <set>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <iostream>
#include "ExceptionList.h"
#include "FileNotFound.h"
#include "UnexpextedType.h"
#include "SMcache.h"
#include "SMcache.cpp"
#include "EmptyStatisticMultiset.h"

template <class T>
class StatisticMultiset {
private:
	std::multiset<T> storage;
	SMcache<T> cache;

	struct Sum { // struct for get sum
		T sum;
		Sum() { sum = 0; }
		void operator() (T n) { sum += n; }
	};

	//for examples ------------------->
	std::multiset<T> setExample = { 1, 10, -3, 5 };
	std::vector<T> vectorExample = { 1, 10, -3, 5 };
	std::list<T> listExample = { 1, 10, -3, 5 };
	// <-----------------------------
public:
	StatisticMultiset();
	~StatisticMultiset();

	// Add number in storage --------->
	void AddNum(const T num);

	void AddNum(const std::multiset<T> & numbers);

	void AddNum(const std::vector<T> & numbers);

	void AddNum(const std::list<T> & numbers);

	void AddNum(const StatisticMultiset & a_stat_set);

	void AddNumFromFile(const char * filename);
	// <--------------------
	
	T GetMax() const; // Max of storage
	
	T GetMin() const; // Min of storage
	
	float GetAvg() const; // Average of storage

	int counterUnder(float threshold, const std::multiset<T> & ms) const;

	int counterAbove(float threshold, const std::multiset<T> & ms) const;
	
	int GetCountUnder(float threshold) const; // Count less than threshold
	
	int GetCountAbove(float threshold) const; // Count more than threshold

	void menuAddNum();

	void menu();
};