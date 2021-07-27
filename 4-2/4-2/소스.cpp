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
    // 점 100개를 보관하는 배열
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

    // 모든 점들 간의 거리를 출력하는 함수 입니다.
    void PointDistance();

    // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수입니다.
    // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x, y) = ax+by+c = 0
    // 이라고 할 때 임의의 다른 두 점 (x1, y1)과 (x2, y2)가 f(x, y) = 0을 기준으로
    // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.

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

    // xx: x1과 x2의 차이를 제곱한 것 | yy: y1과 y2의 차이를 제곱한 것
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
            std::cout << "Point[" << i + 1 << "]과 Point[" << j + 1 << "]의 거리 : " << distance << std::endl;
            std::cout << std::endl;

            sum_distance += distance;
        }
    }

    std::cout << "모든 점들 간의 거리의 총합은 " << sum_distance << " 이다." << std::endl;
}

void Geometry::PrintNumMeets() {
    // 만들 수 있는 직선은 총 {(num_points)! / 2} 개이다.
    // 직선의 방정식 계수 a, b, c를 0으로 초기화
    // 직선의 방정식 : a*x + b*y + c = 0    
    const int NUM_OF_LINES = (factorial(num_points) / 2);
    std::cout << "직선의 개수는 " << NUM_OF_LINES << "개 입니다." << std::endl;

    // 첫번째[0] : 직선의 방정식 계수 a
    // 두번째[1] : 직선의 방정식 계수 b
    // 세번째[2] : 직선의 방정식 계수 c
    // 네번째[3] : 직선의 방정식을 만드는 point1의 index
    // 다섯번째[4] : 직선의 방정식을 만드는 point2의 index
    int coefficients[100000][5] = { 0, };

    if (NUM_OF_LINES > 100000) {
        std::cout << "직선의 개수가 너무 많아 계산이 불가합니다." << std::endl;
        return;
    }

    // 직선의 방정식 계수 a, b, c를 구한다.
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


    // 직선이 만나는 포인트의 개수를 구한다.
    int sum_of_meets = 0;
    for (int i = 0; i < NUM_OF_LINES; i++) {
        for (int j = 0; j < num_points - 1; j++) {
            for (int k = j + 1; k < num_points; k++) {
                // 직선의 방정식을 세운 포인트는 넘어가기
                if (coefficients[i][3] == j || coefficients[i][3] == k) {
                    continue;
                }

                x1 = point_array[j]->GetX();
                y1 = point_array[j]->GetY();
                x2 = point_array[k]->GetX();
                y2 = point_array[k]->GetY();

                // 두 포인트가 직선 기준으로 서로 반대면에 있는지 확인
                if ((coefficients[i][0] * x1 + coefficients[i][1] * y1 + coefficients[i][2]) * (coefficients[i][0] * x2 + coefficients[i][1] * y2 + coefficients[i][2]) <= 0) {
                    sum_of_meets++;
                }
            }
        }
    }

    std::cout << std::endl;
    std::cout << "직선의 개수는 " << NUM_OF_LINES << "개 입니다." << std::endl;
    std::cout << "직선의 방정식이 교차하는 점의 개수는 " << sum_of_meets << "개 이다." << std::endl;
}

int main() {
    // 시드 값을 얻기 위한 random_device 생성
    std::random_device rd;

    // random_device를 통해 난수 생성 엔진을 초기화
    std::mt19937 gen(rd());

    // 0부터 99까지 균등하게 나타나는 난수 열을 생성하기 위해 균등 분포 정의
    std::uniform_int_distribution<int> dis(0, 99);

    // point 개수
    const int NUM_OF_POINT = 8;

    Geometry geometry;

    for (int i = 0; i < NUM_OF_POINT; i++) {
        // std::cout << "난수 : " << dis(gen) <<", " << dis(gen) <<std::endl;
        Point point(dis(gen), dis(gen));
        geometry.AddPoint(point);
    }

    geometry.PointDistance();
    geometry.PrintNumMeets();

    return 0;
}

