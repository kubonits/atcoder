#include<cstdio>
#include<set>
#include<string>
#include<iostream>
using namespace std;
int main(){
    string s,sub="";
    set<string> se;
    int n,ans=0;
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++){
        sub+=s[i];
        decltype(se)::iterator it = se.find(sub);
        if(it==se.end()){
            ans++;
            se.insert(sub);
            sub="";
        }
    }
    printf("%d\n",ans);
}