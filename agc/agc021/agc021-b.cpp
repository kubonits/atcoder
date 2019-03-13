#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
double EPS=1e-10;

double add(double a,double b){
    if(abs(a+b)<EPS*(abs(a)+abs(b))) return 0;
    return a+b;
}

//二次元ベクトル構造体
struct P{
    double x,y;
    P(){}
    P(double x, double y) : x(x),y(y){
    }
    P operator + (P p){
        return P(add(x,p.x),add(y,p.y));
    }
    P operator - (P p){
        return P(add(x,-p.x),add(y,-p.y));
    }
    P operator * (double d){
        return P(x*d,y*d);
    }
    double dot(P p){    //内積
        return add(x*p.x,y*p.y);
    }
    double det(P p){    //外積
        return add(x*p.y,-y*p.x);
    }
};

//辞書順で比較
bool cmp_x(const P& p,const P& q){
    if(p.x!=q.x) return p.x<q.x;
    return p.y < q.y;
}

vector<P> convex_hull(P* ps,int n){
    sort(ps,ps+n,cmp_x);
    int k=0;                //凸包の頂点数
    vector<P> qs(2*n);   //構築中の凸包
    //下側凸包の作成
    for(int i=0;i<n;i++){
        while(k>1 && (qs[k-1]-qs[k-2]).det(ps[i] - qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    //上側凸包の作成
    for(int i=n-2, t=k ;i>=0;i--){
        while(k>t && (qs[k-1]-qs[k-2]).det(ps[i] - qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    qs.resize(k-1);
    return qs;
}

double dist(P p, P q){
    return (p-q).dot(p-q);
}

int main(){
    double R=100000000000000.0,ans[100]={},pi,co,deg;
    vector<P> q;
    P p[100],pp[100];
    pi=atan(1)*4;
    int n,m,f;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&p[i].x,&p[i].y);
        pp[i]=p[i];
    }
    q=convex_hull(pp,n);
    m=q.size();
    for(int i=0;i<n;i++){
        f=-1;
        for(int j=0;j<m;j++){
            if(p[i].x==q[j].x&&p[i].y==q[j].y){
                f=j+m;
            }
        }
        if(f!=-1){
            co=(q[(f-1)%m]-q[f%m]).dot(q[(f)%m]-q[(f+1)%m])/sqrt(dist(q[(f-1)%m],q[f%m])*dist(q[f%m],q[(f+1)%m]));
            ans[i]=acos(co)/(2*pi);
        }
        else{
            ans[i]=0.00000000000;
        }
        printf("%.7f\n",ans[i]);
    }
}