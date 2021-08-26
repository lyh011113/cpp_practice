#include<iostream>
#include<sstream>

double to_number(std::string s){

	std::istringstream ss(s);
	double x;

	ss >> x;
	return x;
}

int main_08() {
	std::cout << "º¯È¯:: 1 + 2 = " << to_number("1") + to_number("2") << std::endl;

	return 0;
}