#include<cstdio>
#include<deque>
#include<utility>
using namespace std;
typedef long long ll;
int main(){
    int n,k;
    ll a[100000],ans=0;
    deque<pair<ll,int> > q;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        while(!q.empty()&&q.back().first>a[i]){
            q.pop_back();
        }
        while(!q.empty()&&q.front().first>a[i]){
            q.pop_front();
        }
        q.push_back(make_pair(a[i],i));
        ans+=q.front().first;
        if(q.front().second==i-k+1){
            q.pop_front();
        }
    }
    printf("%lld\n",ans);
}