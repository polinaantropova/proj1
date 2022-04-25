#pragma once
#include "Arr.h"

template<typename T>
class circBuf {
private:
	Arr <T> storage;
	//long long int cur_pos;
  
public:
	circBuf(size_t raz):storage(raz) {}
	void put(const& T val) {
		storage.addElement(const& T val);
	};
	const T& get (size_t index )const {
		if (index >= 0)
			return storage[index % raz];
		else
			throw "index < 0";
	};
};
