#include<iostream>

class Date {
	int year_;
	int month_;  // 1 ���� 12 ����.
	int day_;    // 1 ���� 31 ����.

public:
	void SetDate(int year, int month, int date) {
		year_ = year;
		month_ = month;
		day_ = date;
	}

	void AddDay(int inc) {
		day_ += inc;

		do {
			if (day_ > 28) {
				if (month_ == 2) {
					month_ += 1;
					day_ -= 28;
				}
				else if (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12) {
					if (day_ > 31) {
						month_ += 1;
						day_ -= 31;
					}
					else if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11) {
						if (day_ > 30) {
							month_ += 1;
							day_ -= 30;
						}
					}
				}
			}
		} while (day_ < 29);

	}
	void AddMonth(int inc) {
		month_ += inc;
		do {
			if (month_ > 12) {
				year_ += 1;
				month_ -= 12;
			}
		} while (month_<13);
	}
	void AddYear(int inc) {
		year_ += inc;
	}
	void ShowDate() {

		std::cout << year_ << "�� " << month_ << "�� " << day_ << "�� " << std::endl;

	}
};

int main_1() {




	int i = 1;

	do
	{
		int input = 0;
		std::cout << "1. ��¥ �߰�" << std::endl
			<< "2. �� �߰�" << std::endl
			<< "3. �� �߰�" << std::endl
			<< "4. ����" << std::endl;
		std::cin >> input;
		switch (input) {
		case 1:
			int day = 0;
			std::cout << "�� ���� �߰�? :";
			std::cin >> day;
			Date.AddDay(day)
				break;
		case 2:
			int year = 0;
			std::cout << "�� ���� �߰�? :";
			std::cin >> year;
			break;
		case 3:
			int month = 0;
			std::cout << "�� ���� �߰�? :";
			std::cin >> month;
			break;
		case 4:
			i = 0;
			break;
		}
	} while (i==0);




	return 0;
}