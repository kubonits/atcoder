#include<cstdio>
using namespace std;
int n,q,sum[100001]={},l,r,f;
char s[100010];
int main(){
    scanf("%d %d",&n,&q);
    scanf("%s",s);
    for(int i=1;i<n;i++){
        sum[i+1]=sum[i];
        if(s[i-1]=='A'&&s[i]=='C'){
            sum[i+1]++;
        }
    }
    for(int i=0;i<q;i++){
        scanf("%d %d",&l,&r);
        f=0;
        if(l>1){
            f=sum[l]-sum[l-1];
        }
        printf("%d\n",sum[r]-sum[l-1]-f);
    }
}