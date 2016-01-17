/*************************************************************
   Test Program for Basic Heap Class - Preliminiary Version.
**************************************************************/
#include <iostream>
#include "maxheap.h"
using namespace std;

void heapTest();
 
int main(){
      heapTest();
      return 0;
}


void Show( Heap & H, string s ){
      cout << s << ".capacity=" << H.capacity() << endl;
      cout << s << ".size=" << H.size() << endl;
      cout << "-----------------------\n";
} 

 
void heapTest(){

      // Test default constructor and basic functions 
      Heap H;
 
      H.insert(91,7);
      H.insert(92,6);
      H.insert(93,8);
      H.insert(94,5);
      H.insert(95,9);
      while( !H.empty() ){
        cout << "max priority: " << H.peekMaxPriority() << endl;
        cout << "max priority element: " << H.peekMax() << endl;
        H.extractMax();
      }
 
}
