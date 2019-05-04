#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int n,m;
    double x,y;
    scanf("%d %d",&n,&m);
    n%=12;
    x=(double)n*30+(double)m/2;
    y=(double)m*6;
    y-=x;
    x=0.0;
    printf("%f\n",min(abs(y),abs(360-abs(y))));
}