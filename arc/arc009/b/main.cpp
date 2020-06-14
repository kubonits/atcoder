#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int b[10],n;
    string s;
    vector<pair<int ,string> > v;
    for(int i=0;i<10;i++){
        int x;
        cin>>x;
        b[x]=i;
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        int x=0;
        for(int j=0;j<s.length();j++){
            x*=10;
            x+=b[s[j]-'0'];
        }
        v.push_back({x,s});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        cout<<v[i].second<<endl;
    }
}