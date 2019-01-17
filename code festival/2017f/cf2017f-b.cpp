#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int a,b,c,mina,maxa,n;
    char s[100010];
    a=b=c=0;
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            a++;
        }
        else if(s[i]=='b'){
            b++;
        }
        else{
            c++;
        }
    }
    mina=maxa=a;
    maxa=max(maxa,b);
    maxa=max(maxa,c);
    mina=min(mina,b);
    mina=min(mina,c);
    if(maxa-mina>1){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
}