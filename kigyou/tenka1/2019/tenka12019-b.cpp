#include<cstdio>
using namespace std;
int main(){
    int n,k;
    char s[11];
    scanf("%d",&n);
    scanf("%s",s);
    scanf("%d",&k);
    for(int i=0;i<n;i++){
        if(s[i]!=s[k-1]){
            s[i]='*';
        }
    }
    printf("%s\n",s);
}