#pragma once
#include <map>

template<class T>
class SMcache {
private:
	mutable bool _wasChangedAvg = true;
	mutable bool _wasChangedAbove = true;
	mutable bool _wasChangedUnder = true;
	mutable std::map<T, int> above;
	mutable std::map<T, int> under;
	mutable float avg;
public:
	SMcache();
	~SMcache();
	bool wasChangedAvg() const;
	bool wasChangedUnder() const;
	bool wasChangedAbove() const;
	void setAvg(const float _avg) const;
	float getAvg() const;
	void reset();
	void setUnder(T _num, int count) const;
	int getUnder(T _num) const;
	bool isHaveUnder(T _num) const;
	bool isHaveAbove(T _num) const;
	void setAbove(T _num, int count) const;
	int getAbove(T _num) const;
};