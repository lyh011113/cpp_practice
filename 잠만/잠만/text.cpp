#include<iostream>

int main(){


	int value = 5; 
	
	const int& ref = value; // create const reference to variable value value = 6; // okay, 

	value = 6;

	std::cout << value << ref;

}