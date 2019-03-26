#include<cstdio>
#include<set>
#define INF 10000000000
typedef long long ll;
using namespace std;
int main(){
    int n,k,t;
    ll a,ans=0;
    multiset<ll> ra,re;
    scanf("%d %d",&n,&k);
    for(int i=0;i<k;i++){
        ra.insert(INF);
    }
    for(int i=0;i<n;i++){
        scanf("%d %lld",&t,&a);
        if(t==0){
            ans+=a;
            ra.insert(a);
            if(!re.empty()){
                multiset<ll> ::iterator it=re.end();
                it--;
                re.erase(it);
            }
            else{
                multiset<ll> ::iterator it=ra.begin();
                ans-=*it;
                ra.erase(it);
            }
        }
        else{
            ans+=a;
            re.insert(a);
            if(!ra.empty()){
                multiset<ll>::iterator it=ra.end();
                it--;
                ra.erase(it);
            }
            else{
                multiset<ll>::iterator it=re.begin();
                ans-=*it;
                re.erase(it);
            }
        }
    }
    printf("%lld\n",ans);
}