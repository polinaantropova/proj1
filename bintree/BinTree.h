#pragma once

class BinTree {
private:

	struct Node {
		//указатели
		Node* left;
		Node* right;
		Node* parent;
		//данные в узле 
		struct Element {
		} data;

		Node(const Element& X) : right(nullptr), left(nullptr), parent(nullptr), data(X) {}
		~Node() {
			if (left) delete left;
			if (right) delete right;
			left = right = parent = nullptr;
		}
	};
	Node* root;
	unsigned int count;
public:
	BinTree() : root(nullptr), count(0) {}
	~BinTree() {
		if (root)
			delete root;
		root = nullptr;
	}
	unsigned int size()const { return count; }
	void clear() {
		if (root) delete root;
		root = nullptr;
	}
};
