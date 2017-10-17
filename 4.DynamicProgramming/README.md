# Dynamic Programming (동적계획법)
1. 분할정복비법처럼 작은 문제들로 나누어 각각 해답을 찾고 원래 문제의 해답을 계산
2. 하지만 중복이 발생하여 반복연산이 많아 수행시간이 길다. => 메모리제이션으로 해결(반복연산 제거)
    * ex) 최적화 문제(최대,최소) : working backward기법 사용 -> 재귀식으로 정의 (중복계산발생)-> bottom-up 방식 -> 저장할 테이블을 생성 [앞 1~3번째 까지는 최적값을 계산하는 과정이고, 마지막은 최적해답을 계산하는 단계]
### factorial 
<pre><code>
//많은 중복연산을 함. n=100
int f(int n)		//메모리제이션 - 미리저장
{
	int i ,f[100];
	f[0]=1;		//base case
	for(i=1;i<=n;i++)
		 f[i]=i*f[i-1];
	return f[n];
}
</code></pre>
### fibonacci
<pre><code>
int fib(int n)
{
	int i,fib[100];
	fib[0]=0;
	fib[1]=1;
	for(i=2;i<=n;i++)
		 fib[i]=fib[i-1]+fib[i-2];
	return fib[n];
}
</code></pre>
### 직사각형 타일 채우기
* 문제 : 2xN 직사각형이 주어졌을 때, 이 직사각형을 크기가 2x1인 도미노 타일로 채우는 가지수를 계산.
    - 2x1 이 주어졌을 때 1개
    - 2X2 		2개
    - 2x3		3개
    - 2X4		5개
    * 1 단계 : working backward => 2xN의 마지막을 채운다. 1) 한개로 채우면(n-1남음) 2) 두개로 채우면(n-2남음)
    * 2 단계 : 재귀 => c(n) = c(n-1)+c(n-2)
      - c(n) = 1 (n=1), 2 (n=2) , c(n-1)+c(n-2) (n>2)

### 동전교환
* 문제 : 서로 다른 단위으 동전이 주어졌을 때, 거스름돈을 동전의 개수가 최소가 되도록.
    - 1원, 5원, 10원, 21원, 25원 (무제한)
    - 거스름 돈 63원 = {21,21,21}
    * 1 단계 : working backward 
      - 63-1 = 62
      - 63-5 = 58
      - 63-10 = 53
      - 63-21 = 42
      - 63-25 = 38
    * 2 단계 : 재귀식 (1은 동전의 개수?)
      - c(63)=min(c(63-1)+1,c(63-5)+1,c(63-10)+1...) =min(c(63-1),c(63-5),c(63-10)...)+1
      - c(k)=min(k-ci)+1
    * 3 단계 : 최소동전의 개수 계산
      - s[k] : 최소 개수의 거스름돈 동전을 계산하기 위하여 c[k] 를 계산 할 때, 최소값으로 선택된 동전ci를 저장
      - c[k] : k 원을 바꿀 때, 최소 동전의 개수 저장
      - k 0	1	2	3	4	5	6	7 ....	21 (돈)
      - c 0	1	2	3	4	1	2	3 ....	1  (동전 개수)
      - s 0	1	1	1	1	5	1	5? .... 21 ( 사용 동전의 최소값)
<pre><code>
void coinExchange(int coins[], int numDiffCoins, int change, int coinsUsed[],int lastCoin[])
{
	int cents,j;
	coinsUsed[0]=lastCoin[0]=0;
	for(cent=1; cent<=change;cents++)
	{
		 int minCoins,newCoin;
		 minCoins=cents;
		 newCoin=1;
		 for(j=0;j<=numDiffCoins;j++)
		 {
			 if(coins[j]>cents)
			 {
				 continue;
			 }
			 if(coinsUsed[cents-coins[j]]+1 '<' minCoins)
			 {
				 minCoins = coinsUsed[cents-coins[j]]+1;
				 newCoin=coins[j];
			 }
		 }
		 coinsUsed[cents]=minCoins;
		 lastCoin[cents]=newCoin;
	}
}
</code></pre>
    * 4 단계 : 최소동전의 집합 계산(recursive)
<pre><code>
void reconstruct(int change, int lastCoin[])
{
	if(change>0)
	{
		 reconstruct(change-lastCoin[change],lastCoin);
		 printf("%d ", lastCoin[change]);
	}
}
</code></pre>



























