#include <iostream>
using namespace std;
class Node{
public:
  int data;
  Node* next;
public:
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};
// print
void print(Node* head){
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}

// insert
void InsertAtTail(Node* &head, Node* &tail, int data){
  Node* temp = new Node(data);
  if(head == NULL){
    head = temp;
    tail = temp;
  }  
  else{
    tail->next = temp;
    tail = temp;
  }
}

// reverse
Node* reverse(Node* &head){
  Node* prev = NULL;
  Node* curr = head;
  while(curr != NULL){
    Node* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

// add
Node* add(Node* &num1, Node* &num2){
  Node* ansHead = NULL;
  Node* ansTail = NULL;
  int carry = 0;
  while(num1 != NULL || num2 != NULL || carry != 0){
    int val1 = 0;
    if(num1 != NULL){
      val1 = num1->data;
    }
    int val2 = 0;
    if(num2 != NULL){
      val2 = num2->data;
    }
    int sum = val1 + val2 + carry;
    int digit = sum % 10;
    InsertAtTail(ansHead, ansTail, digit);
    carry = sum / 10;

    if(num1 != NULL){
      num1 = num1->next;
    }
    if(num2 != NULL){
      num2 = num2->next;
    }
  }
  return ansHead;
}

int main(){

  // creating 2 liniked list and inserting values
  Node* node1 = new Node(2);
  Node* tail = node1;
  Node* head = node1;
  InsertAtTail(head, tail, 3);
  InsertAtTail(head, tail, 4);
  InsertAtTail(head, tail, 5);

  Node* node2 = new Node(6);
  Node* tail2 = node2;
  Node* head2 = node2;
  InsertAtTail(head2, tail2, 2);
  InsertAtTail(head2, tail2, 4);
  InsertAtTail(head2, tail2, 3);
  // printing the linked list
  cout<<"The two linked list are: "<<endl;
  print(node1);
  print(node2);

  // adding the two linked list
  node1 = reverse(node1);
  node2 = reverse(node2);
  Node* ans = add(node1, node2);

  node1 = reverse(ans);

  print(node1);

  return 0;
}