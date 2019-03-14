/*
https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_a
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    printf("%d ",min(a,b));
    if(n-(a+b)>0){
        printf("0\n");
    }
    else{
        printf("%d\n",a+b-n);
    }
}