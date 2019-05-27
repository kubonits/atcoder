#include<cstdio>
using namespace std;
int main(){
    int n,k;
    char s[60];
    scanf("%d %d",&n,&k);
    scanf("%s",s);
    s[k-1]+='a'-'A';
    printf("%s\n",s);
}