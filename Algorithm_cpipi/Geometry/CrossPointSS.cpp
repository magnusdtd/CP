//Tim toa do giao diem cua 2 doan thang
//3
//0 0 2 0 1 1 1 -1
//0 0 1 1 0 1 1 0
//0 0 1 1 1 0 0 1
//Result:
//1	0
//0.5 0.5
//0.5 0.5

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

Point getCrossPoint(Segment A, Segment B){
	Vector base = B.p2 - B.p1;
	double d1 = abs(cross(base, A.p1 - B.p1));	// khoi can tinh base.abs() vi khi tinh t se tu dong triet tieu
	double d2 = abs(cross(base, A.p2 - B.p1));	
	double t = d1 / (d1+d2);
	return A.p1 + (A.p2 - A.p1)*t;
}

int main(){
	int k=0;
	int x=0, y=0, m=0, n=0;
	vector<Segment> V;
	Segment XY;
	scanf("%d", &k);
	for (int i=0; i<k*2; i++){
		scanf("%d %d %d %d", &x, &y, &m, &n);
		Point X(x, y), Y(m, n);
		XY.p1 = X, XY.p2 = Y;
		V.push_back(XY);
	}
	for (int i=0; i<V.size(); i+=2){
		Point Z = getCrossPoint(V[i], V[i+1]);
		printf("%0.10f %0.10f\n", Z.x, Z.y);
	}
}
