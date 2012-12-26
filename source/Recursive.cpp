#include <cstdio>

int Fibonachi( int nVal ) {
    
  if ( nVal <= 1 )
    return 1;
    
  return Fibonachi( nVal-1 ) + Fibonachi( nVal-2 );
}

int main() {
    
  for(int nVal=3; nVal<=10; ++nVal ) {
    int nAns = Fibonachi( nVal );
    printf("f(%d) = %d\n", nVal, nAns );
  }    
  return 0;
}
