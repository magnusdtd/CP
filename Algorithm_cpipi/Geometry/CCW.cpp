//CCW = Counter-Clockwise
//0 0 2 0
//5
//-1 1
//-1 -1
//-1 0
//0 0
//3 0
//Result:
//COUNTER_CLOCKWISE
//CLOCKWISE
//ONLINE_BACK
//ON_SEGMENT
//ONLINE_FRONT

#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
#define EPS (1e-10)
#define equals(a, b) (fabs((a)-(b)) < EPS)
static const int COUNTER_CLOCKWISE = -1;
static const int CLOCKWISE = 1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

struct Point {
	double x, y;
	Point(double x=0, double y=0): x(x), y(y) {}
	Point operator + (Point p) {
		return Point(x+p.x, y+p.y);
	}
	Point operator - (Point p) {
		return Point(x-p.x, y-p.y);
	}
	Point operator * (double a) {
		return Point(x*a, y*a);
	}
	Point operator / (double a) {
		return Point(x/a, y/a);
	}
	bool operator == (Point p) {
		return equals(x, p.x) && equals(y, p.y);
	}
	double abs(){
		return sqrt(x*x+y*y);
	}
};
typedef Point Vector;
struct Segment {
	Point p1, p2;
};
typedef Segment Line;
double dot(Vector a, Vector b){		//Tich vo huong
	return a.x*b.x + a.y*b.y;
}
double cross(Vector a, Vector b){	//Tich huu huong
	return a.x*b.y - a.y*b.x;
}

int CCW(Point p0, Point p1, Point p2){
	Vector a = p1 - p0;
	Vector b = p2 - p0;
	if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
	if (cross(a, b) <-EPS) return CLOCKWISE;
	if (dot(a, b) < -EPS) return ONLINE_BACK;
	if (a.abs() < b.abs()) return ONLINE_FRONT;
	return ON_SEGMENT;
}

int main(){
	int k=0;
	int x=0, y=0, m=0, n=0;
	vector<Point> V;
	scanf("%d %d %d %d", &x, &y, &m, &n);
	Point X0(x, y), X1(m, n);
	scanf("%d", &k);
	for (int i=0; i<k; i++){
		scanf("%d %d", &x, &y);
		Point X2(x, y);
		V.push_back(X2);
	}
	
	for (int i=0; i<k; i++){
		int ans = CCW(X0, X1, V[i]);
		if (ans == -1) printf("COUNTER_CLOCKWISE\n");
		if (ans == 1) printf("CLOCKWISE\n");
		if (ans == 2) printf("ONLINE_BACK\n");
		if (ans == -2) printf("ONLINE_FRONT\n");
		if (ans == 0) printf("ON_SEGMENT\n");
	}
	return 0;
}
