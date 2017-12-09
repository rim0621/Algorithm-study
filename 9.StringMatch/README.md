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
* [code](https://github.com/rim0621/Algorithm-study/tree/master/9.StringMatch/DFA.cpp)
* O(M*단어종류수)
### KMP algorithm (Knuth-Morris-Pratt)
* 롤백을 피하자!!
* 한칸씩옴기면(브로트포스) 오래걸리니깐 어느정도 매칭되는 것을 미리 알고 글로가자!!
1. Maximum Overlap of a Prefix 구하기.
 - 가장긴 proper suffix는 prefix of the prefix 와 같다!(ex AAAA => AAA, AABB => null)
 - 미스매치시 이부분을 다시 사용한다.
 - AAABBAAACB
 - AAAC  //B-C 미스매치
 -      AAAC
2. failure function
 - 패턴의 prefix의 길이!
 - b // k=0
 - ba // k=0
 - bab // k=1
 - baba // k=2
 * fail[] 구하기
```
  aabaabac	0=0으로 세팅
   aabaabac	1=1, a하겹침 (i++,j++ 다음 꺼 안겹침 j=j-1의 요소로 채움)

  aabaabac
    aabaabac	2=0

  aabaabac
     aabaabac    3=1, 하나겹침 , 4=2 하나 또 겹침  5=3 , 6=4, 7은 안겹침 j=(j-1=3)요소

  aabaabac		//j-1(3)의 요소가1 이므로 aa에 i번을 마춤.
        aabaabac  또 아니므로j-1(1-1)=0의 요소 0 에 i번을 마춤
 
  aabaabac
         aabaabac 아님.. 7번짼 0, i++;
```
 
3. [code](https://github.com/rim0621/Algorithm-study/tree/master/9.StringMatch/KMP.cpp)
 - 스트링과 패턴이 매치과 된다면 둘다 한칸씩 옮긴다.
 - 매칭이 안된다면 미리구한 fail에 **j-1**의 k값(길이)를 j로..
 - 다시 매칭... (첫번째, 두번째 반복)










