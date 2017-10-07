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

#변수 범위의 이해
1. 산술 오버플로
    *32비트 최대치=2,147,483,647
2. 오버플로 피하기
    1) 큰 자료형 사용
    2) 연산 순서 바꾸기 ex)이항계수 
       (n,r) = n!/(n-r)!r! => (n-1,r-1) + (n-1,r)






