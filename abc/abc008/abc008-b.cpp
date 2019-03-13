#include<cstdio>
#include<string>
#include<map>
#include<iostream>
#include<utility>
using namespace std;
int main(){
    int n,a=0;
    string s[50],ans;
    map<string,int> m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>s[i];
        decltype(m)::iterator it=m.find(s[i]);
        if(it!=m.end()){
            m[s[i]]++;
        }
        else{
            m.insert(make_pair(s[i],1));
        }
        if(m[s[i]]>a){
            a=m[s[i]];
            ans=s[i];
        }
    }
    cout<<ans<<endl;
}