#include<iostream>


class Date {
	int year_;
	int month_;
	int day_;

public:
	void SetDate(int year, int month, int date);
	void AddDay(int inc);
	void AddMonth(int inc);
	void AddYear(int inc);

	int GetCurrentMonthTotalDays(int year, int month);//해당 월의 총 일 수
	
	void ShowDate();

	Date(int year, int month, int day) { // 생성자
		year_ = year;
		month_ = month;
		day_ = day;
	}

	Date() = default;  // 디폴트 생성자를 정의해라

	Date() { //디폴트 생성자
		year_ = 2012;
		month_ = 7;
		day_ = 12;
	}

	
};
void Date::SetDate(int year, int month, int day) {
	year_ = year;
	month_ = month;
	day_ = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month) {

	static int month_day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month != 2) {
		return month_day[month - 1]; 
	}
	else if(year % 4 == 0 && year % 100 != 0) {
		return 29;
	}
	else {
		return 28;
	}

}



void Date::AddDay(int inc) {

	//현재 달의 총 일 수
	while (true) {

		int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

		// 같은 달 안에 들어온다면
		if (day_ + inc <= current_month_total_days) {
			day_ += inc;
			return;
		}
		else {
			inc -= (current_month_total_days - day_ + 1);
			day_ = 1;
			AddMonth(1);
		}

	}

}

void Date::AddMonth(int inc) {
	AddYear((inc + month_ - 1) / 12);
	month_ = month_ + inc % 12;
	month_ = (month_ == 12 ? 12 : month_ % 12); //달이 12 면 12 아니면 12 나머지
}

void Date::AddYear(int inc) { year_ += inc; }
void Date::ShowDate() {
	std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
		<< " 일 입니다 " << std::endl;

}

int main_01(){


	Date day(2011, 3, 1);
	day.ShowDate();
	// 객체를 초기화 하는 역할을 하기 때문에 리턴값이 없다!
	/* 클래스 이름  ( 인자 ) {} */

	Date day(2011, 3, 1);         // 암시적 방법 (implicit) **선호**
	Date day = Date(2012, 3, 1);  // 명시적 방법 (explicit)

	Date day2;//디폴트 생성자
	Date day3();//초기화가 아니라 함수 소환
	// 디폴트나 생성자는 오버로드 가능

	day.AddDay(30);
	day.ShowDate();

	day.AddDay(2000);
	day.ShowDate();

	day.SetDate(2012, 1, 31);  // 윤년
	day.AddDay(29);
	day.ShowDate();

	day.SetDate(2012, 8, 4);
	day.AddDay(2500);
	day.ShowDate();
	return 0;

}