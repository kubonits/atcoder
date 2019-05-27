#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    int q,si;
    priority_queue<ll> l;
    priority_queue<ll,vector<ll>,greater<ll> > r;
    ll ans=0,a,b,sum=0;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%lld",&a);
        if(a==1){
            scanf("%lld %lld",&a,&b);
            ans+=b;
            if(!l.empty()){
                ans+=max(l.top(),a)-min(l.top(),a);
            }
            if(l.empty()||l.top()>=a){
                l.push(a);
            }
            else if(r.empty()||r.top()<=a){
                r.push(a);
            }
            else if(l.size()==r.size()){
                ans-=max(l.top(),a)-min(l.top(),a);
                l.push(a);
            }
            else{
                r.push(a);
            }
            si=l.size()-r.size();
            if(si>1){
                a=l.top();
                l.pop();
                ans-=(a-l.top())*l.size();
                ans+=(a-l.top())*r.size();
                ans+=(a-l.top());
                r.push(a);
            }
            else if(si<0){
                a=r.top();
                r.pop();
                ans+=(a-l.top())*l.size();
                ans-=(a-l.top())*r.size();
                ans-=(a-l.top());
                l.push(a);
            }
        }
        else{
            printf("%lld %lld\n",l.top(),sum+ans);
        }
    }
}