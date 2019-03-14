#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int n,k;
    char s[100010];
    scanf("%s",s);
    scanf("%d",&k);
    n=strlen(s);
    for(int i=0;i<n;i++){
        if(i==n-1){
            printf("%c\n",'a'+(s[i]-'a'+k)%26);
        }
        else if(s[i]!='a'&&k>='z'-s[i]+1){
            printf("a");
            k-='z'-s[i]+1;
        }
        else{
            printf("%c",s[i]);
        }
    }
}