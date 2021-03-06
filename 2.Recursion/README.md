# Recursion
-> 자신이 수행할 작업을 유사한 형태의 여러 조각으로 쪼갠 뒤 그 중 한 조각을 수행하고, 나머지를 자기 자신을 호줄해 실행하는 함수를 가리킨다.(완전탐색을 구현할 때 유용)
1. base case : 함수의 값을 직접 계산할 수 있는 단순한 경우(적어도 한 개 이상의 base case가 있어야 함)
2. recursive step : base case가 될 때까지 계속 환산해 나가면서 계산(스택 오버플로우 발생)
3. type of recursion
    * 단일 리컬젼 : 자기 자신을 부르는 곳이 하나 ex) 팩토리얼
    * 바이너리 리컬젼 : 부르는 곳이 두개 ex) 피보나치
    * 멀티 리컬젼 : 부르는 곳이 여러개
4. Function call stack
    * 함수를 호출 할 때, 지금 실행중인 함수는 지역변수 등 저장
    * 수행이 끝나면 그전 함수로 들어와서 사용하던 지역변수 등 복구
    * call stack : 현재 함수가 가지고 있던 정보를 저장하는 연속적인 메모리 공간

### factorial
<pre><code>
int factorial(int n)
{
	if(n<=1)
		return 1;	// base case
	else
		return n*f(n-1); 	// recursive step
}
</code></pre>
### Linear Sum
<pre><code>
/*  a[]={3,6,4,2,8}, n=배열크기*/
int sum(int a[],int n)
{
	//base case
	if(n==1)
	  return a[0];
	else 	//recursive step
	  return a[n-1]+sum(a,n-1); //main 제외하고 최대 깊이 = 5

}
</code></pre>
### Reversing Array
<pre><code>
//양 쪽 끝에 (i=0,j=배열개수-1)인덱스들을 잡고 스왑... 결국 재귀
void reverseArray(int a[],int i, int j)
{
	if(i '<' j)	//recursion
	{
		swap(a[i],a[j]);
		reverseArray(a,i+1,j-1);
	}


}
</code></pre>
### Computing Powers
* 16 = 2^4 = 2^2^2 = (2^2)^2
* 256 = 2^8 = 2^2^3 = (((2^2)^2)^2)
    - n=0		1
    - n>0 is odd	x*p(x,(n-1)/2)^2
    - n>0 is even	p(x,n/2)^2
<pre><code>
double p(double x,int n)
{
	double y;
	if(n==0)
		 return 1.0;
	else if(n%2==1)
	{
		 y=p(x,(n-1)/2);
		 return x*y*y;
	}
	else
	{
		 y=p(x,n/2);
		 return y*y;
  	}
}
</code></pre>
### 최대 공약수 (유클리드 호제법)
<pre><code>

 /*   a % b =r -> a=b, b=r 반복... r=0 일 때 까지   */
int gcd(int a,int b)
{

	if(b==0)
	  return a;	//base case
	else
       	  return gcd(b,a&b);	//a=b, b=r....
}
</pre></code>
### string reversal
<pre><code>
// str[]="StrReversal";
void printReversal(char str[],int index)	//void는 baseCase가 없어도 되나보나(?)
{
	if(str[index]!=NULL){
	  printReversal(str,index+1);
	  print("%c",str[index]);
	}
}
</code></pre>
### 진수 변환
<pre><code>
#include<bits/stdc++.h>
using namespace std;

void baseConversion(int n, int base)
{
        static char baseTable[]="0123456789abcdef";
        if(n>=base)
          baseConversion(n/base,base);
        printf("%c",baseTable[n%base]);
}
main()
{
        int num=1234567;
        baseConversion(num,16); //16 진수
        printf("\n");
}
</code></pre>
### Recursive Insertion Sorting
    * 0 1 3 5 7 8 / 2 4 (정렬됨/아직정렬안됨)
    * 2를 1과 3 사이.. 4를 3과 5 사이로 삽입!
<pre><code>


