#include<iostream>

class string {
	char* str;
	int len;

public:
	string(char c, int n);  // ���� c �� n �� �ִ� ���ڿ��� ����
	string(const char* s);
	string(const string& s);
	~string();

	void add_string(const string& s);   // str �ڿ� s �� ���δ�.
	void copy_string(const string& s);  // str �� s �� �����Ѵ�.
	int strlen();                       // ���ڿ� ���� ����
};

string::string(char c, int n) {

	len = n;
	str = new char[n + 1];

	for (int i = 0; i < n; i++) {
		str[i] = c;
	}
}

string::string(const string& s) {}

string::string(const char* s) {}

string::~string() {}

void string::add_string(const string& s) {}

void string::copy_string(const string& s){}

int string::strlen() {}

int main(){



return 0;
}