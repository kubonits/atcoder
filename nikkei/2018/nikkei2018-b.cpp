/*
https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_b
*/
#include<cstdio>
using namespace std;
int main(){
    int n,ans=0;
    char a[101],b[101],c[101];
    scanf("%d",&n);
    scanf("%s",a);
    scanf("%s",b);
    scanf("%s",c);
    for(int i=0;i<n;i++){
        if(a[i]==b[i]&&b[i]==c[i]&&a[i]==c[i]);
        else if(a[i]==b[i]||b[i]==c[i]||a[i]==c[i]){
            ans++;
        }
        else{
            ans+=2;
        }
    }
    printf("%d\n",ans);
}
