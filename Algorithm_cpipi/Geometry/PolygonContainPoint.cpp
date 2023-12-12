//Kiem tra 1 diem co thuoc da giac hay khong?
//4
//0 0
//3 1
//2 3
//0 3
//3
//2 1
//0 2
//3 2
//Result:
//2
//1 
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
static const int IN = 2;
static const int ON = 1;
static const int OUT = 0;

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
typedef vector<Point> Polygon;
double dot(Vector a, Vector b){
	return a.x*b.x + a.y*b.y;
}
double cross(Vector a, Vector b){
	return a.x*b.y - a.y*b.x;
}
int containPyP(Polygon G, Point P){
	bool x= false;
	for (int i=0; i<G.size(); i++){
		Point a = G[i] - P, b = G[(i+1)%2] - P;
		if (abs(cross(a,b)) < EPS && dot(a, b) < EPS ) return ON;
		if (a.y > b.y) swap(a, b);	//Doi lai thanh nguoc chieu kim dong ho a->b
		if (a.y < EPS && EPS < b.y && cross(a, b) > EPS) x = !x; // ??
	}
	return (x ? 2: 0);
}
int main(){
	vector<Point> V;
	Polygon G;
	int k = 0, x=0, y=0;
	scanf("%d", &k);
	for (int i =0; i<k; i++){
		scanf("%d %d", &x, &y);
		Point X(x, y);
		G.push_back(X);	
	}
	scanf("%d", &k);
	for (int i=0; i<k; i++){
		scanf("%d %d", &x, &y);
		Point X(x, y);
		V.push_back(X);	
	}
	for (int i=0; i<V.size(); i++){
		if (containPyP(G, V[i]) == IN) printf("2\n");
		if (containPyP(G, V[i]) == ON) printf("1\n");
		if (containPyP(G, V[i]) == OUT) printf("0\n");
	}
	
	return 0;
}
