//File: queue.cpp -- contains queue class implementation

#include <cstring>
#include <iostream>
#include "queue.h"


using namespace std;

// constructor 
Queue::Queue() {

	front_p = NULL;
	back_p = NULL;
	current_size = 0;

}

// copy constructor
Queue::Queue ( const Queue& q ) {

	front_p = NULL;
	back_p = NULL;
	current_size = q.current_size; 

	if (q.front_p != NULL) {
		node* current = q.front_p;
		node* copy;

		copy = new node (current->data, NULL);
		front_p = copy;
		current = current->next;

		while (current!= NULL) {

			copy->next = new node (current->data, NULL);
			copy = copy->next;
			current= current->next;
		}
	}
}

// destructor 
Queue::~Queue() {


		node* temp = front_p;

		while (front_p != NULL) {
			front_p = front_p->next;
			delete (temp);
			temp = front_p;
		}

		current_size = 0;

}

//enqueues item
void Queue::enqueue( int item ) {

	node* n_node = new node ( item , NULL );

	if (back_p == NULL) {
		front_p = back_p = n_node;
	}

	else {
		back_p->next = n_node;
		back_p = n_node;
	}

	current_size++;
}

// Dequeues the front item.
int Queue::dequeue() {

	node* temp = front_p;

	int result = temp->data;
	front_p = front_p->next;

	if(front_p == NULL){
		back_p = NULL;
	}

	delete(temp);

	current_size--;

	return result;	
}

// Returns the front item without dequeuing it.
int Queue::front() {

	return front_p->data;	
}

// Returns true iff the queue contains no items.
bool Queue::empty() {

	return front_p == NULL;
}

// Returns the current number of items in the queue.
int Queue::size() {

	return current_size;
}

// If <item> occurs in the queue more than once, remove all occurrences of <item> except the first. 
// Return the number of elements removed.
int Queue::makeUnique( int item ) {

	node* track = front_p;
	int count = 0;

	//check head to see if item is there
	if ( front_p-> data == item ){
		count++;
	}

	//check rest of the list 
	while (track->next != NULL) {

		//item found 
		if (track->next->data == item) {

			//to make sure we skip the first instance of item 
			if (count >= 1) {

				//deletion method
				node* temp = track->next;
				track->next = track->next->next;

				delete (temp);
		
				current_size--;
			}

			count++;

			//bug fix: list would not iterate forward when count == 1 and therefore would 
			//delete all instances of item
			if (count == 1) {
				track = track->next;
			}
		}

		//bug fix: list would skip over nodes and therefore leave some instances of item undeleted
		//therefore, only iterate when item has NOT been found
		else {
			track = track->next;
		}
	}

	//bug fix: only returning count-1 means I return -1 when there is no instance of item when 
	//I should be returning zero
	if (count <= 0) {
		return 0;
	}

	else {
		return count-1;
	}
}
