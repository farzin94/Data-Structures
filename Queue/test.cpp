#include <iostream>


#include "queue.h"

using namespace std;



int main (void) {

        
   bool OK = true ;
   Queue q1 ;
   Queue q2 ;
   if( q1.size() != 0 ) OK = false ; 
   for( int i = 1 ; i <= 10 ; i++ ){
      q1.enqueue(100 + i);
      q2.enqueue(200 + i);
   }
   if( q1.size() != 10 ) OK = false ;
   if( q2.size() != 10 ) OK = false ;

   for( int i = 1 ; i <= 20 ; i++ ){
      q2.enqueue( q1.dequeue() );
      q1.enqueue( q2.dequeue() );
   }
   if( q1.size() != 10 ) OK = false ;
   if( q2.size() != 10 ) OK = false ;
  
   while( !q1.empty() ){
      q1.dequeue();
   }
   while( !q2.empty() ){
      q2.dequeue();
   }

   if( q1.size() != 0 ) OK = false ;
   if( q2.size() != 0 ) OK = false ;

   if( OK ){
      cout << "GOOD" << endl ;
      return 0 ;
   }else{
      cout << "BAD" << endl ;
      return -1 ;
   }

	/*Queue test_q;

	test_q.enqueue(4);
	test_q.enqueue(2);
	test_q.enqueue(1);
	test_q.enqueue(6);
	test_q.enqueue(2);
	test_q.enqueue(2);
	test_q.enqueue(3);
	test_q.enqueue(5);
	test_q.enqueue(2);

	Queue test(test_q);

	cout << "front is " << test.front() << endl;

	test.print();

	test_q.print();
	cout << endl;

	int b = test_q.makeUnique(2);

	test_q.print();

	cout << "removed: " << b << " times" << endl;
	cout << "current size is " << test_q.size() << endl;

	cout << "empty? " << test_q.empty() << endl;
	

	cout << endl;

	cout << "front is " << test_q.front() << endl;
	cout << "current size is " << test_q.size() << endl;
	cout << "empty? " << test_q.empty() << endl;

	test_q.dequeue();
	test_q.dequeue();

	cout << "2 dequeues: " << endl;

	cout << "front is " << test_q.front() << endl;
	cout << "current size is " << test_q.size() << endl;
	cout << "empty? " << test_q.empty() << endl;

	test_q.dequeue();
	cout << "empty? " << test_q.empty() << endl;
	

	cout << endl;*/

	return 0;
}
