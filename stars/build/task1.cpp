#include <iostream>
void task1(int n) {
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}
void task2(int n) {
	for (int i = 0; i <= n; ++i) {
		for (int j = n; j > i; --j) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}

}
void task3(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = n-i; j > 0; --j) {
			std::cout << " ";
		} 
		for (int k = 0; k < i+1; ++k) {
			std::cout << "*";

		}
		std::cout << std::endl;
	} 
}
void task4 (int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < n-i; ++j) {
			std::cout << " ";
		}
		for (int k = 0; k < 2*i-1; ++k) {
			std::cout << "*";

		}
		std::cout << std::endl;
	}
	for (int i = n-1; i >=1; --i) {
		for (int j = 0; j < n - i; ++j) {
			std::cout << " ";
		}
		for (int k = 0; k < 2 * i - 1; ++k) {
			std::cout << "*";

		}
		std::cout << std::endl;
	}
}

int main()

{
	int n = -1;
	
	do {
		std::cout << "Input n ";
		std::cin >> n;
	} while (n < 0);
	task1(n);
	std::cout << std::endl;
	task2(n);
	std::cout << std::endl;
	task3(n);
	std::cout << std::endl;
	task4(n);
}

