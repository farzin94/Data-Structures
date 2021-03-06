/* File: char_stack.h       

  Header file for a very basic array-based implementation of a stack.

*/
class char_stack
{
  public:
    char_stack();
    void push( char item );
    char pop(); 
    char top();
    bool empty();
    int size();

  private:
    static const int capacity = 250*1000; //capacity of array
  	char A[capacity]; 
  	int top_index;
};
