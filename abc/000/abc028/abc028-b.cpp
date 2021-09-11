#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int n,f[6]={};
    char s[101];
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++){
        f[s[i]-'A']++;
    }
    for(int i=0;i<6;i++){
        printf("%d",f[i]);
        if(i!=5){
            printf(" ");
        }
        else{
            printf("\n");
        }
    }
}