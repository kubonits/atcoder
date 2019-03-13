#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int n,l;
    char s[100010];
    scanf("%d",&l);
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<min(l,n);i++){
        printf("%c",s[i]);
    }
    printf("\n");
}