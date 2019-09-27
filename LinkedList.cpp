#include "LinkedList.h"

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
    this->tail = NULL;
}

LinkedList::LinkedList(const LinkedList &list){
    std::cout<<"COPIED"<< endl;
    this->length=list.length;
    if (list.head == NULL) {
        head = NULL;
    }
    else {
        head = new Node(list.head->data);
        Node *current = head;
        Node *tempHead = list.head; //
      //  Node *currentNode = tempHead;
        while (tempHead->next) {
            current->next = new Node(tempHead->next->data);
            current = current->next;
            tempHead = tempHead->next;
        }

        tail = current;
    }

}

LinkedList& LinkedList::operator=(const LinkedList &list){
    std::cout<<"Equals"<< endl;
    this->length=list.length;
    if (list.head == NULL) {
        head = NULL;
    }
    else {
        delete head;
        head = new Node(list.head->data);
        Node *current = head;
        Node *tempHead = list.head; //
        //  Node *currentNode = tempHead;
        while (tempHead->next) {
            delete current->next;
            current->next = new Node(tempHead->next->data);
            current = current->next;
            tempHead = tempHead->next;
        }

        tail = current;
    }
    return *this;
}

// add a new element to the back of LinkedList
void LinkedList::pushTail(Member data){
    Node * newNode = new Node(data);

    if (tail == NULL)
    {
        newNode->next = tail;
        tail = newNode;
        head = newNode;
        this->length++;
        return;
    }
    tail->next = newNode;
    tail = tail->next;

    this->length++;


}

LinkedList::~LinkedList(){

     if(head)
        delete head;

}



