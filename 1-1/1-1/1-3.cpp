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

	int arr[10];//�ּҰ� �迭
	int* parr = arr; //�ּ� parr�� �迭 arr�� �ּҰ��� �ִ´�

	int* pi = &i;//i�� �ּҰ��� ������ pi�� �ִ´�.

	for (i = 0; i < 10; i++) {
	
		std::cout << i << std::endl;
	
	}*/
	
	/*int i, sum = 0;
	for (i = 1; i <= 10; i++) {
		sum += i;
	}
	std::cout << "���� :" << sum << std::endl;
	*/

	/*int i = 1, sum = 0;
	while (i <= 10)//i�� 10���� �۰ų� ���� ���ȿ�
	{
		sum += i;
		i++;
	}

	std::cout << "���� :" << sum << std::endl;
	*/

	/*
	int lucky_number = 3;
	std::cout << "�� ����� ���� ���߾� ������~" << std::endl;
	int user_input;

	while (1) {
		std::cout << "�Է� :";

		std::cin >> user_input;
		if (lucky_number == user_input) {
			std::cout << "���߼̽��ϴ�~~" << std::endl;
			break;
		}
		else {
			std::cout << "�ٽ� �����غ�����~" << std::endl;
		}
		
	}
	*/

	int user_input;
	cout << "���� ������ ǥ�����ݴϴ�" << endl;
	cout << "1. �̸�" << endl;
	cout << "2. ����" << endl;
	cout << "3. ����" << endl;
	cin >> user_input;

	switch (user_input) {
	
	case 1:
		cout << "�̿��� !" << endl;
		break;
	case 2:
		cout << "21 ��" << endl;
		break;
		
	case 3:
		cout << "����" << endl;
		break;

	default:
		cout << "�ñ��Ѱ� ������~" << endl;
		break;
	}

	return 0;
}