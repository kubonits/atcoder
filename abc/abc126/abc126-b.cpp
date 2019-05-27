#include<cstdio>
using namespace std;
int main(){
    int n,a,b;
    scanf("%d",&n);
    a=n/100;
    b=n%100;
    if(a&&b&&a<=12&&b<=12){
        printf("AMBIGUOUS\n");
    }
    else if(b&&b<=12){
        printf("YYMM\n");
    }
    else if(a&&a<=12){
        printf("MMYY\n");
    }
    else{
        printf("NA\n");
    }
}