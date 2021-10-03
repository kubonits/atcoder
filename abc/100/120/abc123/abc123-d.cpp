#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
int main(){
    int x,y,z,k;
    ll a[1000],b[1000],c[1000],ans=0,d;
    priority_queue<ll> q1,q2;
    scanf("%d %d %d %d",&x,&y,&z,&k);
    for(int i=0;i<x;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<y;i++){
        scanf("%lld",&b[i]);
    }
    for(int i=0;i<z;i++){
        scanf("%lld",&c[i]);
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            q1.push(a[i]+b[j]);
        }
    }
    for(int i=0;i<k&&!q1.empty();i++){
        d=q1.top();
        q1.pop();
        for(int j=0;j<z;j++){
            q2.push(c[j]+d);
        }
    }
    for(int i=0;i<k;i++){
        printf("%lld\n",q2.top());
        q2.pop();
    }
}