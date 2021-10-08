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

int main()

{
	int n=-1;
	std::cout << "Input n ";
	do {
		std::cin >> n ;
	} while (n < 0) ;
	task2(n);
} 

