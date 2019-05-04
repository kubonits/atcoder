#include<cstdio>
using namespace std;
int main(){
    int n,d,k,l[10000],r[10000],s,t;
    scanf("%d %d %d",&n,&d,&k);
    for(int i=0;i<d;i++){
        scanf("%d %d",&l[i],&r[i]);
    }
    for(int i=0;i<k;i++){
        scanf("%d %d",&s,&t);
        int L=s,R=s;
        for(int j=0;j<d;j++){
            if(l[j]<L&&r[j]>=L){
                L=l[j];
            }
            if(l[j]<=R&&R<r[j]){
                R=r[j];
            }
            if(L<=t&&t<=R){
                printf("%d\n",j+1);
                break;
            }
        }
    }
}