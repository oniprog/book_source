#include <cstdio>

int Fibonachi( int nVal ) {

  if ( nVal <= 1 )
    return 1;

  int nBef[2] = { 1, 2 };

  for( int it=3; it<=nVal; ++it ) {

    int nSum = nBef[0] + nBef[1];

    // 今の数を1つ前に
    // 1つ前を2つ前に
    nBef[0] = nBef[1];
    nBef[1] = nSum;
  }
  return nBef[1];
}

int main() {
    
  for(int nVal=3; nVal<=10; ++nVal ) {
    int nAns = Fibonachi( nVal );
    printf("f(%d) = %d\n", nVal, nAns );
  }    
  return 0;
}
