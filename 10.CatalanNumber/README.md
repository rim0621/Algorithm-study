# 카탈란 수
[코드링크](https://github.com/rim0621/Algorithm-study)
* 쌍을 이루는 것들을 나열하는 모든 경우의 수.

#### 카탈란 수열 문제들
* 모든 괄호 짝
* 산 만들기
* 대각선 피해가기
* 다각형을삼각형으로 나누기

#### 모든 괄호 짝
* n쌍의 괄호가 잘 짜놓은 방법을 Cn.
* (A)B => A에 괄호가 k쌍 있다면 B에는 n-1-k쌍이 있다.(트리?)
* C1= C0C0
* c2= C0C1+C1C0
* c3= C0C2+C1C1+C0C2 ...
* Cn= Σ Ci*Cn-1-i (i는 0~n-1)

##### Code
```C++
void PrintBracket(bool *state,int size)
{
	for(int i=1;i<size;i++)
	{
		if(state[i])
		{
			cout<<"(";
		}
		else
		{
			cout<<")";
		}
	}
	cout<<endl;
}
void Bracket(bool *state, int size,int start, int end)
{
	if(start==0&&end==0)	//베이스케이스
	{
		PrintBracket(state,size);
		return ;
	}
	if( start>0){				//괄호가 먼저 열리니깐 열림이 많은 것부터 뽑는다.
		state[size]=true;
		Bracket(state,size+1,start-1,end+1);
	}
	if(end>0){
		state[size]=false;
		Bracket(state,size+1,start,end-1);
	}
}

int main()
{
	int n;
	cin>>n;
	bool state[2*100];	//n은 최대 100개, 괄호를 열것인지 닫을것인지 넣는다.
	Bracket(state,1,n,0);
	return 0;
}
```
