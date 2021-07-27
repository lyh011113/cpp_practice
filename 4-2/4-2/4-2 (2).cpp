#include <iostream>
#include <cmath>

class Point {
	int x, y;

public:
	Point(int pos_x, int pos_y) {
		x = pos_x;
		y = pos_y;
	}

	int GetX() { return x; }
	int GetX() const { return x; }
	int GetY() { return y; }
	int GetY() const { return y; }
};

class Geometry {
	Point* point_array[100];	// �� 100���� �����ϴ� �迭
	int num_points;
public:
	Geometry() {
		num_points = 0;
	}

	void AddPoint(const Point& point) { //��� Point Ŭ������ � �ν��Ͻ��� �ּ� -> �迭�� �ּ�
		point_array[num_points++] = new Point(point.GetX(), point.GetY());
	}

	// ��� ���� ���� �Ÿ��� ����ϴ� �Լ��Դϴ�.
	void PrintDistance();

	// ��� ������ �մ� ������ ���� ������ ���� ������ִ� �Լ��Դϴ�.
	void PrintNumMeets();

	// point1�� point2�� �մ� ������ �����Ŀ� insert�� ������� �� ���
	int InsertLineToPoint(const Point* point1, const Point* point2, const Point* insert);
};

void Geometry::PrintDistance() {
	for (int i = 0; i < num_points - 1; i++) {
		for (int j = i + 1; j < num_points; j++) {
			std::cout << i + 1 << "��° ���� " << j + 1 << "��° �� ������ �Ÿ��� "
				<< sqrt(pow(point_array[i]->GetX() - point_array[j]->GetX(), 2) + pow(point_array[i]->GetY() - point_array[j]->GetY(), 2))
				<< "�Դϴ�." << std::endl;
		}
	}
}

int Geometry::InsertLineToPoint(const Point* point1, const Point* point2, const Point* insert) {
	return (point1->GetX() - point2->GetX()) * (insert->GetX() - point1->GetX()) - (point1->GetY() - point2->GetY()) * (insert->GetY() - point1->GetY());
}

void Geometry::PrintNumMeets() {
	int cnt = 0;

	if (num_points <= 3) {
		std::cout << "���� �����Ͽ� ������ �����ϴ�." << std::endl;
		return;
	}


	for (int i = 0; i < num_points - 3; i++) {
		for (int j = i + 1; j < num_points - 2; j++) {
			for (int k = j + 1; k < num_points - 1; k++) {
				for (int l = k + 1; l < num_points; l++) {
					if (InsertLineToPoint(point_array[i], point_array[j], point_array[k]) * InsertLineToPoint(point_array[i], point_array[j], point_array[l]) <= 0)
						cnt++;
				}
			}
		}
	}

	std::cout << "������ �� " << cnt << "�� �Դϴ�." << std::endl;
}
