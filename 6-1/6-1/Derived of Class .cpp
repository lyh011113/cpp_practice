#include <iostream>
#include <string>

class Base {
protected:
    std::string parent_string;

public:
    Base() : parent_string("���") { std::cout << "��� Ŭ����" << std::endl; }

    void what() { std::cout << parent_string << std::endl; }
};
class Derived : public Base {
    std::string child_string;

public:
    Derived() : Base(), child_string("�Ļ�") {
        std::cout << "�Ļ� Ŭ����" << std::endl;

        // �׷��ٸ� ���� private �� Base ��
        // parent_string �� ������ �� ������?
        parent_string = "�ٲٱ�";
    }

    void what() { std::cout << child_string << std::endl; }
};