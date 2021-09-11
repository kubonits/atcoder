#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#include<utility>
using namespace std;
typedef long long ll;
int main(){
    int n,m;
    char s[11];
    vector<char> s1;
    map<vector<char> ,ll> se;
    ll ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s);
        m=strlen(s);
        sort(s,s+m);
        s1.clear();
        for(int j=0;j<m;j++){
            s1.push_back(s[j]);
        }
        decltype(se)::iterator it = se.find(s1);
        if(it!=se.end()){
            se[s1]++;
        }
        else{
            se.insert(make_pair(s1,1));
        }
    }
    for(auto i=se.begin();i!=se.end();i++){
        ans+=(i->second)*(i->second-1)/2;
    }
    printf("%lld\n",ans);
}