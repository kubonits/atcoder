#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int s,a,maxa;
set<int> b;
int main(){
    scanf("%d",&s);
    b.insert(s);
    a=s;
    maxa=1;
    for(int j=1;j<=100;j++){
        b.insert(j);
        a=j;
        for(int i=2;i<=1000000;i++){
        if(a%2){
            a=a*3+1;
        }
        else{
            a/=2;
        }maxa=max(maxa,a);
        decltype(b)::iterator it =b.find(a);
        if(it!=b.end()){
            //printf("%d\n",i);
            break;
        }
        else{
            b.insert(a);
            //printf("%d\n",a);
        }
    }

    }
    printf("%d\n",maxa);
}