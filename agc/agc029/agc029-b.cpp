#include<cstdio>
#include<map>
#include<utility>
#include<algorithm>
using namespace std;
int main(){
    int n,ans=0,p;
    long a[200000],two[32];
    map<long,int> m;
    two[0]=1;
    for(int i=1;i<32;i++){
        two[i]=two[i-1]*2;
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%ld",&a[i]);
        decltype(m)::iterator it=m.find(a[i]);
        if(it!=m.end()){
            m[a[i]]++;
        }
        else{
            m.insert(make_pair(a[i],1));
        }
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        if(m[a[i]]){
            for(int j=0;j<32;j++){
                if(two[j]>a[i]){
                    p=j;
                    break;
                }
            }
            decltype(m)::iterator it=m.find(two[p]-a[i]);
            if(it!=m.end()&&(it->second&&it->first!=a[i]||it->second>1)){
                ans++;
                m[a[i]]--;
                it->second--;
            }
        }
    }
    printf("%d\n",ans);
}