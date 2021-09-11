#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int n,p,maxa=0,sum=0,a;
    char s[1000][30],t[30];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s %d",s[i],&p);
        sum+=p;
        if(maxa<p){
            maxa=p;
            strcpy(t,s[i]);
        }
    }
    if(sum<2*maxa){
        printf("%s\n",t);
    }
    else{
        printf("atcoder\n");
    }
}