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

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll ans=1LL;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }sort(a.begin(),a.end());
  for(ll i =0LL;i<n;i++){
    ans*=(a[i]-i);
    ans%=MOD;
    if(a[i]-i<=0){
      ans=0LL;
    }
  }cout<<ans<<endl;
}