#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    char s[100010];
    int n,a=0,b=0;
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            a++;
        }
        else{
            b++;
        }
    }
    printf("%d\n",2*min(a,b));
}