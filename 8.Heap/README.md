# Heap sort
* insert
* delete min(max)
* Complete Binary Tree
 - 순서대로 채워져있는 트리
 - 배열사용
 - 레밸의 맨 왼쪽은 2^h
 - 루트에서 마지막 노드 = floor(logN)
 - 2^h ~ 2^(h+1)-1개 노드
 - 그 노드의 부모는  floor(k/2) 
 - 그 노드의 왼쪽 자식 2k, 오른쪽 2k+1
#### Binary Heap
* Binary Heap 
- 특징 : 컴플릿트 바이너러 / min heap(부모는 자식보다 작거나 같다.) / max heap(부모는 자식보다 크거나 같다.)
* insert : 마지막 노드에 추가 하고 위치로 GO! (fix heap) 
* delete(min/max) : 루트만 지울 수 있다. 
 1. 루트를 삭제
 2. 마지막 노드를 루트로 올림. 
 3. fix heap! 

#### Heap Construction
* [make_heap](https://github.com/rim0621/Algorithm-study/tree/master/8.Heap/makeHeap.cpp)
* 완전트리가 힙 순서로 정렬 되있지 않을 때 => fixHeap 
* fixheap = **2floor(logN)**
* Heap Construction 만드는 방법
 - 방법1 : 루트를 기준으로 윈쪽,오른쪽으로 리컬시브하게 들어간 후 fixheap =
 - 방법2 : floor(k/2)[k는 마지막 노드, 마지막 자식노드를 갖는 마지막 부모]부터~ 루트까지 fixheap( whlie문 한개로! ) = **O(n)**
* insert하는 것보다 complete tree를 construct 하는 것이 더 빠름.
 - 삽입은 밑에 삽입되고 위로 위치를 찾아 올라감
 - 완전 트리를 컨스트럭트 하면 floor(k/2)부터 하니깐 요소가 움직이는 수가 훨씬 적음!!
#### Heap Sorting
1. 방법1) delete 민하고 다른 배열에 넣어서 소팅하는 방법(결국 배열 두개가 필요) - 오름차순할때
2. 방법2) delete 맥스하고 다른 배열이 아닌 마지막 루트를 올렸으니 그 자리에 넣어서..(점점fixheap하는 배열크기가 줄어들지)-오름차순
* **O(NlogN)**
