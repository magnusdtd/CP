//Tim sao giao diem cua cac duong thang song song
//6
//2 2 2 5
//1 3 5 3
//4 1 4 4
//5 2 7 2
//6 1 6 3
//6 5 6 7
//Result:
//3

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b))<EPS)
//static const int COUNTER_CLOCKWISE = -1;
//static const int CLOCKWISE = 1;
//static const int ON_SEGMENT = 0;
//static const int IN = 2;
//static const int ON = 1;
//static const int OUT = 0;

struct Point {
	double x, y;
	Point () {}
	Point(double x, double y): x(x), y(y) {
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
#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3
struct EndPoint{
	Point p;
	int seg, st; //seg = so thu tu, st = 1 trong 4 vi tri left, right, bottom, top
	EndPoint() {}
	EndPoint(Point p, int seg, int st): p(p), seg(seg), st(st) {}
	
	bool operator < (const EndPoint &ep) const {
		if (p.y == ep.p.y) {
			return st < ep.st;
		} else {
			return p.y < ep.p.y;
		}
	}
};
EndPoint EP[2*1000010];

int ManhattanIntersection(vector<Segment> S){
	int n = S.size();
	sort(EP, EP + (2*n));
	
	set<int> BT;
	BT.insert(1000000001);	//Tao set sieu lon de quet het mat phang :))
	int cnt = 0;
	
	for (int i=0; i<2*n; i++){	//Quet tu duoi len tren
		if (EP[i].st== TOP){
			BT.erase(EP[i].p.x);
		} else if (EP[i].st == BOTTOM){
			BT.insert(EP[i].p.x);
		} else if (EP[i].st == LEFT){
			set<int> :: iterator b = BT.lower_bound(S[EP[i].seg].p1.x);
			set<int> :: iterator e = BT.upper_bound(S[EP[i].seg].p2.x);
			cnt += distance(b, e);
		}
	}
	return cnt;
}

int main(){
	int k=0;
	vector<Segment> S;
	Segment seg;
	scanf("%d", &k);
	for (int i=0; i<k; i++){
		scanf("%lf %lf %lf %lf", &seg.p1.x, &seg.p1.y, &seg.p2.x, &seg.p2.y);
		//Dieu chinh diem dau va cuoi cua seg truoc khi cho vao vector
		if (seg.p1.y == seg.p2.y) {
			if (seg.p1.x > seg.p2.x) swap(seg.p1, seg.p2);
		} else if (seg.p1.y > seg.p2.y) swap(seg.p1, seg.p2);
		
		//
		if (seg.p1.y == seg.p2.y){
			EP[k++] = EndPoint(seg.p1, i, LEFT);
			EP[k++] = EndPoint(seg.p2, i, RIGHT);
		} else{
			EP[k++] = EndPoint(seg.p1, i, BOTTOM);
			EP[k++] = EndPoint(seg.p2, i, TOP);
		}
		S.push_back(seg);
	}
	
	
	printf("%d", ManhattanIntersection(S));
	
	return 0;
}
