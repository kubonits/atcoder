#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
#include <cstring>

vector<int> g[100001],c(100001);
int n;

void dfs(int x,int y){
  for(int i=0;i<g[x].size();i++){
    if(g[x][i]!=y){
      c[g[x][i]]=(1^c[x]);
      dfs(g[x][i],x);
    }
  }
}

int main() {
  int a,b,q;
  cin >> n>>q;
  for(int i=0;i<n-1;i++){
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1,0);
  c[1]=0;
  for(int i=0;i<q;i++){
    cin>>a>>b;
    if((c[a]^c[b])){
      cout<<"Road"<<endl;
    }else{
      cout<<"Town"<<endl;
    }
  }
}