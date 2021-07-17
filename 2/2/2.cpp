#include <iostream>

int change_val(int* p) {//포인터 사용
	*p = 3;

	return 0;
}

int change_val2(int& p) {//이상적인 참조자 활용, int& p = number;
	p = 3;

	return 0;
}
int main_01() {
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

			int x; // 참조자의 활용
			int& y = x;
			int& z = y;
			x = 1;
			std::cout << "x :" << x << "y :" << y << "z :" << z << std::endl;
		
			y = 2;
			std::cout << "x :" << x << "y :" << y << "z :" << z << std::endl;

			z = 3;
			std::cout << "x :" << x << "y :" << y << "z :" << z << std::endl;



			int arr[3] = { 1, 2, 3 }; // 배열의 참조자
			int(&ref)[3] = arr;

			ref[0] = 2;
			ref[1] = 3;
			ref[2] = 1;

			std::cout << arr[0] << arr[1] << arr[2] << std::endl;

			const int& refr = 4; // 리터럴 상수의 참조자
			
			int f = refr;

		return 0;
	
}