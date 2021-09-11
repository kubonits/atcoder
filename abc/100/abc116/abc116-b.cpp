#include<cstdio>
#include<set>
using namespace std;
int s,a;
set<int> b;
int main(){
    scanf("%d",&s);
    b.insert(s);
    a=s;
    for(int i=2;i<=1000000;i++){
        if(a%2){
            a=a*3+1;
        }
        else{
            a/=2;
        }
        decltype(b)::iterator it =b.find(a);
        if(it!=b.end()){
            printf("%d\n",i);
            return 0;
        }
        else{
            b.insert(a);
            printf("%d\n",a);
        }
    }
}