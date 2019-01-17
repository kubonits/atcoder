#include<cstdio>
#include<set>
using namespace std;

int main(){
    long n,a[200000],b[200001],x,ans=0,l,r;
    multiset<long> s;
    scanf("%ld",&n);
    for(long i=0;i<n;i++){
        scanf("%ld",&a[i]);
        b[a[i]]=i;
    }
    s.insert((long)-1);
    s.insert(n);
    for(long i=1;i<=n;i++){
        set<long>::iterator itr=s.lower_bound(b[i]);
        r=*itr;
        l=*(--itr);
        x=(b[i]-l)*(r-b[i]);
        ans+=x*i;
        s.insert(b[i]);
    }
    printf("%ld\n",ans);
}