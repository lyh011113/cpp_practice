#include <iostream>

int change_val(int* p) {
	*p = 3;

	return 0;
}

int change_val2(int& p) {
	p = 3;

	return 0;
}
int main() {
	int number = 5;

	std::cout << number << std::endl;
	change_val(&number);
	std::cout << number << std::endl;


		int a = 3;
		int& another_a = a; // 또다른 이름 이라고 컴파일러에게 알려주는 것

		another_a = 5;
		std::cout << "a : " << a << std::endl;
		std::cout << "another_a : " << another_a << std::endl;


		
			int number2 = 5;

			std::cout << number2 << std::endl;
			change_val2(number2); //int& p = number2
			std::cout << number2 << std::endl;
		

		return 0;
	
}