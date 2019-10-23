#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<utility>
#include<cmath>
using namespace std;
typedef long long ll;
int main(){
    ll k,x,y,px=0,py=0,a,dis;
    vector<pair<ll,ll> > v;
    scanf("%lld%lld%lld",&k,&x,&y);
    dis=abs(x)+abs(y);
    if(k%2==0&&(x+y)%2){
        printf("-1\n");
    }
    else if(k==(abs(x)+abs(y))){
        printf("1\n");
        printf("%lld %lld\n",x,y);
    }
    else if(k%2&&(abs(x)+abs(y))%2&&3*k>=abs(x)+abs(y)){
        printf("3\n");
        a=3*k-abs(x)-abs(y);
        ll bx,by;
        bx=min(k,a/2);
        if(x>0){
            px=-bx;
        }
        else{
            px=bx;
        }
        a-=2*bx;
        if(!a){
            if(y>0){
                py=k-bx;
            }
        }
        printf("%d %d\n",px,py);
        if(a){
            if(py>y){
                py+=a/2;
            }
            else{
                py-=a/2;
            }
            if(px>x){
                px-=(k-a/2);
            }
            else{
                px+=(k-a/2);
            }
        }
        else{
            by=abs(y-by);
            if(py>y){
                py-=min(by,k);
            }
            else{
                py+=min(by,k);
            }
            if(px>x){
                px-=(k-min(by,k));
            }
            else{
                px+=(k-min(by,k));
            }
        }
        printf("%lld %lld\n",px,py);
        printf("%lld %lld\n",x,y);
    }
    else if(k%2==0&&dis<=2*k){
        printf("2\n");
        for(ll i=0;i<=k;i++){
            if(abs(x-i)+abs(y-(k-i))==k){
                printf("%lld %lld\n",i,k-i);
                break;
            }
            else if(abs(x-i)+abs(y-(k+i))==k){
                printf("%lld %lld\n",i,-k+i);
                break;
            }
            else if(abs(x+i)+abs(y-(k-i))==k){
                printf("%lld %lld\n",-i,k-i);
                break;
            }
            else if(abs(x+i)+abs(y-(k+i))==k){
                printf("%lld %lld\n",-i,-k+i);
                break;
            }
        }
        printf("%lld %lld\n",x,y);
    }
    else if(k%2){
        ll n;
        n=(dis+k-1)/k;
        if(n%2!=dis%2){
            n++;
        }
        printf("%lld\n",n);
        a=k*n-dis;
        for(int i=0;i<n;i++){
            if(!i){
                if(x>0){
                    px-=min(k,a/2);
                }
                else{
                    px+=min(k,a/2);
                }
                if(y>0){
                    py+=k-min(k,a/2);
                }
                else{
                    py-=k-min(k,a/2);
                }
                a-=min(k*2,a);
            }
            else if(a){
                ll by=a/2;
                if(py>y){
                    py+=by;
                }
                else{
                    py-=by;
                }
                if(px>x){
                    px-=k-by;
                }
                else{
                    px+=k-by;
                }
            }
            else{
                ll bx=min(k,abs(x-px));
                if(px>x){
                    px-=bx;
                }
                else{
                    px+=bx;
                }
                if(py>y){
                    py-=k-bx;
                }
                else{
                    py+=k-bx;
                }
            }
            printf("%lld %lld\n",px,py);
        }
    }
    else{
        ll n;
        n=(dis+k-1)/k;
        printf("%lld\n",n);
        a=k*n-dis;
        for(int i=0;i<n;i++){
            if(!i){
                if(x>0){
                    px-=min(k,a/2);
                }
                else{
                    px+=min(k,a/2);
                }
                if(y>0){
                    py+=k-min(k,a/2);
                }
                else{
                    py-=k-min(k,a/2);
                }
                a-=min(k*2,a);
            }
            else if(a){
                ll by=a/2;
                if(py>y){
                    py+=by;
                }
                else{
                    py-=by;
                }
                if(px>x){
                    px-=k-by;
                }
                else{
                    px+=k-by;
                }
            }
            else{
                ll bx=min(k,abs(x-px));
                if(px>x){
                    px-=bx;
                }
                else{
                    px+=bx;
                }
                if(py>y){
                    py-=k-bx;
                }
                else{
                    py+=k-bx;
                }
            }
            printf("%lld %lld\n",px,py);
        }
    }
}