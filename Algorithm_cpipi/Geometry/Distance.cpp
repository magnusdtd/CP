//Khoang cach cua 2 duong thang
//3
//0 0 1 0 0 1 1 1
//0 0 1 0 2 1 1 2
//-1 0 1 0 0 1 0 -1
//Result:
//1
//1.4142135624
//0

#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b))<EPS)
static const int COUNTER_CLOCKWISE = -1;
static const int CLOCKWISE = 1;
static const int ON_SEGMENT = 0;

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
double getDistance(Point a, Point b){
	return (a-b).abs();
}
double getDistanceLP(Point P, Line L){	//Chung minh bang cach dung dien tich cua tam giac
	return abs(cross((P-L.p1), (P-L.p2)))/(L.p1 - L.p2).abs();
}
double getDistanceSP(Point P, Segment S){
	if ( dot(S.p2 - S.p1, P - S.p1) < 0.0 ) return (P-S.p1).abs();
	if ( dot(S.p2 - S.p1, S.p2 - P) < 0.0 ) return (P-S.p2).abs();
	return getDistanceLP(P, S);
}
int CCW(Point p0, Point p1, Point p2){
	Vector a = p1 - p0;
	Vector b = p2 - p0;
	if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
	if (cross(a, b) <-EPS) return CLOCKWISE;
//	if (dot(a, b) < -EPS) return ONLINE_BACK;
//	if (a.abs() < b.abs()) return ONLINE_FRONT;
	return ON_SEGMENT;
}
bool intersect(Point p1, Point p2, Point p3, Point p4){
	return (CCW(p1, p2, p3)*CCW(p1, p2, p4) <= 0) && (CCW(p3, p4, p1)*CCW(p3, p4, p2) <= 0);
}
bool intersect(Segment S1, Segment S2) {
	return intersect(S1.p1, S1.p2, S2.p1, S2.p2);
}
double getDistance(Segment A, Segment B){
	if (intersect(A, B)) return 0.0;
	return min(min(getDistanceSP(A.p1, B), getDistanceSP(A.p2, B)), min(getDistanceSP(B.p1, A), getDistanceSP(B.p2, A)));
}

int main(){
	int k=0;
	double x=0, y=0, m=0, n=0; //Sai
	vector<Segment> V;
	Segment XY;
	scanf("%d", &k);
	for (int i=0; i<k*2; i++){
		scanf("%lf %lf %lf %lf", &x, &y, &m, &n);
		Point X(x, y), Y(m, n);
		XY.p1 = X, XY.p2 = Y;
		V.push_back(XY);
	}
	for (int i=0; i<V.size(); i+=2){
		printf("%0.10f\n", getDistance(V[i], V[i+1]));
	}
	return 0;
}
