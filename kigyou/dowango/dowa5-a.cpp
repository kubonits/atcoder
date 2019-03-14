#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int n,ans;
    float a[100],sum=0.0,ave,sa;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%f",&a[i]);
        sum+=a[i];
    }
    ave=sum/n;
    ans=0;
    sa=fabs(ave-a[0]);
    for(int i=1;i<n;i++){
        if(sa>fabs(ave-a[i])){
            sa=fabs(ave-a[i]);
            ans=i;
        }
    }
    printf("%d\n",ans);
}