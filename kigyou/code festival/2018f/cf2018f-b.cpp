#include<cstdio>
#include<cmath>
int main(){
    int n,m,r[100000],nn;
    double kai[100001],ans;
    kai[0]=kai[1]=0.0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d",&r[i]);
    }
    for(int i=2;i<=n;i++){
        kai[i]=kai[i-1]+log10(i);
    }
    nn=n;
    for(int i=0;i<m;i++){
        ans+=kai[nn]-kai[r[i]]-kai[nn-r[i]];
        nn-=r[i];
    }
    ans-=(double)n*log10(m);
    printf("%.0f\n",ceil(-ans));
}