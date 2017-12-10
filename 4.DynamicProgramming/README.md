# Dynamic Programming (동적계획법)
1. 분할정복비법처럼 작은 문제들로 나누어 각각 해답을 찾고 원래 문제의 해답을 계산
2. 하지만 중복이 발생하여 반복연산이 많아 수행시간이 길다. => 메모리제이션으로 해결(반복연산 제거)
    * ex) 최적화 문제(최대,최소) : working backward기법 사용 (top-down 방법으로)-> 재귀식으로 정의 (중복계산발생)-> bottom-up 방식 -> 저장할 테이블을 생성 [앞 1~3번째 까지는 최적값을 계산하는 과정이고, 마지막은 최적해답을 계산하는 단계]
### factorial 
```
//많은 중복연산을 함. n=100
int f(int n)		//메모리제이션 - 미리저장
{
	int i ,f[100];
	f[0]=1;		//base case
	for(i=1;i<=n;i++)
		 f[i]=i*f[i-1];
	return f[n];
}
```
### fibonacci
```
int fib(int n)
{
	int i,fib[100];
	fib[0]=0;
	fib[1]=1;
	for(i=2;i<=n;i++)
		 fib[i]=fib[i-1]+fib[i-2];
	return fib[n];
}
```
### 직사각형 타일 채우기
* 문제 : 2xN 직사각형이 주어졌을 때, 이 직사각형을 크기가 2x1인 도미노 타일로 채우는 가지수를 계산.
    - 2x1 이 주어졌을 때 1개
    - 2X2 		2개
    - 2x3		3개
    - 2X4		5개
    * 1 단계 : working backward => 2xN의 마지막을 채운다. 1) 한개로 채우면(n-1남음) 2) 두개로 채우면(n-2남음)
    * 2 단계 : 재귀 => c(n) = c(n-1)+c(n-2)
      - c(n) = 1 (n=1), 2 (n=2) , c(n-1)+c(n-2) (n>2)
### 이항계수
```
B[n][k])=  1   k=0 or k=n
	B[n-1][k-1]+B[n-1][k] 0<k<n

int binCoeff(int n, int k)
{
	int i,j;
	int B[MAX][MAX];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=min(i,k);j++)
		{
			if(j==0 || j==i)
				B[i][j]=1;	//base case;
			else
				B[i][j]=B[i-1][j-1]+B[i-1][j];
		}
	}
	return B[n][k];
}
```
### 동전교환
* 문제 : 서로 다른 단위의 동전이 주어졌을 때, 거스름돈을 동전의 개수가 최소가 되도록.
    - 1원, 5원, 10원, 21원, 25원 (무제한)
    - 거스름 돈 63원 = {21,21,21}
    * 1 단계 : working backward 
```
      - 63-1 = 62
      - 63-5 = 58
      - 63-10 = 53
      - 63-21 = 42
      - 63-25 = 38
```
    * 2 단계 : 재귀식 (1은 동전의 개수?)
```
      - c(63)=min(c(63-1)+1,c(63-5)+1,c(63-10)+1...) =min(c(63-1),c(63-5),c(63-10)...)+1
      - c(k)=min(k-ci)+1
```
    * 3 단계 : 최소동전의 개수 계산
```
      - s[k] : 최소 개수의 거스름돈 동전을 계산하기 위하여 c[k] 를 계산 할 때,c[k-ci]를해서 최소값으로 선택된 동전ci를 저장(여러개면 아무거나 선택가능)
      - c[k] : k 원을 바꿀 때, 최소 동전의 개수 저장
      - k 0	1	2	3	4	5	6	7 ....	21 (돈)
      - c 0	1	2	3	4	1	2	3 ....	1  (동전 개수)
      - s 0	1	1	1	1	5	1	5 .... 21 ( 사용 동전의 최소값)
			 			ex) 7 일때
							7-c1=7-1=6  c[6]=2개
							7-c2=7-5=2  c[2]=2개 같으므로 아무거나 선택
									c[2]선택하면 s[7]=5
```
```C++
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
```
    * 4 단계 : 최소동전의 집합 계산(recursive)	(?)
