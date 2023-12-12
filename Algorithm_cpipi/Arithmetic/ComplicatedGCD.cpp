#include<iostream>
using namespace std;
typedef long long LL;

LL GCD(LL a, LL b){
    return b? GCD(b, a%b) : a;
}

int main(){
    LL a, b;
    cin>> a>> b;
    LL arr[b-a+1];
    LL ans=0;
    for (int i=0; i<b-a+1; i++){
        arr[i] = a+i;
        ans=GCD(ans, arr[i]);
    }
    cout << ans;

}
// Đề trên codeforces hơi xàm hỏi GCD của các nó liên tiếp thì hieernnhieen nó bằng 1 ????