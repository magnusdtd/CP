#include<iostream>
using namespace std;
typedef long long int LLI;

LLI PowMod(LLI x, LLI n, LLI M) {
	LLI ans=1;
	while (n>0){
		if (n & 1){
			ans= (ans*x) % M;
		}
		n/=2;
		x= x*x%M;
	}
	return ans;
}

int main(){
    LLI x=0, n=0, m=0;
    cin >> x >> n >> m ;
    LLI ans = PowMod(x, n, m);
    cout << ans <<"\n";
	return 0;
}

//Note: O(log(n)) time complexity