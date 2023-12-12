//Tim hinh chieu cua 1 diem len duong thang
//0 0 3 4
//1
//2 5
//Result: 
//3.12
//4.16

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

struct Point{
	double x, y;
	Point (double x=0, double y=0): x(x), y(y) {}
	Point operator + (Point p) {
		return Point(x + p.x, y + p.y);
	}
	Point operator - (Point p) {
		return Point(x - p.x, y - p.y);
	}
	Point operator * (double a) {
		return Point(x*a, y*a);
	}
	Point operator / (double a) {
		return  Point(x/a, y/a);
	}
	double abs() {
		return sqrt(x*x + y*y);
	}
};
typedef Point Vector;

struct Segment{
	Point p1, p2;
};
typedef Segment Line;

double dot(Vector a, Vector b){
	return a.x*b.x + a.y*b.y;
}

double cross(Vector a, Vector b){
	return a.x*b.y - a.y*b.x;
}

Point project(Segment s, Point p) { //Chung minh bang cach chieu len truc Ox
	Vector base = s.p2 - s.p1;
	double r = dot(p - s.p1, base) / (base.abs()*base.abs());
	return s.p1 + base * r;
}


int main(){
	int k=0;
	int x=0, y=0, m=0, n=0;
	scanf("%d %d %d %d", &x, &y, &m, &n);
	Point X(x, y), Y(m,n);
	Segment XY; XY.p1 = X; XY.p2 = Y;
	Point Z;
	vector<Point> V;
	scanf("%d", &k);
	for (int i=0; i<k; i++){
		scanf("%d %d", &x, &y);
		Z.x = x, Z.y = y;
		V.push_back(Z);
	}
	for (int i=0; i<k; i++){
		Point W = project(XY, V[i]);
		printf("%f %f\n", W.x, W.y);
	}
	return 0;	
}
