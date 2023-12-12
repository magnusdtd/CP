//Thuat toan Andrew dung de tim ra da giac loi chua tat ca cac diem da chon
//Convex Hull
//7
//2 1
//0 0 
//1 2
//2 2 
//4 2
//1 3
//3 3
//Result:
//5
//0 0 
//2 1
//4 2
//3 3
//1 3




// Co bug







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
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
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
	bool operator == (const Point &p) const {
        return equals(x,p.x) && equals(y, p.y);
    }
    bool operator < (const Point &p) const {
    	return x != p.x ? x < p.x : y < p.y;
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
int CCW(Point p0, Point p1, Point p2){
	Vector a = p1 - p0;
	Vector b = p2 - p0;
	if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
	if (cross(a, b) <-EPS) return CLOCKWISE;
	if (dot(a, b) < -EPS) return ONLINE_BACK;
	if (a.abs() < b.abs()) return ONLINE_FRONT;
	return ON_SEGMENT;
}
Polygon AndrewScan(Polygon G){
	Polygon u, l;
	int len = G.size();
	
	sort(G.begin(), G.end());
	u.push_back(G[0]);
	u.push_back(G[1]);
	
	l.push_back(G[len - 1]);
	l.push_back(G[len - 2]);
	
	//Phan tren
	for (int i=2; i<len; i++){
		for (int j = u.size(); j>=2 && CCW(u[j - 2], u[j-1], G[i]) >= 0; j--){
			u.pop_back();
		}
		u.push_back(G[i]);
	}
	
	//Phan duoi
	for (int i= len - 3; i>=0; i--){
		for (int j = l.size(); j>=2 && CCW(l[j - 2], l[j-1], G[i])>=0; j--){
			l.pop_back();
		}
		l.push_back(G[i]);
	}
	
	reverse(l.begin(), l.end());
	for (int i=u.size() - 2; i >= 1; i--){
		l.push_back(u[i]);
	}
	return l;
}

int main(){
	Polygon G;
	int k=0, x=0, y=0;
	scanf("%d", &k);
	for (int i=0; i<k; i++){
		scanf("%d %d", &x, &y);
		G.push_back(Point(x, y));
	}
	G = AndrewScan(G);
	printf("%d\n", G.size());
	for (int i=0; i<G.size(); i++){
		printf("%d %d\n", G[i].x, G[i].y);
	}
	return 0;
}
