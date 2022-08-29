#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a,b,c,d,e,f,ans=0;
    cin>>a>>b>>c>>d>>e>>f;
    ans=max((a/d)*(b/e)*(c/f),(a/d)*(b/f)*(c/e));
    ans=max(ans,(a/e)*(b/d)*(c/f));
    ans=max(ans,(a/e)*(b/f)*(c/d));
    ans=max(ans,(a/f)*(b/d)*(c/e));
    ans=max(ans,(a/f)*(b/e)*(c/d));
    cout<<ans<<endl;
}