//Tim giao diem cua 2 duong tron
//0 0 2
//2 0 2
//Result:
//1 -1,7320508
//1 1.7320508





/*Co bug*/











#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b))<EPS)

struct Point {
	double x, y;
	Point(double x=0, double y=0): x(x), y(y) {
	}
	Point operator + (Point p){
		return Point(x+p.x, y+p.y);
	}
	Point operator - (Point p){
		return Point(x-p.x, y-p.y);
	}
	Point operator * (double a){
		return Point(x*a, y*a);
	}
	Point operator / (double a){
		return Point(x/a, y/a);
	}
	bool operator == (Point p){
        return equals(x,p.x) && equals(y, p.y);
    }
	double abs() {
		return sqrt(x*x + y*y);
	}
	double norm() {
		return x*x + y*y;
	}
};
typedef Point Vector;
struct Segment {
	Point p1, p2;
};
typedef Segment Line;
double dot(Vector a, Vector b){
	return a.x*b.x + a.y*b.y;
}
double cross(Vector a, Vector b){
	return a.x*b.y - a.y*b.x;
}
struct Circle {
	Point I;
	double R; 
};
double arg(Vector p){
	return atan2(p.y, p.x);
}
Vector polar(double a, double theta){ //Phep quay tam O bien diem X(x, 0) thanh X' theo goc quay theta
	return Point(cos(theta)*a, sin(theta)*a);
}
pair<Point, Point> getCrossPointCC(Circle C1, Circle C2){
	double d = (C1.I - C2.I).abs();
	double a = acos((d*d + C1.R*C1.R - C2.R)/(2*d*C1.R));
	double t = arg(C2.I - C1.I);
	return make_pair(C1.I + polar(C1.R, t+a), C1.I + polar(C1.R, t-a));
}
bool isIntersect(Circle C1, Circle C2){
	double C1C2 = (C1.I - C2.I).abs();
	if (C1C2 - abs(C1.R - C2.R) > EPS && C1C2 - abs(C1.R + C2.R) < EPS) return true;
	else return false;
}

int main(){
	Circle C1, C2;
	Point X, Y;
	scanf("%d %d %lf", &C1.I.x, &C1.I.y, &C1.R);
	scanf("%d %d %lf", &C2.I.x, &C2.I.y, &C2.R);
	if (isIntersect(C1, C2)) {
		pair<Point, Point> S = getCrossPointCC(C1, C2);
		printf("%lf %lf\n", S.first.x, S.first.y);
		printf("%lf %lf", S.second.x, S.second.y);
	} else {
		printf("They don't intersect");
	}
	return 0;
}
