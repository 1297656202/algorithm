ll erlis()
{ll i,l,r,mid,len=1;
	d[1]=a[1];//d[i]��ʾ����Ϊi���������������һ������СΪd[i]
	for(i=2;i<=n;i++)
	{ 
		l=1;r=len;
		if(d[len]<a[i]){len++;d[len]=a[i];continue;}
		while(l<=r) //���ֲ������½�
		{ 
			mid=(l+r)/2;
			if(d[mid]<a[i])l=mid+1;
			else r=mid-1;
		}
		d[l]=a[i];
	}
	return len;
}

ll erlis()
{ll i,l,r,mid,len=1,ret;
	d[1]=a[1];//d[i]��ʾ����Ϊi���������������һ������СΪd[i]
	for(i=2;i<=n;i++)
	{ 
		l=1;r=len;
		if(d[len]<a[i]){len++;d[len]=a[i];continue;}
		while(l<=r) //���ֲ������½�
		{ 
			mid=(l+r)/2;
			if(d[mid]>a[i]){r=mid-1;ret=mid;}
			else l=mid+1;
		}
		d[ret]=a[i];
	}
	return len;
}
