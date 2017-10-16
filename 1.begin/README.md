# 문제 해결 과정
1. 문제를 읽고 이해하기
2. 재정의와 추상화
3. 계획 세우기
4. 계획 검증
5. 계획 수행
6. 회고하기 (코드와 함께 자신의 경험을 기록 & 오답 원인 & 다른사람코드확인)

# 간결한 코드 작성하기

<pre><code>
#define FOR(i,n) for(int i=0;i<(n);++i) 
bool hasDuplication(const vector<int>& array){ 
	FOR(i,array.size())
		FOR(j,i)
			if(array[i]==array[j])
				return true;
	return false;
}
</code></pre>
별로지만 오타 발생을 줄여준다.

# 변수 범위의 이해
1. 산술 오버플로
    * 32비트 최대치=2,147,483,647
2. 오버플로 피하기
    * 큰 자료형 사용
    * 연산 순서 바꾸기 ex) 이항계수 (n,r) = n!/(n-r)!r! => (n-1,r-1) + (n-1,r)
# 실수 크기 비교
1. 현실적으로 오차를 생각하기
2. |a-b|/max(|a|,|b|)로 a,b 상대오차를 구하기

<pre><code>
bool relativeEqual(double a,double b){
	return fabs(a-b) <= 1e-8 * max(fabs(a),fabs(b));
}  // 큰 수를 비교할 때는 괜찮지만 작은 숫자들을 비교할때는 문제가 발생
</code></pre>
<pre><code>
//  정대 오차와 상대오차를 모두 이용
bool doubleEqual(double a,double b){
	double diff=fabs(a-b);
	if(diff '<' 1e-10) return true;	
	return diff <= 1e-8 * max(fabs(a),fabs(b));
}
</code></pre>


# 알고리즘 평가
1. 시간
2. 공간

이 둘은 서로 상충하는 경우가 많다.

# 알고리즘의 시간 복잡도 분석
1. 분석
    * 방법1 : 모든 primitive operation(assignment,array indexing, 덧셉,곱,함수호출등)횟수를 계산
    * 방법2 : 핵심적인 연산만 계산
<pre><code>
void insertionSort(int a[], int n)	// 앞에정렬되있으면 자기 위치로 찾아감(앞은 정렬되있고 뒤에몇개만 소팅이 필요할때  유리)
{
  int i, j, value;
  for(i=1; i'<'n; i++)	
  {
    value = a[i];
    for(j=i-1; j>=0; j--)
      if (a[j] > value)
       	a[j+1] = a[j];
      else
       	break;
   a[j+1] = value;
  }
}
</code></pre>
    * Primitive operation T(n) : 4n^2+5n-8 (=, <, ++, [],-, > +, --) = O(n^2)
	for(i=1;	1	1
	i'<'n; i++)	2	2(n-1)
	value=a[i];	2	2(n-1)
	for(j=i-1;	2	2(n-1)
	j>=0;j--	2	n(n-1)
	if(a[j]>value)	2	n(n-1)
	a[j+1]=a[j]	4	2n(n-1)
	a[j+1]=value	3	3(n-1)
    * basic operation T(n) : 0.5n^2-0.5n = O(n^2)
<pre></code>
void bubbleSort(int a[], int n)	// 인접 두개 비교 
{
   int i, j, tmp;
   for(i=0; i'<'n; i++)
     for(j=0; j'<'n-1; j++)
       if (a[j] > a[j+1]) 	//핵심 -> T(n) = n*(n-1)
       {
       		tmp = a[j];
	        a[j] = a[j+1];
 		a[j+1] = a[j];
	}
}
</code></pre>
<pre><code>
void selectionSort(int a[], int n)	//뽑은 수를 가장 작은 것과 바꿈
{
	int i, j, min, tmp;
	for(i=0; i'<'n-1; i++)
	{
 		min = i;
	 	for(j=i+1; j'<'n; j++)
		    if (a[j] '<' a[min]) //핵심 T(n) = (n-1)*n / 2
			 min = j;
	 	if (i != min)
	 	{
		 	tmp = a[i];
		 	a[i] = a[min];
		 	a[min] = tmp;
	 	}
	}
}
</code></pre>
2. 선형 시간 알고리즘
    * 다이어트 현황 파악: 이동 평균 계산하기 // 모든 자료 훑어봄 (n^2) -> n 바꾸기
3. 선형 이하 시간 알고리즘
    * 성형 전 사진 찾기:이진 탐색(소팅필수) // 절반씩 나누어 (logN)
    * 소팅후 찾기 했는데 선형 시간이 아니라면 => 다 보지 않을 것이므로 배열을 갖고 있지 않아도 되게 가운데 있는 것에 대해서만 필요할 때 계산(판단)
4. 지수 시간 알고리즘 


# 해결 알고리즘
1. working backward (역방향 추론) - 무게추를 천칭에 다 올리고 내리면서 해결함..
2. backward induction (후진 귀납법)

# Maximum Contiguous Subsequence Sum
- n개의 정수 a1~an이 주어졌을 때, 연속적인 부분수열의 합이 최대가 되는 구간과 그 구간의 합을 계산하시오.
<pre><code>
// 5 -7 2 3 -4 5 2 -7 8 -7
int maxSubsequenceSum(int a[], int n, int *start, int *end)
{
	int i,j,k;
	int maxSum=0;
	*start=*end=0;
	for(i=0;i'<'n;i++)
	{
	  for(j=i;j'<'n;j++)
	  {
		 int thisSum=0;
		 for(k=i;k<=j;k++)
		 {
			 thisSum+=a[k]; //5, -7+5, 5-7+2...... i가 1일 땐 -7,-7+2.....쭉(max연산 하고 다시 더하는거)
		 }
		 if(thisSum>maxSum)
		 {
			 maxSum=thisSum;
			 *start=i;
			 *end=j;
		 }
	  }
	}
	return maxSum;
}
/* O(n^3)*/
</code></pre>
<pre><code>
// 5 -7 2 3 -4 5 2 -7 8 -7
int maxSubsequenceSum(int a[], int n, int *start, int *end)
{
	int i,j;
	int maxSum=0;
	*start=*end=0;
	for(i=0;i'<'n;i++)
	{
	  int thisSum=0;
	  for(j=i;j'<'n;j++)
	  {

   		 thisSum+=a[j]; //5, -7+5, 5-7+2...... i가 1일 땐 -7,-7+2.....쭉(max연산하고 거기에다가 더하는거)
		 
		 if(thisSum>maxSum)
		 {
			 maxSum=thisSum;
			 *start=i;
			 *end=j;
		 }
	  }
	}
	return maxSum;
}
/* O(n^2)*/
</code></pre>
<pre><code>
// 5 -7 2 3 -4 5 2 -7 8 -7
// 음수가 되는 곳 다음을 처음으로 잡고!!!!!
int maxSubsequenceSum(int a[], int n, int *start, int *end)
{
	int i,j,k;
	int maxSum=0,thisSum=0;
	*start=*end=0;
	for(i=0,j=0;i'<'n;i++)
	{
		 thisSum+=a[j];
		 if(thisSum>maxSum)
		 {
			 maxSum=thisSum;
			 *start=i;
			 *end=j;
		 }
		 else if(thisSum'<'0)	//합이 음수가 되면 앞에꺼는 더하면 손해니깐 버림!
		 {
			 i=j+1;
			 thisSum=0;
		 }
	  
	}
	return maxSum;
}
/* O(n)*/
</code></pre>









































