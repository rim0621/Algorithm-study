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
1. 반복문 (for -> n)
2. 선형 시간 알고리즘
    * 다이어트 현황 파악: 이동 평균 계산하기 // 모든 자료 훑어봄 (n^2) -> n 
3. 선형 이하 시간 알고리즘
    * 성형 전 사진 찾기:이진 탐색(소팅필수) // 절반씩 나누어 (logN)
    * 소팅후 찾기 했는데 선형 시간이 아니라면 => 다 보지 않을 것이므로 배열을 갖고 있지 않아도 되게 가운데 있는 것에 대해서만 필요할 때 계산(판단)
4. 지수 시간 알고리즘 















































