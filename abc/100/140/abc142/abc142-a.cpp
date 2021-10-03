#include<cstdio>
using namespace std;
int main(){
    int n,a;
    scanf("%d",&n);
    a=n/2+n%2;
    printf("%f\n",(double)((double)a/(double)n));
}