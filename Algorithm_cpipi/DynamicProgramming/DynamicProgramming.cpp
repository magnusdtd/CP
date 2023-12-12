/*15 6
1 2 7 8 12 50
Result:
2*/


#include<iostream>
#include<algorithm>
using namespace std;

static const int MMAX = 20;
static const int NMAX = 50000;
static const int oo = 1<<29;

int main(){
    int n, m;
    int C[21];
    int T[NMAX+1];
    cin >> n >> m;
    
    for (int i=0; i<m; i++){
        cin >> C[i];
    }
    for (int i=0; i<=MMAX; i++) T[i]=oo;
    T[0]=0;
    for (int i=0; i<=m; i++){
        for (int j=C[i]; j <= n; j++){
            T[j] = min(T[j], T[j - C[i]]+ 1);
        }
    }   

    cout << T[n];
    return 0;
}