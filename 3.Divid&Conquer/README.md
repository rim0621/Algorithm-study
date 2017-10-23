# Divide & Conquer (분할정복기법)
1. Recursion 기반 해결기법
2. 분할정복기법의 문제해결 시나리오
    * 분할(Divide) : 주어진 문제를 쪼갬
    * 정복(Conquer) : 나누어진 작은 문제는 재귀로 해결. (재귀적으로 계속 분할해간다)
    * 통합(Combine) : 나눴던 문제들로부터 구한 해답들을 서로 통합하여 원래 문제의 해답을 만든다.
----
1. Top-Down 문제해결 방법
    * Top-Down : 작은 문제로 분할하여 해결하는 방법
2. Recursion으로 알고리즘 구현
    * Top-Down 을 더 작은 문제로 반복해서 분할
----
1. Divide & Conquer
    * 분할정복기법 알고리즘의 정확성 증명 (수학적 귀납법 사용)
    * 분할정복기법 알고리즘의 시간복잡도 계산 
### Tromino 타일 채우기
- 문제 : 한 모퉁이가 없는 2X2로 타일로 채운다. (전체는 N*N-한모퉁이)
- 해결 : 가운데에 타일로 채우고 4개로 분할하면 4개가 다 같은 모양이다. => 반복
<pre><code>
</code></pre>
### Finding Max
- ex) 5 7 1 3 4 | 9 2 0 8 6 => 7 , 9 => 9 
<pre><code>
// a[],left=0,right=a.size()
int recurMax(int a[],int left,int right)
{
	
	if(left==right)
	{
	  return a[left];
	}
	else
	{
	  return max(recurMax(a,left,(left+right)/2),recurMax(a,((left+right)/2)+1,right); 
			//왼쪽으로				//오른쪽으로	
	}
}
// T(n)=n-1  (n아닌가?)
</code></pre>
### Binary Search
<pre><code>
int binarySearch(int a[],int left,int right,int value)
{
  int mid;
  if(left > right)
	return -1;
  else
  {
    mid=(left+right)/2;
    if(a[mid]==value)
    {
      return mid;
    }
    else if(a[mid]>value)
    	return binarySearch(a,left,mid-1,value);	//비교 -> 분할 -> 비교 -> 분할 ... 
    else
	return binarySearch(a,mid+1,right,value);
  }
}
// O(logn)
</code></pre>

### Find Peak value
<pre><code>
</code></pre>
### Merge Sorting
1. Divide : 배열을 각각 n/2 개의 데이터로 만드러진 두개의 부분배열로 분할
2. Conquer : 나누어진 부분 배열에 대하여 재귀적으로 합병 정렬을 수행
3. Combine : 두개의 이미 정렬된 부분 배열을 통합
<pre><code>
#define MAX_SIZE 100
void merge(int a[],int low,int mid,int high)	//합침 combine
{
	int i,j,k;
	int tmp[MAX_SIZE];
	for(i=low;i<=high;i++)
	{
		 tmp[i]=a[i];
	}
	i=k=loq=w;
	j=mid+1;
	while(i'<'mid && j<=high)
	{
		 if(tmp[i]<=tmp[j])		정렬
			 tmp[k++]=tmp[i++];
		 else
			 tmp[k++]=tmp[j++];
	}
	while(i<=mid)
		 a[k++]=tmp[i++];
	while(j<=high)
		 a[k++]=tmp[j++];
}
void mergeSort(int v[],int low,int high)	
{
	int mid;
	if(low==high)
 		return ;
	mid=(low+high)/2;	//divide
	mergeSort(v,low,mid);
	mergeSort(v,mid+1,high);
	merge(v,low,mid,high);
}
void main()
{
	int i,v[MAX_SIZE]={5,6,8,1,4,7,9,10};
	mergeSort(v,0,8);
}
</code></pre>
### Quick Sorting

1. 누군가 한 곳을 뽑아서 피벗을 잡고
2. 다음껄 뽑아 피벗보다 크면 오른 작으면 왼쪽 (파티션)-Divide // 마지막에 pivot이랑 j있는거랑 스왑
    * 피벗, j,i(j+1),  i 갈리키는게 피벗보다 크면 i++// 작으면 j++ 하고 스왑 후 i++	
3. 왼쪽 그룹(하나줄이면서) 오른쪽 그룹(하나 올리면서)  퀵소팅 ㄲ (리컬시브)
    * combine 작업 필요 없다. =>
<pre><code>
int partition(int a[],int low,int high)
{
	int i,j;	//j는 맨처음 i는 그 다음꺼
	int pivot,pivotPos;
	pivot=a[low];	//왼쪽 맨끝 -> 피벗
	j=low;
	for(int i=low+1;i<=high;i++)
	{
		 if(a[i]'<'pivot)
		 {
			 j++;
			 swap(a[i],a[j]);
		 }
	}
	pivotPos=j;
	swap(a[low],a[j]);	//피벗이랑 j있는거랑 스왑.. 그럼 j있는 것은 소팅완료!!
	return pivotPos;
}	//T(n)=n-1
void quickSort(int v[],int low,int high)
{
      if(high>low)
      {
	int pos=partition(v,low,high);
	quickSort(v,low,pos-1);
	quickSort(v,pos+1,high);	
      }
}
void main()
{
	int i, v[]={3,6,1,5,2,9,7};
	quickSort(v,0,v.size()-1);
}
</code></pre>	
    * 미리 정렬된 데이터가 입력되는 것이 가장 worst cast 이다.
    * 결국 피벗이 가장 중간수가 잡히면 효율적이다.

#### Quick Sorting  VS  Merge Sorting

* 빅오 표기법 속에 숨겨진 큌 정렬의 상수항이 꽤 괜찮기 때문에 퀵 정렬을 선호한다. 실생활에서 퀵정령은 머지정렬보다 성능이 좋으며, 선택 정렬과 삽입 정렬보다 훨씬 좋다. 퀵소트는 머지소트처럼 추가 저글링이 없다.
* 머지는 항상 이동하고, 퀵은 경우에 따라 이동하기 때문에 퀵이 더 좋다.
		   퀵			   머지
* divide	파티션,피벗,O(n)		간단,반으로 나눈다.
* conquer	재귀			재귀
* combine	필요없음		머지수행,conquer단계에서 정렬된 두 배열을 병합 O(n)

#### Bolts & Nuts
* 문제 : 크기가 모두 다른 n개의 너트와 그에 맞는 볼트가 있다. n개의 볼트-너트 조합을 만들어라.
    - 너트 끼리는 비교 불가, 너트-> 볼트를 확인해서 큰지 작은지 맞는지를 판반 (볼트도->너트)
* 해결 : 
    1) 볼트 하나 잡고 너트와 다들 껴본후 맞은거 를 찾음
    2) 찾은 너트와 남어지 볼트를 비교해서 큰, 작은 으로 나눔
    3) 찾은 볼트로 너트 도 그룹을 나눔
    4) 양쪽 리컬시브

