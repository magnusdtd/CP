#include<bits/stdc++.h>
using namespace std;
//const auto seed = chrono::steady_clock::now().time_since_epoch().count();

int main(){
	long long seed = time(0);
	
	std::mt19937 rng32(seed);
	cout << "random 32: " << rng32() << endl;
	mt19937_64 rng64(seed);
	cout << "random 64: " << rng64() << endl;
	
	return 0;
}
