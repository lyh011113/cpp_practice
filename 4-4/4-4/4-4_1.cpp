#include <iostream>

class A {
    int x;

public:
    A(int c) : x(c) {}
    A(const A& a) {
        x = a.x;
        std::cout << "복사 생성" << std::endl;
    }
};

class B {
    A a;

public:
    B(int c) : a(c) {}
    B(const B& b) : a(b.a) {}//b 변수 a를 대입, 복사
    A get_A() {
        A temp(a); // 복사 1, temp 이름으로 a 복사 
        return temp;// 임시 객체 리턴 ->temp의 정보
    }
};

int main() {
    B b(10); //a(10) -> x(10) 

    std::cout << "---------" << std::endl;
    A a1 = b.get_A(); // 복사2 temp(a) 
}