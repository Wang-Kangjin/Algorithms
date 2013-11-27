/*
 *给定坐标序列，求其中在一条直线上的点的数量的最大值
 *用向量叉积（叉积为0，在一条直线上），叉积在计算机图形学中应用比较多
 */

#include <stdio.h>

int searchLine(int (*a)[2] ,int n);
int main(){
  int a[10][2]={
    {0,0},{2,2},{1,1},{3,3},{2,4},{1,4},{4,6},{1,8},{0,1},{4,3}
  };
  printf("%d\n",searchLine(a,10));
  return 0;
}

int searchLine(int (*a)[2], int n){
  int i , j, k;
  int max=0,count=0;
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      count = 2;
      if ( j != i)
	for(k = 0; k < n; k++)
	{
	  if ( k != j && k != i )
	  {
	    // 叉积为0则在一条直线上，ABxAC叉积=(b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y)  
	    int res = (a[j][0]-a[i][0]) * (a[k][1]-a[i][1]) - (a[k][0]-a[i][0]) * (a[j][1]-a[i][1]);
	    if (res == 0)
	      count++;
	  }
	}
      max = count>max?count:max;
    }
  }
  return max;
}
