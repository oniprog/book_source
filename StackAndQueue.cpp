#include <cstdio>
#include <cassert>
#include <list>

class Stack {
  std::list<int>    m_listStack;
public:
  void    Push(int nData) {
    m_listStack.push_back( nData );
  }
  int        Pop() {
    int nRet = m_listStack.back();
    m_listStack.pop_back();
    return nRet;
  }
};

class Queue {
  std::list<int>    m_listQueue;
public:
  void    Enqueue( int nData ) {
    m_listQueue.push_back( nData );
  }
  int        Dequeue() {
    int nRet = m_listQueue.front();
    m_listQueue.pop_front();
    return nRet;
  }
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
