#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<float> s;

    int n=0, somu=0;
    float heso=0, x=0;
    scanf("%d", &n);
    printf("Da thuc vua nhap la: ");
    scanf("%f %d", &heso, &somu);
    s.push(heso);
    s.push(somu);
    if (heso==1){
        printf("+x^%d", somu);
    } else if (heso == -1){
        printf("-x^%d", somu);
    } else if (heso > 0 ){
            printf("+%0.2fx^%d", heso, somu);
    } else if (heso == 0 ){
            printf("%0.2fx^%d", heso, somu);
    } else if (heso < 0 ){
            printf("%0.2fx^%d", heso, somu);
    } else if (somu == 0){
        printf("%0.2f", heso);
    }
    for (int i=1; i<n; i++){
        scanf("%f %d", &heso, &somu);
        s.push(heso);
        s.push(somu);
        if (heso==1){
            printf("+x^%d", somu);
        } else if (heso == -1){
            printf("-x^%d", somu);
        } else if (heso > 0 ){
             printf("+%0.2fx^%d", heso, somu);
        } else if (heso == 0 ){
             printf("%0.2fx^%d", heso, somu);
        } else if (heso < 0 ){
             printf("%0.2fx^%d", heso, somu);
        } else if (somu == 0){
            printf("%0.2f", heso);
        } else {
            printf("0");
            break;
        }
    }
    printf("\n");
    scanf("%f", &x);
    float heso1=0, somu1=0, sum=0, temp=1;
    while(!s.empty()){
        somu1=s.top();
        s.pop();
        heso1=s.top();
        s.pop();
        if (somu1==0) temp=1;
        while(somu1>0){
            temp*=x;
            somu1--;
        }
        sum+=heso1*temp;
        temp=1;
    }


    printf("Gia tri cua da thuc la: %0.2f", sum);
    return 0;
}