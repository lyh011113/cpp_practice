#include <iostream>

class MyString {
    char* string_content;  // ���ڿ� �����͸� ����Ű�� ������
    int string_length;     // ���ڿ� ����

    int memory_capacity;

public:
    // capacity ��ŭ �̸� �Ҵ���.
   explicit MyString(int capacity);

    // ���ڿ��� ���� ����
    MyString(const char* str);

    // ���� ������
    MyString(const MyString& str);

    ~MyString();

    int length() const;

    void read() const
        ;
};

void MyString::read() const{
    std::cout << string_content;
}

MyString::MyString(int capacity) {
    string_content = new char[capacity];
    string_length = 0;
    memory_capacity = capacity;
    std::cout << "Capacity : " << capacity << std::endl;
}

MyString::MyString(const char* str) {
    string_length = 0;
    while (str[string_length++]) {
    }

    string_content = new char[string_length];
    memory_capacity = string_length;

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void DoSomethingWithString(MyString s) {
    // Do something...
}

int main() {
    DoSomethingWithString("string");  // ????
    

}