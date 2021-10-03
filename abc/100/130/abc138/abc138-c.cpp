#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    double ans=0,v[1000];
    for(int i=0;i<n;i++){
        scanf("%lf",&v[i]);
    }
    sort(v,v+n);
    ans=(v[0]+v[1])/2;
    for(int i=2;i<n;i++){
        ans=(ans+v[i])/2;
    }
    printf("%.6f\n",ans);
}