```
void reconstruct(int change, int lastCoin[])
{
	if(change>0)
	{
		 reconstruct(change-lastCoin[change],lastCoin);
	 	 printf("%d ", lastCoin[change]);
	}
}
```
* [code](https://github.com/rim0621/Algorithm-study/tree/master/4.DynamicProgramming/exchangeCoin.cpp)
### 동전교환-2
* cn 의 동전이 포함된 경우, 포함되지 않는 경우
* 재귀:
```
N(n,k)=N(n-1,k)+N(n,k-cn)
       cn 포함안됨 / cn 포함 
	
n가지 동전 종류, k거스름돈
N(n,k) = 0 n=0 and k>0	//bc
	 1 k=0		//bc
	 0 k<'0		//bc
	 N[n-1][k]+N[n][k-cn]	//recursive step

N[][]의 의미는 무엇인가??
```

### LCS 
* Longest Common Subsequence 재귀
```
	- L(m,n) =
		 	 0 			(n=0 or m=0)
	 	 	 L(m-1,n-1)+1		(m,n>0 and sm=tn)
	 	 	 max(L(m,n-1),L(m-1,n))	(m,n>0 and sm!=tn)
```
* [code 백준_9251](https://github.com/rim0621/Rookie/blob/master/9251_LCS.cpp)
* [code LCS](https://github.com/rim0621/Algorithm-study/tree/master/4.DynamicProgramming/LCS.cpp)
* LCS 정답 순서 스트링 보기! 
![Alt text](/img/LCS.png)
* 대각 선에서 내려올 때는 재귀식 두번째 경우, 왼쪽에서 또는 위에서 오는 것은 재귀식 마지막 경우
```
#define MAX:_LENGTH 101
#define MAX(a,b) ((a)>(b)?(a):(b))
int L[MAX_LENGTH][MAX_LENGTH], S[MAX_LENGTH][MAX_LENGTH]; //0으로 초기화
// L[][]은 sm 그리고 tm의 최장길이를 저장... S[][]는 LCS를 구하기 위한 저장 정보... 
int lengthLCS(char s[],char t[], int m, int n)
{
	int i,j;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(s[i-1]==t[j-1])
			{
				L[i][j]=L[i-1][j-1]+1; // 대각선으로 부터 +1 //2번째 경우
				S[i][j]=0;
			}
			else
			{
				L[i][j]=MAX(L[i][j-1],L[i-1][j]);
				if(L[i][j]==L[i][j-1])
					S[i][j]=1;	//위에서	
				else
					S[i][j]=2;	옆에서
			}
		}
	}
	return L[m][n];
}
```
* LCS 프린트
```
void printLCS(char s[], char t[],int m,int n)
{
	if(m==0 || n==0)
		return ;
	if(S[m][n]==0)
	{
		printLCS(s,t,m-1,n-1);
		printf("%c",s[m-1]);
	}
	else if(S[m][n]==1)
		printLCS(s,t,m,m-1);
	else if(S[m][n]==2)
		printLCS(s,t,m-1,n);
}
```
### 연쇄행렬 최소곱셈 알고리즘
* 재귀
	- M(i,j) =
	 	- min(M(i,k)+M(k+1,j)+di-1,dk,dj)	if(1<=i<'j<=m)
	 	- 0				if(i=j)
# 메모이제이션
* 입력이 고정되어 있을 때 그 결과가 항상 같을 (참조적 투명성) 때 만 가능.
1. 기저 사례를 제일 먼저 처리.
2. 반환값을 잘 생각하여 초기화.
* 시간 복잡도 분석
	- 존재하는 부분 문제의수 * 한 부분 문제를 풀 때 필요한 반복문의 수행 횟수
# 동적 계획법 레시피
1. 주어진 문제를 완전 탐색을 이용
2. 중복된 부분 문제를 한번만 계산하도록 메모이제이션을 사용
```
//외발 뛰기 완전탐색
int n,board[100][100];
bool jump(int y,int x)
{
	if(y>=n || x>n) return false; // over board
	if(y==n-1 && x==n-1) return true;
	int jumpSize=board[y][x];
	return jump(y+jumpSize,x) || jump(y,x+jumpSize);
}
```
```
// 동적 계획법으로
int n,board[100][100];
int cache[100][100];
int jump2(int y,int x)
{
	if(y>=n || x>n) return 0; // over board
	if(y==n-1 && x==n-1) return 1; //도달
	int& ret=cache[y][x]; //ret 은 cache[y][x]의 참조형, ret의 값이 바뀌면 cache도 바뀜!!!!
	if(ret!=-1) return ret;
	int jumpSize=board[y][x];
	return ret=(jump(y+jumpSize,x) || jump(y,x+jumpSize));
}
```

#### 와일드카드 Wildcard.cpp , WildcardDynamic.cpp 
* 문제
	- *=0글자 이상의 어떤 문자열에도 대응
	- ?=한 글자만 대응
## 최적문제
* 직관적이지 않은 경우에는 대개 귀류법 혹은 대우를 이용하여 증명한다.
#### 최대 증가 부분 수열
* 완전 탐색 방법 : 숫자 하나씩으로 조각낸 뒤, 한 조각에서 숫자 하나씩을 선택하는 완전 탐색. 길이구하기 -> 집합의 증가 부분 수열을 만든 뒤 가장 긴것 반환.
<pre><code>
int lis(const vector<'int>& A)
	if(A.empty()) return 0;
	int ret=0;
	for(int i=0; i<'A.size();++i)
	{
		 vector<'int> B;
		 for(int j=i+1;j<'A.size();++j)
		 {
		 	if(A[i]<'A[j])
		 	{
		 		B.push_back(A[j]);
		 	}	
		 }
		 ret=max(ret,1+lis(B));
	}
	return ret;

</code></pre>
* 동적계획법
<pre><code>
int n;
int cache[100],S[100];
int lis2(int start){
	int& ret = cache[start];
	if(ret!=-1)return ret;
	
	ret=1;
	for(int next=start+1; next<'n;++next)
	{
		 if(S[start]<'S[next])
		 	ret=max(ret,lis2(next)+1);
	}
	return ret;

</code></pre>





















