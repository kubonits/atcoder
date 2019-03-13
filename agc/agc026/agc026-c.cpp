#include<cstdio>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<iostream>
using namespace std;

string s,sl,sr,s1,s2;
int n;

long long ans;
map<pair<string,string>,long long> m;

void dfsl(int x){
    if(x==n){
        decltype(m) :: iterator it=m.find(make_pair(s1,s2));
        if(it==m.end()){
            m.insert(make_pair(make_pair(s1,s2),1));
        }
        else{
            m[make_pair(s1,s2)]++;
        }
    }
    else{
        s1+=sl[x];
        dfsl(x+1);
        s1.pop_back();
        s2+=sl[x];
        dfsl(x+1);
        s2.pop_back();
    }
}

void dfsr(int x){
    if(x==-1){
        decltype(m) :: iterator it=m.find(make_pair(s1,s2));
        if(it==m.end());
        else{
            ans+=m[make_pair(s1,s2)];
        }
    }
    else{
        s1+=sr[x];
        dfsr(x-1);
        s1.pop_back();
        s2+=sr[x];
        dfsr(x-1);
        s2.pop_back();
    }
}

int main(){
    scanf("%d",&n);
    cin>>s;
    sl=s.substr(0,n);
    sr=s.substr(n);
    dfsl(0);
    dfsr(n-1);
    printf("%lld\n",ans);
}