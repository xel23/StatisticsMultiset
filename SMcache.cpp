#include "SMcache.h"
#include <iostream>
#include <utility>

template<class T>
SMcache<T>::SMcache()
{
}

template<class T>
SMcache<T>::~SMcache()
{
}

template<class T>
bool SMcache<T>::wasChangedAvg() const
{
	return _wasChangedAvg;
}

template<class T>
bool SMcache<T>::wasChangedUnder() const
{
	return _wasChangedUnder;
}

template<class T>
bool SMcache<T>::wasChangedAbove() const
{
	return _wasChangedAbove;
}

template<class T>
void SMcache<T>::setAvg(const float _avg) const
{
	avg = _avg;
	_wasChangedAvg = false;
}

template<class T>
float SMcache<T>::getAvg() const
{
	return avg;
}

template<class T>
void SMcache<T>::reset()
{
	_wasChangedAvg = true;
	_wasChangedAbove = true;
	_wasChangedUnder = true;
	above.clear();
	under.clear();
}

template<class T>
void SMcache<T>::setUnder(T _num, int count) const
{
	under.insert(std::make_pair(_num, count));
	_wasChangedUnder = false;
}

template<class T>
int SMcache<T>::getUnder(T _num) const
{
	return under[_num];
}

template<class T>
bool SMcache<T>::isHaveUnder(T _num) const
{
	return under.find(_num) != under.end();
}

template<class T>
bool SMcache<T>::isHaveAbove(T _num) const
{
	return above.find(_num) != above.end();
}

template<class T>
void SMcache<T>::setAbove(T _num, int count) const
{
	above.insert(std::make_pair(_num, count));
	_wasChangedAbove = false;
}

template<class T>
int SMcache<T>::getAbove(T _num) const
{
	return above[_num];
}
