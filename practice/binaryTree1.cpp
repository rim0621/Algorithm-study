#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int weight[(1<<21)+1];

int chageWeight(int p,int maxNum){
    int left = 2*p+1;
    int right = 2*p+2;
    int lsum=0;
    int rsum=0; 
    if(left > maxNum || right > maxNum) 
    {	
	return weight[p];
    }
    else
    {
       lsum = chageWeight(left,maxNum); 
       rsum = chageWeight(right,maxNum);

      if(lsum < rsum){
          weight[left] += rsum - lsum;
      }
      else if(lsum > rsum){
          weight[right] += lsum - rsum;
      }
    }
    return weight[p] + max(lsum, rsum);
}

int main(){

  int numcase;
  cin>>numcase;
  for(int num=0;num<numcase;num++){
    int level;
    int maxNum;
    scanf("%d", &level);
    maxNum = (1<<(level+1))-2;
    for(int i=1; i<=maxNum; ++i) 
	scanf("%d", &weight[i]);
    
    chageWeight(0,maxNum);

    int answer = 0;
    for(int i=1; i<=maxNum; ++i)
	 answer += weight[i];

    printf("%d\n", answer);
   } 
   return 0;
}
