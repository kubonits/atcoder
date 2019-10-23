#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<deque>
#include<cmath>
using namespace std;

int main(){
    int n;
    double x[100],y[100],dis,ans=0.0,xx,yy,a,b;
    const double PI=3.14159265358979323846;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf%lf",&x[i],&y[i]);
    }
    for(double i=0;i<100000.0;i++){
        xx=yy=0.0;
        a=cos(PI*i/1000.0);
        b=sin(PI*i/1000.0);
        for(int j=0;j<n;j++){
            if(a*x[j]+b*y[j]>=0){
                xx+=x[j];
                yy+=y[j];
            }
        }
        dis=xx*xx+yy*yy;
        ans=max(ans,sqrt(dis));
    }
    printf("%.12f\n",ans);
}