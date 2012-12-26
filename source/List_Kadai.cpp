#include <cstdio>
#include <cassert>

// 以下のクラスを実装する
class List {
public:
  List() {}
  ~List() {}
    
  // データを加える
  void    AddData(int nValue) {}
    
  // データを削除する
  bool    DeleteData(int nIndex) { return true; }
    
  // サイズを得る
  int Size() const { return 0; }
    
  // 値を得る
  int GetData(int nIndex) const { return 0; }
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
