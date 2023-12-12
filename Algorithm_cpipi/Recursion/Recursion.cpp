/*5
1 5 7 10 21
4
2 4 17 8
no
no
yes
yes*/

#include<iostream>
using namespace std;

int n=0, a[21];

bool solve(int i, int m){
    if (m == 0) return true;
    if (i >= n) return false;
    return solve(i+1, m) || solve(i+1, m - a[i]);
}

int main(){
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int q=0, m=0;
    scanf("%d", &q);
    for (int i=0; i<q; i++){
        scanf("%d", &m);
        if (solve(0, m)){
            printf("yes\n");
        } else printf("no\n");
    }
    return 0;
}