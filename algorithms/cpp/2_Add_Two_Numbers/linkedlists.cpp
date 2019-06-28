#include <iostream>
using std :: cout;
using std :: endl;

/* declare a structure to define a node.
 * The node usually has at least one varialbe
 * that stores the data and one pointer that
 * links to the next node. */
struct ListNode{
  int data;
  ListNode *next;
};

/* define a class to store and process the nodes */
  class list{
  private:
    ListNode *head, *tail;
  public:
    list(){
      head = nullptr;
      tail = nullptr;
    }
    /* a method to create nodes */
    void createnode(int value){
      ListNode *tmp = new ListNode;
      tmp->data = value;
      tmp->next = nullptr;
      if(head == nullptr){
	head = tmp;
	tail = tmp;
      }
      else{
	tail->next = tmp;
     	tail = tmp;
      }
    }
    /* a method to display all the nodes */
    void display(){
      ListNode *tmp = new ListNode;
      tmp = head;
      while(tmp != nullptr){
        cout << tmp->data;
        tmp = tmp->next;
      }
      cout << endl;
    }
    /* a method to insert a node before head */
    void insert_before_head(int value){
      ListNode *tmp = new ListNode;
      tmp->data = value;
      tmp->next = head;
      head = tmp;
    }
    /* a method to insert a node after tail */
    void insert_after_tail(int value){
      ListNode *tmp = new ListNode;
      tmp->data = value;
      tail->next = tmp;
      tail = tmp;
    }
    /* a method to insert a node at a particular position */
    void insert_particular_at(int position, int value){
      ListNode *current = new ListNode;
      ListNode *previous = new ListNode;
      ListNode *tmp = new ListNode;
      current = head;
      for(int i=1; i<position; i++){
	previous = current;
	current = previous->next;
      }
      tmp->data = value;
      tmp->next = current;
      previous->next = tmp;
    }
    /* a method to delete the first node in list */
    void delete_head(){
      head=head->next;
    }
    /* a method to delete the last node in list */
    void delete_tail(){
      ListNode *previous = new ListNode;
      ListNode *current = new ListNode;
      current = head;
      while(current->next != nullptr){
	previous = current;
	current = previous->next;
      }
      tail = previous;
      tail->next = nullptr;
    }
    /* a method to delete a node at a particular position */
    void delete_particular_at(int position){
      ListNode *current = new ListNode;
      ListNode *previous = new ListNode;
      current = head;
      for(int i=1; i<position; i++){
	previous = current;
	current = previous->next;
      }
      previous->next = current->next;
    }
  };

int main(){

  list connections;
  for(int i=1; i<10; i++){
    connections.createnode(i);
  }
  cout << "origional list contains:" << endl;
  connections.display();

  connections.insert_before_head(0);
  cout << "after inserting a node before head:" << endl;
  connections.display();

  connections.insert_after_tail(0);
  cout << "after inserting a node after tail:" << endl;
  connections.display();

  connections.insert_particular_at(5,0);
  cout << "after inserting a node at a particular position:" << 5 << endl;
  connections.display();

  connections.delete_head();
  cout << "after deleting the head:" << endl;
  connections.display();

  connections.delete_tail();
  cout << "after deleting the tail:" << endl;
  connections.display();

  connections.delete_particular_at(4);
  cout << "after deleting a node at a particular position:" << 4 << endl;
  connections.display();
}
