#include <cstdio>
#include <cassert>

// リストのノード
struct ListNode {
  ListNode    *pNext;
  int         nValue;
  ListNode() : pNext(0) {}
  ListNode( ListNode *pNext_, int nValue_ ) : pNext(pNext_), nValue(nValue_) {}
  ~ListNode() { delete pNext; }
};

// リスト本体
// 効率は無視してます．
class List {
  ListNode *m_pHead;
public:
  List() : m_pHead(0) {}
  ~List() { delete m_pHead; }
    
  // データを加える
  void    AddData(int nValue) {
    if( m_pHead ) {
      ListNode *pNewNode = new ListNode( m_pHead, nValue );
      m_pHead = pNewNode;
    }
    else {
      m_pHead = new ListNode( 0, nValue );
    }
  }
    
  // データを削除する
  bool    DeleteData(int nIndex) {
        
    ListNode *pBefNode = m_pHead, *pCurNode = m_pHead;
    for( ; pCurNode && nIndex > 0 ; --nIndex ) {
      pBefNode = pCurNode;
      pCurNode = pCurNode->pNext;
    }
        
    if( pCurNode ) {
            
      if ( pCurNode == m_pHead )
	m_pHead = m_pHead->pNext;
      else 
	pBefNode->pNext = pCurNode->pNext;
            
      pCurNode->pNext = 0;// 連鎖して消えてしまわないように
      delete pCurNode;
            
      return true;
    }
    else 
      return false;
  }
    
  // サイズを得る
  int Size() const {
        
    int nCnt = 0;
    for( ListNode *pCurNode = m_pHead; pCurNode; pCurNode = pCurNode->pNext ) {
      ++nCnt;
    }
    return nCnt;
  }
    
  // 値を得る
  int GetData(int nIndex) const {
        
    ListNode *pCurNode;
    for( pCurNode = m_pHead; pCurNode && nIndex > 0 ; --nIndex ) 
      pCurNode = pCurNode->pNext;
        
    if ( pCurNode )
      return pCurNode->nValue;
    else
      return 0;
  }
};

// ユニットテスト
// 仕様書でもあります
void RunUnitTest() {
  {
    List listTest;
    assert( listTest.Size() == 0 );
    listTest.AddData( 10 );
    assert( listTest.Size() == 1 );
    listTest.AddData( 20 );
    assert( listTest.Size() == 2 );

    assert( listTest.GetData( 0 ) == 20 );
    assert( listTest.GetData( 1 ) == 10 );
        
    listTest.DeleteData(0);
    assert( listTest.Size() == 1 );
    assert( listTest.GetData( 0 ) == 10 );
        
    listTest.DeleteData(0);
    assert( listTest.Size() == 0 );
  }
}

int main() {
  RunUnitTest();
  return 0;
}