</code></pre>
### permutation
    * n 개의 서로 다른 문자로 만들어진 스트링이 주어졌을 때, 이문자열에 속하는 문자들의 모든 순열
    * 처음에 맨 앞에 올 수 있는 걸로 스왑해서 경우의수 만들고 -> 첫번째꺼 제외 뒤에껏들중 제일 앞에있는것을 스왑해서 경우의 수를 만들고 -> 첫,두번째꺼 제외하고 뒤에껏들중 제일 앞에있는것을 스왑.... 반복 (남은게 하나일 때 까지)
    * 코딩 : 스왑 -> 펄미 -> 스왑(복구 다음 꺼 위해서..) (깊이먼저..)
    * "abc"
       -abc
		 -abc
		 -acb //뒤에서 두개 스왑
       -bac
		 -bac
		 -bca
       -cba
		 -cba
		 -cab


<pre><code>
using namespace std;
void permuteString(string str,int begin,int end)
{

       int range=end-begin;
       if(range==1)
	  printf("%s",str);
       else
       {
       	for(int i=0; i'<'range;i++){
         	swap(str[begin],str[begin+i]);
	         permuteString(str,begin+1,end);
      		swap(str[begin],str[begin+i]);// 바껴있으니깐 다음 껄 위해서 다시 원상복귀.
      	}
      }
}


int main()
{
       string str="abcd";
       permuteString(str,0,str.size());
}
</code></pre>
### Hanoi Tower
    * 문제 : 가장 왼쪽에 꽂혀있는 모든 원판을 가장 오른쪽 기둥으로 옮긴다.
       - 한번에 한개의 원판만 옮김
       - 한개의 원판을 옮길 때는 어떤 기둥에 꽂혀있는 원판의 가장 위에 놓여져 있는 원판을 다른 기둥에 꽂혀있는 원판의 가장 위에 놓는다.
       - 크기가 큰 원판이 작은 원판 위에 놓여져서는 안된다.
    * 해결
      - 1번 기둥에 쌓여져있는 n-1개의 원판을 모두 2번 기둥으로 옮긴다.
      -	1번 기중에 남아 있는 가장 큰 원판을 3번기둥으로 옮긴다.
      - 2번 기중으로 옮겨진 n-1개의 원판을 모두 3번으로 옮긴다.(리컬)
<pre><code>
void Hanoi(int n, int a, int b, int c)
{
	if(n>0)
	{
 		Hanoi(n-1,a,c,b);
 		printf("move from %d to %d\n",a,c);
 		Hanoi(n-1,b,a,c);
	}
}

int main()
{
	int numDisks=5;
	Hanoi(numDisks,1,2,3);

}
</code></pre>
### Flood Fill
    * 문제 : 연속적인 범위를 마우스 클릭하면 같은 색으로 채우기
<pre><code>
#define SIZE 9
using namespace std;
void floodFill(char fig[][SIZE+1],int x,int y, char oldColor, char newColor)
{
       if(fig[x][y]!=oldColor)
 	       return ;
       else
       {
	            fig[x][y]=newColor;
	            //왼,오른,아래,위
	            floodFill(fig, x-1,y,oldColor,newColor);
	            floodFill(fig, x+1,y,oldColor,newColor);
	            floodFill(fig, x,y-1,oldColor,newColor);
	            floodFill(fig, x,y+1,oldColor,newColor);
       }
}

int main()
{
       //why y is +1 ???
       char fig[][SIZE+1]={
"*********", "*...*...*", "*...*...*","*..*....*", "***...***",
"*....*..*","*...*...*", "*..*....*", "*********"};


       for(int i=0;i'<'SIZE;i++)
       {
         	for(int j=0;j'<'SIZE;j++)
          	{
		  printf("%c ",fig[i][j]);

        	}
               	  printf("\n");
       }
       floodFill(fig,4,4,'.','+');

       for(int i=0;i'<'SIZE;i++)
       {
         	for(int j=0;j'<'SIZE;j++)
          	{
		  printf("%c ",fig[i][j]);

        	}
               	  printf("\n");
       }


}
</code></pre>
### Knight's Tour Problem
    * 문제 : 기사(말) 이 임의의 위치에 놓여졌는데 모든 64개의 격자를 방문하도록(방문한곳은 NO)
