#include<cstdio>
#include<algorithm>
#include<set>
#include<utility>
typedef long long ll;
using namespace std;
int main(){
    set<pair<int,int> > s;
    ll h,w,ans;
    int n,r,c;
    scanf("%lld %lld %d",&h,&w,&n);
    ans=(h-1)*w+h*(w-1);
    for(int i=0;i<n;i++){
        scanf("%d %d",&r,&c);
        if(r-1>0){
            decltype(s) :: iterator it=s.find(make_pair(r-1,c));
            if(it==s.end()){
                ans--;
            }
        }
        if(c-1>0){
            decltype(s) :: iterator it=s.find(make_pair(r,c-1));
            if(it==s.end()){
                ans--;
            }
        }
        if(r+1<=h){
            decltype(s) :: iterator it=s.find(make_pair(r+1,c));
            if(it==s.end()){
                ans--;
            }
        }
        if(c+1<=w){
            decltype(s) :: iterator it=s.find(make_pair(r,c+1));
            if(it==s.end()){
                ans--;
            }
        }
        s.insert(make_pair(r,c));
    }
    printf("%lld\n",ans);
}