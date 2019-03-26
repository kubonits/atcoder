#include<cstdio>
#include<algorithm>
#include<deque>
using namespace std;
typedef long long ll;
deque<ll> d,l;
ll n,a[200000],b[200000];
int main(){
    scanf("%lld",&n);
    for(ll i=0;i<n;i++){
        scanf("%lld",&a[i]);//-ai+b=-ci+d
        b[i]=a[i]+i*i;
        while(!d.empty()&&l.back()>(b[d.back()]-b[i])/2/(d.back()-i)){
            d.pop_back();
            l.pop_back();
        }
        if(d.empty()||(b[d.back()]-b[i])/2/(d.back()-i)<=n){
            if(l.empty()){
                l.push_back(0);
            }
            else{
                l.push_back((b[d.back()]-b[i])/2/(d.back()-i));
            }
            d.push_back(i);
        }
    }
    for(ll i=0;i<n;i++){
        while(d.size()>1&&-2*i*d[0]+b[d[0]]>-2*i*d[1]+b[d[1]]){
            d.pop_front();
        }
        printf("%lld\n",i*i+b[d[0]]-2*i*d[0]);
    }
}