#include<cstdio>
using namespace std;
int main(){
    long a,b,c;
    scanf("%ld %ld %ld",&a,&b,&c);
    if(a+b>=c){
        printf("%ld\n",b+c);
    }
    else{
        printf("%ld\n",a+b+b+1);
    }
}