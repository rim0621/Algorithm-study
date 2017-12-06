#### 스트링 매치
1. 브로트포스 : 한 칸씩 옮기면서.. 매칭 O(m*n) m=패턴 / n=스트링
2. DFA 
3. KMP algorithm

### DFA (Deterministic Finite Automaton)
* 시작 스테이트 - accept 스테이트.
* 패턴에 알맞는 단어가 나오면 다음 스테이트.
* 내부적으로는 이차원 배열을 사용(1에서 A나오면 2번으로..)
1. DFA construction
  - x를 구한다. x = [들어온단어][전스테이트의 x] 이다. x는 그 다음스테이션의 기본값으로 세팅하면 된다. 
  - [들어온단어][스테이트]위치에 다음 스테이트 값(i+1)을 넣는다.
  - 반복.. (마지막은 넣지않는다.)

```C++
int x=0;
for(int i=0;i<size+1;i++)
{
     for(int j=0;j<3;j++)
     {
       DFA[j][i]=DFA[j][x];
     }
     x=DFA[wordToInt(p[i])][x];
     if(size-1>=i){
       DFA[wordToInt(p[i])][i]=i+1;
     }

}

```

2. 들어온 스트링을 1에서 만든 행렬대로 따라가서 마지막 스테이트가 나오면 매칭!!
* [code](https://github.com/rim0621/Algorithm-study/tree/master/9.DFA/DFA.cpp)

### KMP algorithm (Knuth-Morris-Pratt)