<pre><code>
</code></pre>
### Binary Tree
<pre><code>

struct node{
  char data;
  struct node* left;
  struct node* right;
};

node* createNode(char data)
{
  node *n=(node *)malloc(sizeof(node));
  n->left=NULL;
  n->right=NULL;

  n->data=data;

  return n;
}

void inOrder( node* root)
{
  if(root==NULL)
  {
     return ;
  }
  else
  {
    inOrder(root->left);
    printf("%c ",root->data);
    inOrder(root->right);
  }
}
void preOrder(node* root)
{
  if(root==NULL)
  {
    return ;
  }
  else
  {
    printf("%c ",root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
}
void postOrder(node* root)
{
  if(root==NULL)
  {
    return ;
  }
  else
  {
    postOrder(root->left);
    postOrder(root->right);
    printf("%c",root->data);
  }
}
int size(node *root)
{
	if(root==NULL)
		 return 0;
	else
		 return (size(root->left) +1 +size(root->right));
}
int max(int a, int b)
{
  if(a>b)
	return a;
  else
	return b;
}
int height(node *root)
{
       if(root==NULL)
	{
	 	return -1; //처음노드가 0이므로.. -1 로 하나 빼준다.
	}
	else
	{
       		return max(height(root->left),height(root->right))+1;		
	}
}


void mirror( node* root) {
  if (root==NULL) {
    return;
  }
  else {
    struct node* temp;

    // 밑으로 간다!
    mirror(root->left);
    mirror(root->right);

    // swap
    printf("swap %c \n",root->data);
    temp = root->left;
    root->left = root->right;
    root->right = temp;
  }
}

int main()
{
	node *root=createNode('a');
	root->left = createNode('b');
	root->right = createNode('c');
	root->left->left=createNode('d');
	root->left->left->right=createNode('g');
	root->right->right=createNode('f');
	root->right->left=createNode('e');
	printf("size = %d\n",size(root));
	printf("height= %d\n",height(root));
	preOrder(root);
	printf("\n");
	mirror(root);
	preOrder(root);
	printf("\n");
}
</code></pre>
### Binary Tree with Weight
<pre><code>

struct node{
	int weight;
	struct node* left;
	struct node* right;
}

int sumOfWeight(struct node *root)
{
	if(root==NULL)
	{
		 return 0;
	}
	else
	{
		 return sumOfWeight(root->left)+sumOfweight(root->right)+root->weight;
	}
}
int maxPathWeight(struct node *root)
{
	if(root==NULL)
		 return 0;
	else
	{
		 int leftWeight,rightWeight;
		 leftWeight=root->wegiht+maxPathWeight(root->left);
		 rightWeight=root->wegiht+maxPathWeight(root->right);
		 return max(leftWeight,rightWeight);
	}
}

</code></pre>
#### picnic.cpp
* 재귀+완전탐색 : 모든 경우의 수를 조건에 맞게 찾는다.
#### BoardCover.cpp
1. 빈곳을 찾는다.
2. 빈곳을 기준으로 4모형이 보드를 초과하는지 체크한다.
3. 놓는다. 가능을 반환한다.
4. 재귀
## 완전 탐색을 이용한 최적화문제
* 가능한 답을 모두 생성해 보고 그중 가장 좋은 것을 찾아내는 방법.
#### 여행하는 외판원 문제
1. n개의 도시를 모두 방문하는 경로중 가장 짧은 것
    * 0부터 시작해면 n-1개를 방문할수있는 경우의 수는 (n-1)!
<pre><code>
int n;
double dist[MAX][MAX];

double shortestPath(vector<'int>& path, vector<'bool>& visited, double currentLength){
	if(path.size()==n)
		 return currentLength + dist[path[0]][path.back()];
	double ret=INF;
	for(int next=0;next'<'n;++next)
	{
		 if(visited[next]) continue;
		 int here=path.back();
		 path.push_back(next);
		 visited[next]=true;
		 double cand = shortestPath(path,visited,currentLength+dist[here][next]);
		 ret=min(ret,cand);
		 visited[next]=false;
		 path.pop_back();
	}
	return ret;
}
</code></pre>
