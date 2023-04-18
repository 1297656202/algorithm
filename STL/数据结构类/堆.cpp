priority_queue<ll>q;//大根堆
priority_queue<ll,vector<ll>,greater<ll> >q;//小根堆


struct w{
    ll dis;ll num;
};
bool operator <(w a,w b)
{
    return a.dis>b.dis||(a.dis==b.dis&&a.num>b.num);//这是dis的小根堆,并且会把dis相同的num小的置于堆顶 
}
priority_queue<w>q;
q.push((w){-inf,0});
