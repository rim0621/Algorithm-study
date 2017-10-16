# Recursion
1. base case : 함수의 값을 직접 계산할 수 있는 단순한 경우(적어도 한 개 이상의 base case가 있어야 함)
2. recursive step : base case가 될 때까지 계속 환산해 나가면서 계산(스택 오버플로우 발생)
3. type of recursion
    * 단일 리컬젼 : 자기 자신을 부르는 곳이 하나 ex) 팩토리얼
    * 바이너리 리컬젼 : 부르는 곳이 두개 ex) 피보나치
    * 멀티 리컬젼 : 부르는 곳이 여러개
<pre><code>
/*factorial*/
int factorial(int n)
{
	if(n<=1)
		return 1;	// base case
	else
		return n*f(n-1); 	// recursive step
}
</code></pre>

4. Function call stack 
    * 함수를 호출 할 때, 지금 실행중인 함수는 지역변수 등 저장
    * 수행이 끝나면 그전 함수로 들어와서 사용하던 지역변수 등 복구
    * call stack : 현재 함수가 가지고 있던 정보를 저장하는 연속적인 메모리 공간
<pre><code>
/* Linear Sum a[]={3,6,4,2,8}, n=배열크기*/
int sum(int a[],int n)
{
	//base case
	if(n==1)
	  return a[0];
	else 	//recursive step
	  return a[n-1]+sum(a,n-1);

}
</code></pre>
