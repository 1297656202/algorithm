bool check(double x){/ . * }//���x�Ƿ�����ĳ������
double bsearch_3(double l,double r)
{
    //eps��ʾ���ȣ�ȡ������Ŀ�Ծ��ȵ�Ҫ��
    while (r-l>eps)
	{
        double mid=(l+r)/2;
        if (check(mid))r=mid;
    	else l=mid;
	}
    return l;
}
