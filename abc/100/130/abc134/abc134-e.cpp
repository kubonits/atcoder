#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<cstring>
#include<set>
using namespace std;

int main(){
    int n,a;
    multiset<int> s;
    scanf("%d",&n);
    scanf("%d",&a);
    s.insert(a);
    for(int i=1;i<n;i++){
        scanf("%d",&a);
        decltype(s)::iterator it = s.lower_bound(a);
        if(it==s.begin()){
            s.insert(a);
        }
        else{
            it--;
            s.erase(it);
            s.insert(a);
        }
    }
    printf("%ld\n",s.size());
}