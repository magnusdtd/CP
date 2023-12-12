#include<iostream>


int GCD(int a, int b){
    return b ? GCD(b, a%b) : a; 
}

int main(){
    int t=0;
    std::cin >>t;
    while (t > 0){
        int n, ans=0;
        std::cin >> n;
        int a[n];
        for (int i=0; i<n; i++){
            std::cin>>a[i];
            ans= GCD(ans, a[i]);
        } 
        if (ans==1){
            std::cout <<"YES\n";
        } else{
            std::cout<< "No\n";
        }

        t--;
    }
   

}