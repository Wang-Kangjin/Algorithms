/*
 *给定数组a[n]，计算数组b[n],使得b[i]等于a中除了第i个元素之外的所有元素之积
 *不可以用除法，时间复杂度为O(n)
 */

#include <stdio.h>

void calulate(long long *a, long long *b, int num);
void print(long long *a, int num);
int main(){
  long long a[10] ={1,2,3,4,5,6,7,8,9,10};
  long long b[10] ;
  calulate(a, b, 10);
  print(b,10);
}

void calulate(long long *a, long long *b, int num){
  if(num == 0)
    return;
  if(num == 2)
  {
    b[0] = a[1];
    b[1] = a[0];
  }
  long long front[num],back[num];
  int i, j;
  long long front_total=1, back_total=1;
  for(i = 0; i < num; i++)
  {
    j = num-i-1;
    front_total *= a[i];
    back_total  *= a[j];
    front[i] = front_total;
    back[j]  = back_total;
  }
  
  b[0] = back[1]; b[num-1] = front[num-2];
  for(i = 1; i <num-1; i++)
  {
    b[i] = front[i-1] * back[i+1];
  }
}

void print(long long*arr, int n){
  int i;
  for(i = 0; i < n; i++)
  {
    printf("%lld ", arr[i]);
  }
  printf("\n");
}
