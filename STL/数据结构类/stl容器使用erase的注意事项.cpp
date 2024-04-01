std::vector< int> Vec={0,1,2,3,4};
	for(auto itVec = Vec.begin(); itVec != Vec.end(); )
	{
		if( ( *itVec)==3 )//判断是否是要删除的数字
		{
			itVec = Vec.erase( itVec);
		}
		else
			itVec++;
	}
	for(auto x:Vec)
	cout<<x<<" ";

list和vector的使用方法同理,总之就是利用erase删除节点之后会返回下一个有效的迭代器

map和set也是一样的用法

map<int,int>mapTest={{0,1},{2,2},{1,1}};
	std::map<int,int>::iterator it = mapTest.begin();  
	while(it != mapTest.end())  
	{  
			if((it->first)==0)  
			{  
					it = mapTest.erase(it);  
			}  
			else  
					it++;  
	}
	for(auto [x,y]:mapTest)
	{
		cout<<x<<" "<<y<<endl;
	}