//Kiem tra truc giao, song song
//3
//0 0 3 0 0 2 3 2
//0 0 3 0 1 1 1 4
//0 0 3 0 1 1 2 2
//Result :
//2
//1
//0

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
#define EPS (1e-10)
#define equals(a, b) (fabs((a)-(b))<EPS)

struct Point
{
    double x, y;
    Point(double x=0, double y=0) : x(x), y(y) {}
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
    double abs() {
        return sqrt(x*x + y*y);
    }
    bool operator == (Point p){
        return equals(x,p.x) && equals(y, p.y);
    }
};
typedef Point Vector;

struct Segment {
    Point p1, p2;
};
typedef Segment Line;

double dot(Vector a, Vector b) { //Tich vo huong
	return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) { //Tich huu huong voi khong gian 2 chieu
	return a.x * b.y - a.y * b.x;
}

bool isParallel(Vector a, Vector b) { //Kiem tra song song
	return equals(cross(a, b), 0.0);
}

bool isOrthogonal(Vector a, Vector b) {	//Kiem tra truc giao
	return equals(dot(a, b), 0.0);
}


int main() {
	int k=0, x=0, y=0, m=0, n=0;
	Point X(0, 0), Y(0, 0);
	vector<Vector> V;
    scanf("%d", &k);
    for (int i=0; i<k; i++){
    	scanf("%d %d %d %d", &x, &y, &m, &n);
    	X.x = x, X.y = y, Y.x = m, Y.y = n;	
    	V.push_back(X-Y);
    	scanf("%d %d %d %d", &x, &y, &m, &n);
    	X.x = x, X.y = y, Y.x = m, Y.y = n;	
    	V.push_back(X-Y);
	}
	for (int i=0; i<V.size(); i+=2) {
		if (isParallel(V[i], V[i+1])) {
			printf("2\n");
		} else if (isOrthogonal(V[i], V[i+1])) {
			printf("1\n");
		} else printf("0\n");
	}
    return 0;
}
