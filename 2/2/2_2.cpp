#include<iostream>



int& function() { //int & ref=a;
	int a = 2;
	return a; 
}

int& function1(int& a) { //int&a = d -> int &ref = a -> ���������� d�� ��� ����
	a = 5;
	return a;
}


int main() {
	int b = function();// int b = a; �ٵ� a�� �Ҹ�
	b = 3;


	int d = 2;
	int c = function1(d);
	return 0;

return 0;
}