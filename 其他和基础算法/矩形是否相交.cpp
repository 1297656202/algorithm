如何判断两个矩形相交
假定矩形是用一对点表达的(minx, miny) (maxx, maxy)，那么两个矩形
    rect1{(minx1, miny1)(maxx1, maxy1)}
    rect2{(minx2, miny2)(maxx2, maxy2)}  
相交的结果一定是个矩形，构成这个相交矩形rect{(minx, miny) (maxx, maxy)}的点对坐标是：  
    minx   =   max(minx1,   minx2)  
    miny   =   max(miny1,   miny2)  
    maxx   =   min(maxx1,   maxx2)  
    maxy   =   min(maxy1,   maxy2)  
   
如果两个矩形不相交，那么计算得到的点对坐标必然满足：  
  （ minx  >  maxx ） 或者 （ miny  >  maxy ） 
		ll minx=max(b[x].minx,b[i].minx);
		ll miny=max(b[x].miny,b[i].miny);
		ll maxx=min(b[x].maxx,b[i].maxx);
		ll maxy=min(b[x].maxy,b[i].maxy);
		if(minx>maxx||miny>maxy)continue;
		else return 0;
