//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        // code here
        long long int max= -1;
        while (N % 2 == 0){
            max=2;
            N= N/2;
           
        }
        for (int i=3; i<int(sqrt(N))+1; i+=2){
            while (N % i ==0){
                N=N/i;
                max=i;
            }
        }
        return N>2 ? N:max;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int N;
    cin>>N;
    Solution ob;
    cout << ob.largestPrimeFactor(N) << endl;
    return 0; 
}
// } Driver Code Ends