#include<iostream>
#include<cmath>
using namespace std;
const double PI = acos(-1.0);

struct Point{
    double x, y;
};

void pause(){
    cout <<"Press any key to continue...";
    getchar();
    getchar();
}

void Koch(int n, Point a, Point b){
    if (n==0){
        return;
    }
    Point s, t , u;
    double th = PI* 60.0 / 180.0;
    s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
    s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
    t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
    t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
    u.x = (t.x - s.x) * cos(th) - (t.y -s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y -s.y) * cos(th) + s.y;

    Koch(n - 1, a, s);
    printf("%0.8lf %0.8lf\n", s.x, s.y);
    Koch(n - 1, s, u);
    printf("%0.8lf %0.8lf\n", u.x, u.y);
    Koch(n - 1, u, t);
    printf("%0.8lf %0.8lf\n", t.x, t.y);
    Koch(n - 1, t, b);
}

int main(){
    /*
    a_______________________b
    =>
                u
              __ __
            __     __
    a______s         t _____b
    */ 

    Point a, b;
    int n=0;
    scanf("%d", &n);

    a.x = a.y = 0;
    b.x = 100, b.y = 0;
    printf("%0.8lf %0.8lf\n", a.x, a.y);
    Koch(n, a, b);
    printf("%0.8lf %0.8lf\n", b.x, b.y);
    // pause();
    return 0;
}