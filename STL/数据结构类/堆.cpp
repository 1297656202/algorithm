priority_queue<ll>q;//�����
priority_queue<ll,vector<ll>,greater<ll> >q;//С����


struct w{
    ll dis;ll num;
};
bool operator <(w a,w b)
{
    return a.dis>b.dis||(a.dis==b.dis&&a.num>b.num);//����dis��С����,���һ��dis��ͬ��numС�����ڶѶ� 
}
priority_queue<w>q;
q.push((w){-inf,0});
