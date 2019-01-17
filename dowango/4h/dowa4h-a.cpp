#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int h,m,s,c1,c2,l1,l2,r1,r2,cnt=1,t;
    scanf("%d%d%d",&h,&m,&s);
    scanf("%d%d",&c1,&c2);
    h%=12;
    while(c1>=0&&c2>=0){
        t=((h*60)+m)*60+s;
        if(t%3600==3599||((m*60+s>s*60)&&(m*60+s+1<=60*(s+1)))){
            //printf("%d %d\n",m*60+s+1,(s+1)*60);
            c1--;
            if(c1==0&&c2==0){
                if(t%3600==3599){
                    printf("%d ",cnt+1);
                }
                else{
                    printf("%d ",cnt);
                }
            }
        }
        if(t==43199||((t>12*(m*60+s))&&(t+1<12*(m*60+s+1)))){
            c2--;
            if(c1==0&&c2==0){
                if(t==43199){
                    printf("%d ",cnt+1);
                }
                else{
                    printf("%d ",cnt);
                }
            }
        }
        cnt++;
        s++;
        if(s==60){
            s=0;
            m++;
            if(m==60){
                m=0;
                h++;
                if(h==12){
                    h=0;
                }
            }
        }
    }
    if(c1*c2==0||c1*c2==1){
        printf("%d\n",cnt-2);
        //printf("%d %d %d\n",h,m,s);
    }
    else{
        printf("-1\n");
    }
}