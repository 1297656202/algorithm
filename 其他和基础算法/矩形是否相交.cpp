����ж����������ཻ
�ٶ���������һ�Ե����(minx, miny) (maxx, maxy)����ô��������
    rect1{(minx1, miny1)(maxx1, maxy1)}
    rect2{(minx2, miny2)(maxx2, maxy2)}  
�ཻ�Ľ��һ���Ǹ����Σ���������ཻ����rect{(minx, miny) (maxx, maxy)}�ĵ�������ǣ�  
    minx   =   max(minx1,   minx2)  
    miny   =   max(miny1,   miny2)  
    maxx   =   min(maxx1,   maxx2)  
    maxy   =   min(maxy1,   maxy2)  
   
����������β��ཻ����ô����õ��ĵ�������Ȼ���㣺  
  �� minx  >  maxx �� ���� �� miny  >  maxy �� 
		ll minx=max(b[x].minx,b[i].minx);
		ll miny=max(b[x].miny,b[i].miny);
		ll maxx=min(b[x].maxx,b[i].maxx);
		ll maxy=min(b[x].maxy,b[i].maxy);
		if(minx>maxx||miny>maxy)continue;
		else return 0;
