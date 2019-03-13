#include<cstdio>
using namespace std;
typedef long long ll;

ll f(ll x){
    if(x<=0){
        return 0;
    }
    ll res=0;
    ll y=1,z;
    for(int i=0;i<40;i++){
        if(y==1&&(x%4==2||x%4==1)){
            res+=1;
        }
        else if(y!=1&&x%(2*y)>=y&&x%(2*y)%2==0){
            res+=y;
        }
        y*=2;
    }
    return res;
}

int main(){
    ll a,b,res=0;
    scanf("%lld %lld",&a,&b);
    printf("%lld\n",f(b)^f(a-1));
}