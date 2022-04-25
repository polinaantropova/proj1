#pragma once

template <typename T>
class Stack {
private:
	Arr<T> m_base;
public:
	Stack() {}
	void push(const T& val) {
		m_base.addElement(val);
	};
	const T& get() {
		if (m_base.getSize()) {
			return m_base[m_base.getSize() - 1];
		}
		else {
			throw "stack is empty!!!";
		}
	};

	void pop() {
		if (m_base.getSize()) {
			m_base.removeElement(m_base.getSize() - 1);
		}
		else {
			throw "stack is empty!!!";
		}
	};
};
