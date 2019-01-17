#include<cstdio>
using namespace std;
int main(){
    long n,a,b,c,d;
    scanf("%ld %ld %ld %ld %ld",&n,&a,&b,&c,&d);
    for(long i=0;i<n-1;i++){
        if(c*i-d*(n-1-i)<=b-a&&d*i-c*(n-1-i)>=b-a){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}
  