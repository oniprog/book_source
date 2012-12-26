#include <cstdio>
#include <cassert>
#include <list>

// 以下のクラスを実装してください
class Stack {
  std::list<int>    m_listStack;
public:
  void    Push(int nData) {}
  int     Pop() { return 0; }
};

// 以下のクラスを実装してください
class Queue {
  std::list<int>    m_listQueue;
public:
  void    Enqueue( int nData ) {}
  int        Dequeue() { return 0; }
};

void RunUnitTest() {
    
  // Stack Test
  {
    int nTmp;
    Stack test;
    test.Push(1);
    nTmp = test.Pop();
    assert( nTmp == 1 );
        
    test.Push(2);
    test.Push(3);
    nTmp = test.Pop();
    assert( nTmp == 3 );
    nTmp = test.Pop();
    assert( nTmp == 2 );
  }
  // Queue Test
  {
    int nTmp;
    Queue test;
    test.Enqueue(1);
    nTmp = test.Dequeue();
    assert( nTmp == 1 );
        
    test.Enqueue(2);
    test.Enqueue(3);
    nTmp = test.Dequeue();
    assert( nTmp == 2 );
    nTmp = test.Dequeue();
    assert( nTmp == 3 );
  }
}

int main() {
  RunUnitTest();
  return 0;
}

