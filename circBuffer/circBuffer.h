#pragma once
#include "Arr.h"
#include "marker.h"

template<typename T>
class circBuf {
private:
	Arr <T> storage;
	marker<T> cur_pos;
public:
	circBuf(size_t size) {
		Arr<T> storage(size);
		marker<T> cur_pos(&(storage[0]));
	}
	void put(T val) {
		
		storage.replaceElement((cur_pos.get_pos()-&(storage[0])) %storage.getSize(), val);
		++cur_pos;
	};
	const T& get ()const {
			return storage[cur_pos % storage.getSize()];
		
	};
};