#### 카라츠바의 빠른 곱셈 알고리즘
* 1234 * 5678
<pre><code>
// 곱 알고리즘
void normalize(vector<'int>& num){
	num.push_back(0);
	for(int i=0;i<'num.size();++i)
	{
		 if(num[i]<'0){
			 int borrow=(abs(num[i])+9)/10;
			 num[i+1]-=borrow;
			 num[i]+=borrow*10;
		 }
		 else
		 {
			 num[i+1]+=num[i]/10;
			 num[i]%=10;
		 }
	}
	if(num.back()==0) num.pop_back();
}
vector<'int> multiply(const vector<'int>& a, const vector<'int>& b){
	vector<'int> c(a.size()+b.size()+1,0);
	for(int i=0;i<'a.size(); ++i)
		 for(int j=0;j<'b.size();++j)
			 c[i+j]+=a[i]*b[j];
	normalize(c);
	return c;
}
</code></pre>
<pre><code>
void addTO(vector<'int>& a,const vector<'int>& b, int k);
void subFrom(vector<'int>& a, const vector<'int>& b);
vector<'int> karatsuba(const vector<'int>& a,const vector<'int>& b){
	int an= a.size(), bn=b.size();
	if(an<'bn) return karatsuba(b,a);
	if(an==0||bn==0) return vector<'int>();
	if(an<=50) return multiply(a,b);
	int half=an/2;
	vector<'int> a0(a.begin(),a.begin()+half);
	vector<'int> a1(a.begin()+half,a.end());
	vector<'int> b0(b.begin(),b.begin()+min<'int>(b.size(),half));
	vector<'int> b1(b.begin()+min<'int>(b.size(),half),b.end());

	vector<'int> z2=karatsuba(a1,b1);
	vector<'int> z0=karatsuba(a0,b0);
	addTo(a0,a1,0);
	addTo(b0,b1,0);
	vector<'int> z1=karatsuba(a0,b0);
	subFrom(z1,z0);
	subFrom(z1,z2);
	addTo(ret,z0,0);
	addTo(ret,z1,half);
	addTo(ret,z2,half+half);
	return ret;
}
</code></pre>
#### qaudtreeMirror.cpp  - ????
* 베이스 케이스 :  w,b 이면 칠하고 종료
	       : x 이면 decompress로 나눔(재귀)

#### fence.cpp
* 문제 : 버리는 울타리에서 잘라낼 수 있는 많은 직사각형 중 가장 넓은 직사각형(높이는 주어지고, 너비는1)
    .
.   . .  여기
.   . .	여기	=> 6
. . . .  여기






















