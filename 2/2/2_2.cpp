#include<iostream>



int& function() { //int & ref=a;
	int a = 2;
	return a; 
}

int& function1(int& a) { //int&a = d -> int &ref = a -> 최종적으로 d가 살아 있음
	a = 5;
	return a;
}


int main() {
	int b = function();// int b = a; 근데 a가 소멸
	b = 3;


	int d = 2;
	int c = function1(d);
	return 0;

return 0;
}