//Tim toa do giao diem cua 1 duong tron voi duong thang
//2 1 1
//2
//0 1 4 1
//3 0 3 3
//Result:
//1 1 3 1
//3 1 3 1

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
Point project(Segment s, Point p) { //Chung minh bang cach chieu len truc Ox
	Vector base = s.p2 - s.p1;
	double r = dot(p - s.p1, base) / (base.norm());
	return s.p1 + base * r;
}	
double getDistanceLP(Point P, Line L){	//Chung minh bang cach dung dien tich cua tam giac
	return abs(cross((P-L.p1), (P-L.p2)))/(L.p1 - L.p2).abs();
}

struct Circle {
	Point I;
	double R; 
};

bool intersect(Circle C, Line L){
	if (getDistanceLP(C.I, L) > C.R) return false;
	return true;
}
pair<Point, Point> getCrossPointCL(Circle C, Line L){
	Point pr = project(L, C.I);
	Vector e = (L.p2 - L.p1) / (L.p1 - L.p2).abs();	//Vector don vi ???
	double base = sqrt(C.R*C.R - (pr - C.I).norm());
	return make_pair(pr + e*base, pr - e*base);
}

int main(){
	int k=0;
	double x=0, y=0, m=0, n=0; //Toa do cac diem co the la double
	double r=0;
	vector<Line> V;
	Line XY;
	scanf("%lf %lf %lf", &x, &y, &r);
	Circle O;
	Point I = (x, y);
	O.I = I;
	O.R = r;
	scanf("%d", &k);
	for (int i=0; i<k; i++){
		scanf("%lf %lf %lf %lf", &x, &y, &m, &n);
		Point X(x, y), Y(m, n);
		XY.p1 = X, XY.p2 = Y;
		V.push_back(XY);
	}
	
	for (int i=0; i<V.size(); i++){
		if (intersect(O, V[i])){
			pair<Point, Point> S = getCrossPointCL(O, V[i]);
			printf("%lf %lf %lf %lf\n", S.first.x, S.first.x, S.second.x, S.second.y);
		} else {
			printf("They don't intersect\n");	
		}
	}
	
}
