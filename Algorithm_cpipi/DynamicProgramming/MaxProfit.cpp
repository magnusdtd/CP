/*Case1:
6
5
3
1
3
4
3
Result1: 3
Case2:
6
5
3
1
3
4
3
Result2: -1*/

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n=0;
    int a[20000];
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    int minv = a[0];
    int maxv = INT_MIN;
    for (int j=1; j<n; j++){
        maxv= max(maxv, a[j] - minv);
        minv= min(minv, a[j]);
    }
    printf("%d", maxv);
    return 0;
}