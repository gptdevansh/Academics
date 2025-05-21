/* Devansh (202308503) */
#include <iostream>
#include <cmath>
#include <vector>

struct Point {
    int x, y;
    Point(int X = 0, int Y = 0) : x(X), y(Y) {}

    friend std::istream& operator>>(std::istream& is, Point& P);
    friend std::ostream& operator<<(std::ostream& os, const Point& P);

    double dist(const Point& P) const {
        return sqrt((x - P.x) * (x - P.x) + (y - P.y) * (y - P.y));
    }
};

std::istream& operator>>(std::istream& is, Point& P) {
    is >> P.x >> P.y;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Point& P) {
    os << "( " << P.x << ", " << P.y << " )";
    return os;
}

// Find points of convex_hull using brute force method
void get_convex_hull(Point points[], int n) {
    std::vector<std::pair<Point, Point>> convex_hull;

    for (int i = 0; i < n - 1; ++i) {
        Point A = points[i];

        for (int j = i + 1; j < n; ++j) {
            Point B = points[j];

            /*
            equation of line :-
                          (Y2 - Y1)
            => (Y - Y1) = --------- * (X - X1)
                          (X2 - X1)
            => (Y - Y1).(X2 - X1) = (Y2 - Y1).(X - X1)
            => (Y2 - Y1).X + (X1 - X2).Y  = X1.Y2 - X2.Y1 cmp. with (ax + by = c) 
            */
            // Equation of line: a*x + b*y = c
            
            int a = B.y - A.y,
                b = A.x - B.x,
                c = A.x * B.y - B.x * A.y;

            int curr_sign, prev_sign = 2; // 2 means uninitialized
            bool point_same_side = true; // Initialize to true

            for (int k = 0; k < n; ++k) {
                if (k == i || k == j) continue;
                Point C = points[k];

                if (a * C.x + b * C.y < c) curr_sign = -1;
                else if (a * C.x + b * C.y > c) curr_sign = +1;
                else curr_sign = 0;

                if (prev_sign != 2 && curr_sign != 0 && prev_sign != curr_sign) {
                    point_same_side = false;
                    break;
                } else if (prev_sign == 2 && curr_sign != 0) {
                    prev_sign = curr_sign;
                }
            }

            if (point_same_side) {
                convex_hull.push_back({A, B});
            }
        }
    }

    // Print the edges of the convex hull
    std::cout << std::endl << "Edges of Convex HULL = [";
    for (const auto& edge : convex_hull) {
        std::cout << edge.first << " -> " << edge.second << "; ";
    }
    std::cout << "]";
}

int main() {
    int numPoints;
    std::cout << "Enter the number of points: ";
    std::cin >> numPoints;
    Point points[numPoints];

    std::cout << "Enter the points (x y):" << std::endl;
    for (int i = 0; i < numPoints; i++) {
        std::cin >> points[i];
    }

    get_convex_hull(points, numPoints);
    return 0;
}
