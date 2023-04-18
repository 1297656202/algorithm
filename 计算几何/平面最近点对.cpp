struct Point
{
    double x, y;
    Point(double x = 0, double y = 0):x(x), y(y){ }
};
Point p[N];
int tmp[N], n;
bool cmp(const Point &a, const Point &b){
        if(a.x == b.x)return a.y < b.y;
        return a.x < b.x;
}
bool cmps(const int &a, const int &b){
    return p[a].y < p[b].y;
}
double get_dist(int i, int j)
{
    return sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
}
double merge(int l, int r)
{
    double d = DINF;
    if(l == r)return d;
    if(l + 1 == r)return get_dist(l, r);
    int mid = l + r >> 1;
    double d1 = merge(l, mid), d2 = merge(mid + 1, r);
    d = min(d1, d2);
    int tot = 0;
    for(int i = l; i <= r; ++ i)
        if(fabs(p[mid].x - p[i].x) <= d)
            tmp[++ tot] = i;
    sort(tmp + 1, tmp + 1 + tot, cmps);

    for(int i = 1; i <= tot; ++ i)
        for(int j = i + 1; j <= tot; ++ j){
            if(fabs(p[tmp[j]].y - p[tmp[i]].y) > d)break;
            d = min(d, get_dist(tmp[i], tmp[j]));
        }
    return d;
}
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    sort(p + 1, p + 1 + n, cmp);
    double ans = merge(1, n);
    printf("%.4f\n", ans);
    return 0;
}


