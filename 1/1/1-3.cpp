#include<iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {

	/*int i;
	char c;
	double d;
	float f;
	int number_of_people;
	double interest_rate;

	int arr[10];//주소값 배열
	int* parr = arr; //주소 parr에 배열 arr의 주소값을 넣는다

	int* pi = &i;//i의 주소값을 포인터 pi에 넣는다.

	for (i = 0; i < 10; i++) {
	
		std::cout << i << std::endl;
	
	}*/
	
	/*int i, sum = 0;
	for (i = 1; i <= 10; i++) {
		sum += i;
	}
	std::cout << "합은 :" << sum << std::endl;
	*/

	/*int i = 1, sum = 0;
	while (i <= 10)//i가 10보다 작거나 같은 동안에
	{
		sum += i;
		i++;
	}

	std::cout << "합은 :" << sum << std::endl;
	*/

	/*
	int lucky_number = 3;
	std::cout << "내 비밀의 수를 맞추어 보세요~" << std::endl;
	int user_input;

	while (1) {
		std::cout << "입력 :";

		std::cin >> user_input;
		if (lucky_number == user_input) {
			std::cout << "맞추셨습니다~~" << std::endl;
			break;
		}
		else {
			std::cout << "다시 생각해보세요~" << std::endl;
		}
		
	}
	*/

	int user_input;
	cout << "저의 정보를 표시해줍니다" << endl;
	cout << "1. 이름" << endl;
	cout << "2. 나이" << endl;
	cout << "3. 성별" << endl;
	cin >> user_input;

	switch (user_input) {
	
	case 1:
		cout << "이요한 !" << endl;
		break;
	case 2:
		cout << "21 살" << endl;
		break;
		
	case 3:
		cout << "남자" << endl;
		break;

	default:
		cout << "궁금한게 없군요~" << endl;
		break;
	}

	return 0;
}