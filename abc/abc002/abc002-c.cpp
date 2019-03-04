#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    double x[3],y[3],d[3],s=0.0;
    for(int i=0;i<3;i++){
        scanf("%lf %lf",&x[i],&y[i]);
    }
    for(int i=0;i<3;i++){
        d[i]=sqrt((x[i]-x[(i+1)%3])*(x[i]-x[(i+1)%3])+(y[i]-y[(i+1)%3])*(y[i]-y[(i+1)%3]));
        s+=d[i];
    }
    s/=2.0;
    printf("%f\n",sqrt(s*(s-d[0])*(s-d[1])*(s-d[2])));
}