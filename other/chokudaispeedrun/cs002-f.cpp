#include<cstdio>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;
int main(){
    set<pair<int,int> > s;
    int n,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        s.insert(make_pair(min(a,b),max(a,b)));
    }
    printf("%ld\n",s.size());
}