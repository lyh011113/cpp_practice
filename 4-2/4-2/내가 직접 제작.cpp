#include<iostream>
#include<cmath>
class Point {
	int x, y;
public:
	Point(int pos_x, int pos_y) {
		x = pos_x;
		y = pos_y;
	}
	int getX() const { return x; }
	int getY() const { return y; }
};

class Geometry {

	Point* point_array[100]; //Ŭ���� Point�� ���� �ּ� ��
	int num_points;

public:
	Geometry() { num_points = 0; }


	void AddPoint(const Point& point) {
		point_array[num_points++] = new Point(point.getX(), point.getY());// Ŭ����Point���� �����Ͽ� Ŭ���� Point �濡 ���ο� �޸� �Ҵ��� �ּҰ� ����
	}

	// ��� ���� ���� �Ÿ��� ����ϴ� �Լ� �Դϴ�.
	void PrintDistance() {

		for (int i = 0; i < num_points; i++) {
			for

		}

	}

	// ��� ������ �մ� ������ ���� ������ ���� ������ִ� �Լ� �Դϴ�.
	// ���������� ������ �� ���� �մ� ������ �������� f(x,y) = ax+by+c = 0
	// �̶�� �� �� ������ �ٸ� �� �� (x1, y1) �� (x2, y2) �� f(x,y)=0 �� ��������
	// ���� �ٸ� �κп� ���� ������ f(x1, y1) * f(x2, y2) <= 0 �̸� �˴ϴ�.
	void PrintNumMeets();

};

int main() {




}