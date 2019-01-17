#include<cstdio>
#include<deque>
#include<algorithm>
using namespace std;
int main(){
    int n;
    long ans=0,x,l,p=0,a,b;
    deque<long> d;
    scanf("%ld %d",&l,&n);
    for(int i=0;i<n;i++){
        scanf("%ld",&x);
        d.push_back(x);
    }
    for(int i=0;i<n;i++){
        if(p<d.front()){
            a=d.front()-p;
            b=l-d.back()+p;
        }
        else{
            a=l-p+d.front();
            b=p-d.back();
        }
        if(a>b){
            ans+=a;
            p=d.front();
            d.pop_front();
        }
        else{
            ans+=b;
            p=d.back();
            d.pop_back();
        }
        //printf("%ld %ld\n",p,ans);
    }
    printf("%ld\n",ans);
}