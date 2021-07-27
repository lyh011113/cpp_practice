#include <iostream>
#include <cmath>
#include <random>

class Point {
    int x, y;

public:
    Point(int pos_x, int pos_y) {
        x = pos_x;
        y = pos_y;
    }
    int GetX() const { return x; }
    int GetY() const { return y; }
};

class Geometry {
    int num_points;
    // �� 100���� �����ϴ� �迭
    Point* point_array[100];

public:
    Geometry() {
        num_points = 0;
    }
    ~Geometry() {
        for (int i = 0; i < num_points; i++) {
            delete point_array[i];
        }
    }

    void AddPoint(const Point& point) {
        point_array[num_points++] = new Point(point.GetX(), point.GetY());
    }

    // ��� ���� ���� �Ÿ��� ����ϴ� �Լ� �Դϴ�.
    void PointDistance();

    // ��� ������ �մ� ������ ���� ������ ���� ������ִ� �Լ��Դϴ�.
    // ���������� ������ �� ���� �մ� ������ �������� f(x, y) = ax+by+c = 0
    // �̶�� �� �� ������ �ٸ� �� �� (x1, y1)�� (x2, y2)�� f(x, y) = 0�� ��������
    // ���� �ٸ� �κп� ���� ������ f(x1, y1) * f(x2, y2) <= 0 �̸� �˴ϴ�.

    int factorial(int num) {
        if (num <= 1) { return 1; }
        return num * factorial(num - 1);
    }
    void PrintNumMeets();
};


void Geometry::PointDistance() {
    int distance = 0;
    int sum_distance = 0;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    // xx: x1�� x2�� ���̸� ������ �� | yy: y1�� y2�� ���̸� ������ ��
    int xx = 0, yy = 0;
    Point* point1 = NULL, * point2 = NULL;

    for (int i = 0; i < num_points - 1; i++) {
        for (int j = i + 1; j < num_points; j++) {
            point1 = point_array[i];
            point2 = point_array[j];

            x1 = point1->GetX(), x2 = point2->GetX();
            y1 = point1->GetY(), y2 = point2->GetY();

            xx = pow(x1 - x2, 2);
            yy = pow(y1 - y2, 2);

            distance = pow(xx + yy, 0.5);

            std::cout << "Point[" << i + 1 << "] : (" << x1 << ", " << y1 << ")" << std::endl;
            std::cout << "Point[" << j + 1 << "] : (" << x2 << ", " << y2 << ")" << std::endl;
            std::cout << "Point[" << i + 1 << "]�� Point[" << j + 1 << "]�� �Ÿ� : " << distance << std::endl;
            std::cout << std::endl;

            sum_distance += distance;
        }
    }

    std::cout << "��� ���� ���� �Ÿ��� ������ " << sum_distance << " �̴�." << std::endl;
}

void Geometry::PrintNumMeets() {
    // ���� �� �ִ� ������ �� {(num_points)! / 2} ���̴�.
    // ������ ������ ��� a, b, c�� 0���� �ʱ�ȭ
    // ������ ������ : a*x + b*y + c = 0    
    const int NUM_OF_LINES = (factorial(num_points) / 2);
    std::cout << "������ ������ " << NUM_OF_LINES << "�� �Դϴ�." << std::endl;

    // ù��°[0] : ������ ������ ��� a
    // �ι�°[1] : ������ ������ ��� b
    // ����°[2] : ������ ������ ��� c
    // �׹�°[3] : ������ �������� ����� point1�� index
    // �ټ���°[4] : ������ �������� ����� point2�� index
    int coefficients[100000][5] = { 0, };

    if (NUM_OF_LINES > 100000) {
        std::cout << "������ ������ �ʹ� ���� ����� �Ұ��մϴ�." << std::endl;
        return;
    }

    // ������ ������ ��� a, b, c�� ���Ѵ�.
    int x1 = 0, y1 = 0;
    int x2 = 0, y2 = 0;
    int nth_line = 0;
    for (int i = 0; i < num_points - 1; i++) {
        for (int j = 0; j < num_points; j++) {
            x1 = point_array[i]->GetX();
            y1 = point_array[i]->GetY();
            x2 = point_array[j]->GetX();
            y2 = point_array[j]->GetY();

            coefficients[nth_line][0] = y2 - y1; // a
            coefficients[nth_line][1] = x1 - x2; // b
            coefficients[nth_line][2] = x1 * y1 - 2 * x1 * y2 + x2 * y2; // c
            coefficients[nth_line][3] = i;
            coefficients[nth_line][4] = j;
            nth_line++;
        }
    }


    // ������ ������ ����Ʈ�� ������ ���Ѵ�.
    int sum_of_meets = 0;
    for (int i = 0; i < NUM_OF_LINES; i++) {
        for (int j = 0; j < num_points - 1; j++) {
            for (int k = j + 1; k < num_points; k++) {
                // ������ �������� ���� ����Ʈ�� �Ѿ��
                if (coefficients[i][3] == j || coefficients[i][3] == k) {
                    continue;
                }

                x1 = point_array[j]->GetX();
                y1 = point_array[j]->GetY();
                x2 = point_array[k]->GetX();
                y2 = point_array[k]->GetY();

                // �� ����Ʈ�� ���� �������� ���� �ݴ�鿡 �ִ��� Ȯ��
                if ((coefficients[i][0] * x1 + coefficients[i][1] * y1 + coefficients[i][2]) * (coefficients[i][0] * x2 + coefficients[i][1] * y2 + coefficients[i][2]) <= 0) {
                    sum_of_meets++;
                }
            }
        }
    }

    std::cout << std::endl;
    std::cout << "������ ������ " << NUM_OF_LINES << "�� �Դϴ�." << std::endl;
    std::cout << "������ �������� �����ϴ� ���� ������ " << sum_of_meets << "�� �̴�." << std::endl;
}

int main() {
    // �õ� ���� ��� ���� random_device ����
    std::random_device rd;

    // random_device�� ���� ���� ���� ������ �ʱ�ȭ
    std::mt19937 gen(rd());

    // 0���� 99���� �յ��ϰ� ��Ÿ���� ���� ���� �����ϱ� ���� �յ� ���� ����
    std::uniform_int_distribution<int> dis(0, 99);

    // point ����
    const int NUM_OF_POINT = 8;

    Geometry geometry;

    for (int i = 0; i < NUM_OF_POINT; i++) {
        // std::cout << "���� : " << dis(gen) <<", " << dis(gen) <<std::endl;
        Point point(dis(gen), dis(gen));
        geometry.AddPoint(point);
    }

    geometry.PointDistance();
    geometry.PrintNumMeets();

    return 0;
}

