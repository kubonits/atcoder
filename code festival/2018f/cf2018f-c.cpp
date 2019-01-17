#include<cstdio>
#include<algorithm>
#include<utility>
#include<map>
using namespace std;
int main(){
    int n,a,b,m,t,p,l,r;
    map<int,int> x;
    int e[100000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        e[i]=a;
        x.insert(make_pair(a,b));
    }
    sort(e,e+n);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&t);
        l=0;
        r=n-1;
        while(l<=r){
            p=(l+r)/2;
            if(e[p]>t){
                r=p-1;
            }
            else{
                l=p+1;
            }
        }
        if(r<0){
            printf("%d\n",x[e[0]]);
        }
        else if(l>n-1){
            printf("%d\n",x[e[r]]+t-e[r]);
        }
        else{
            printf("%d\n",min(x[e[r]]+t-e[r],x[e[l]]));
        }
    }
}