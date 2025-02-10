#include <iostream>
#include <vector>
#include <algorithm>
class Point {

public:
	int x;
	int y;
	Point(int _x, int _y) {
		x = _x;
		y = _y;
	}
};

bool compare(const Point& a, const Point& b) {
	if (a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}
int main() {
	int N;
	int x, y;
	std::cin >> N;

	std::vector<Point> points;

	for (int i = 0; i < N; i++) {
		std::cin >> x >> y;
		Point point(x, y);
		points.push_back(point);
	}

	std::sort(points.begin(), points.end(), compare);

	for (int i = 0; i < N; i++) {
		printf("%d %d\n", points[i].x, points[i].y);
	}
}