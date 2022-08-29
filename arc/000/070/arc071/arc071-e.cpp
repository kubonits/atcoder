#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int sums[100001]={},sumt[100001]={},n,m,a,b,c,d,q;
    char s[100010],t[100010];
    scanf("%s",s);
    scanf("%s",t);
    n=strlen(s);
    m=strlen(t);
    for(int i=0;i<n;i++){
        sums[i+1]=sums[i]+s[i]-'A'+1;
    }
    for(int i=0;i<m;i++){
        sumt[i+1]=sumt[i]+t[i]-'A'+1;
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if((sums[b]-sums[a-1])%3==(sumt[d]-sumt[c-1])%3){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}