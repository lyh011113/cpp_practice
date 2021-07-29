#include <iostream>

class A {
    int x;

public:
    A(int c) : x(c) {}
    A(const A& a) {
        x = a.x;
        std::cout << "���� ����" << std::endl;
    }
};

class B {
    A a;

public:
    B(int c) : a(c) {}
    B(const B& b) : a(b.a) {}//b ���� a�� ����, ����
    A get_A() {
        A temp(a); // ���� 1, temp �̸����� a ���� 
        return temp;// �ӽ� ��ü ���� ->temp�� ����
    }
};

int main() {
    B b(10); //a(10) -> x(10) 

    std::cout << "---------" << std::endl;
    A a1 = b.get_A(); // ����2 temp(a) 
}