#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Node;
template <typename T>
class LinkedList{



public:
    //Node Nested class
    class Node{
        // private:
    public:
        T data;
        Node *next = nullptr;
        Node *prev = nullptr;

        void SetNext(Node &node);
        void SetPrevious(Node &node);


    };
//private:
    unsigned int Size = 0;
    Node *HeadP = nullptr;
    Node *TailP = nullptr;

    //Accessors
    void PrintForward() const;
    void PrintReverse() const;
    unsigned int NodeCount() const;
    void FindAll(vector <Node*> &outData, const T &value) const;
    const Node *Find(const T&data) const;
    Node *Find(const T &data);
    const Node *GetNode(unsigned int index) const;
    Node *GetNode(unsigned int index);
    Node *Head();
    const Node *Head() const;
    Node *Tail();
    const Node *Tail() const;


    //Insertion

    void AddHead(const T &data);
    void AddTail(const T &data);
    void AddNodesHead(const T *data, unsigned int count);
    void AddNodesTail(const T *data, unsigned int count);
    void InsertAfter(Node *node, const T &data);
    void InsertBefore(Node *node, const T &data);
    void InsertAt(const T &data, unsigned int index);

    //Removal
    //
    bool RemoveHead();
    bool RemoveTail();
    unsigned int Remove(const T &data);
    bool RemoveAt(unsigned int index);
     void Clear();

    //operators

    const T &operator[](unsigned int index) const;
    T &operator[](unsigned int index);
    bool operator==(const LinkedList<T> &rhs) const;
    LinkedList<T> &operator=(const LinkedList<T> &rhs); //rule of three assignement operator

    //Rule of Three
    //maybe a constructor
    LinkedList();
    LinkedList(const LinkedList<T> &list);
    ~LinkedList();

};

//Node definitions
// template <typename T>
// LinkedList<T>::Node::Node() {
//
// }
// template <typename T>
// LinkedList<T>::Node::Node(const T &d){
//     SetData(d);
//
// }
template <typename T>
void LinkedList<T>::Node::SetNext(Node &node){
    this->next = &node;
    if(node.prev != this){
        node.SetPrevious(*this);
    }
}
template <typename T>
void LinkedList<T>::Node::SetPrevious(Node &node){
    this->prev = &node;
    if(node.next != this){
        node.SetNext(*this);
    }
}


//LinkedList definitions

//accessors
template <typename T>
void LinkedList<T>::PrintForward() const {
    Node* node = HeadP;//Head();
    cout << node->data << endl;
    do{
        node = node->next;
        std::cout << node->data << std::endl;
    }while(node->next != nullptr);

}
template <typename T>
void LinkedList<T>::PrintReverse() const{
    Node *node = TailP; //this->Tail();
    cout << node->data << endl;
    do{
        node = node->prev;
        std::cout << node->data << std::endl;
    }while(node->prev != nullptr);
}

template <typename T>
unsigned int LinkedList<T>::NodeCount() const{
    return this->Size;
}
template <typename T>
void LinkedList<T>::FindAll(vector<Node *> &outData, const T &value) const{
    Node* node = HeadP;
    for(unsigned int i = 0; i < Size; i++){
        if(node->data == value){
            Node* Ptr = node;

            outData.push_back(Ptr);

        }
        node = node->next;
    }

}
template <typename T>
const typename LinkedList<T>::Node *LinkedList<T>::Find(const T &data) const{
    Node* node = Head();
    while(node->next != nullptr){
        if(node->data == data) {
            return node;
        }
        else{
            node = node->next;
        }
    }
    return NULL;
}
template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::Find(const T &data){
    Node* node = Head();
    while(node->next != nullptr){
        if(node->data == data) {
            return node;
        }
        else{
            node = node->next;
        }
    }
    return NULL;

}
template <typename T>
const typename LinkedList<T>::Node *LinkedList<T>::GetNode(unsigned int index) const{
    if(index < 0 or index >= Size ){
        throw;
    }
    if(Size == 1){
        return HeadP;
    }
    Node* node = this->HeadP;
    for(unsigned int i = 0; i < index; i++){
        node = node->next;
    }
    return node;


}
template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::GetNode(unsigned int index) {
    if(index < 0 or index >= Size ){
        throw;
    }
    Node* node = this->HeadP;
    if(Size == 1){
        return HeadP;
    }
    for(unsigned int i = 0; i < index; i++){
        node = node->next;
    }
    return node;
}
template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::Head() {
    return HeadP;

}
template <typename T>
const typename LinkedList<T>::Node *LinkedList<T>::Head() const {
    return HeadP;

}
template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::Tail() {
    return TailP;

}
template <typename T>
const typename LinkedList<T>::Node *LinkedList<T>::Tail() const {
    return TailP;

}


//Insertion
template <typename T>
void LinkedList<T>::AddHead(const T &data){
//    T* dataPtr = new T;
//    *dataPtr = data;
    if(HeadP == nullptr){
        this->HeadP = new Node;
        this->HeadP->data = data;
        this->Size++;
    }
    if(TailP == nullptr){
        this->TailP = HeadP;
    }
    else{//Define the new head to be previous of the old head

        Node* node = new Node;
        node->data = data;
        node->next = &*HeadP;
        this->HeadP->prev = &*node;
        this->HeadP = &*node;
        this->Size++;

    }
}

template <typename T>
void LinkedList<T>::AddTail(const T &data){
//    T* dataPtr = new T;
//    *dataPtr = data;
    if(TailP == nullptr){
        TailP = new Node;
        TailP->data = data;
        Size++;
    }
    if(HeadP == nullptr) {
        this->HeadP = TailP;
    }
    else{//Define the new head to be previous of the old head

        Node* node = new Node;
        node->data = data;
        node->prev = &*TailP;
        TailP->next = &*node;
        TailP = &*node;
        Size++;

    }
}

template <typename T>
void LinkedList<T>::AddNodesHead(const T *data, unsigned int count){
    for(unsigned int i = 0; i < count; i++){
        this->AddHead(data[count-1 - i]);
    }
}

template <typename T>
void LinkedList<T>::AddNodesTail(const T *data, unsigned int count){
    for(unsigned int i = 0; i < count; i++){
        this->AddTail(data[i]);
    }
}
//
template <typename T>
void LinkedList<T>::InsertAfter(Node *node, const T &data){
//    T* newData = new T;
//    *newData = data;
    Node* NewNode = new Node;
    NewNode->data = data;
    NewNode->next = node->next;
    NewNode->prev = node;
    NewNode->next->prev = NewNode;
    node->next = &*NewNode;
    Size++;


}

template <typename T>
void LinkedList<T>::InsertBefore(Node *node, const T &data){
//    T* newData = new T;
//    *newData = data;
    Node* NewNode = new Node;
    NewNode->data = data;
    NewNode->prev = node->prev;
    NewNode->next = node;
    NewNode->prev->next = NewNode;
    node->prev = &*NewNode;
    Size++;

}
template <typename T>
void LinkedList<T>::InsertAt(const T &data, unsigned int index){
    if(index < 0 or index > Size){
        throw;
    }
    else if(index == Size){
        AddTail(data);
    }
    else if(index == 0){
        AddHead(data);
    }
    else {
        Node *node = Head();
        for (unsigned int i = 0; i < index; i++) {
            node = node->next;
        }
        InsertBefore(node, data);
    }
}

//
// //Removal
template <typename T>
bool LinkedList<T>::RemoveHead(){
    if(Size <= 0){
        return false;
    }
    if(Size == 1){
        delete HeadP;
        HeadP = nullptr;
        TailP = nullptr;
    }else {
        HeadP = HeadP->next;
        delete HeadP->prev;
        HeadP->prev = nullptr;
        // delete HeadP->prev; //TODO check if deletion is necessare
        //there may be possible to just check fr heads and pointers
        //but it may cause memory leak

        //Still has to work on exceptions and "False" cases
    }
    Size--;
    return true;
}

template <typename T>
bool LinkedList<T>::RemoveTail(){
    if(Size <= 0){
        return false;
    }
    if(Size ==1){
        delete HeadP;
        HeadP = nullptr;
        TailP = nullptr;
    }else {
        TailP = TailP->prev;
        delete TailP->next;
        TailP->next = nullptr;
        //delete HeadP->next; //check if deletion is necessare
        //there may be possible to just check fr heads and pointers
        //but it may cause memory leak
    }

    //Still has to work on exceptions and "False" cases
    Size--;
    return true;
}
//
template <typename T>
unsigned int LinkedList<T>::Remove(const T &data){
    unsigned int counter = 0;
    Node* node = Head();
    for(unsigned int i = 0; i < Size; i++){
        if(node->data == data){
            node->prev->next = node->next;//links prev Node to the Next node
            node->next->prev = node->prev;
            //Check if it needs to be deleted
            Node* temp = node;
            node = node->prev;
            //TODO check for leaks and edge cases
            delete temp;
            counter++;
            //node = temp;
        }
        node = node->next;
    }
    Size = Size - counter;
    return counter;
}
//
template <typename T>
bool LinkedList<T>::RemoveAt(unsigned int index){
    if(index < 0 or index >= Size){
        return false;
    }
    Node* node = GetNode(index);
    node->prev->next = node->next;
    node->next->prev = node->prev;
    Size--;
    //TODO Check if needs deletion
    delete node;
    return true;

}
//
 template <typename T>
 void LinkedList<T>::Clear() {
    unsigned int y = Size;
     for(unsigned int i = 0; i < y ; i++){
         RemoveHead();
         }
         Size = 0;

 }



//operators
template <typename T>
const T& LinkedList<T>::operator[](unsigned int index) const {
    return GetNode(index)->data;
}
template <typename T>
T& LinkedList<T>::operator[](unsigned int index) {
    Node *node = GetNode(index);
    return node->data;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &rhs) {
    //LinkedList<T>* NewList = new LinkedList;
    for(unsigned int i = 0; i < rhs.Size; i++){
        //Node* node = new Node;
        //*node = *rhs.GetNode(i);
        this->AddTail(rhs[i]);
    }
    return *this;

}
template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T> &rhs) const {
    if(this->Size != rhs.Size){
        return false;
    }
    unsigned int counter = 0;
    for(unsigned int i = 0; i <this->Size; i++){

        if(this->operator[](i) == rhs[i]){
            counter++;
            //return false;
        }
        if(counter == Size){
            return true;
        }
    }
    return false;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list) {
    for(unsigned int i = 0; i < list.Size; i++){
        //Node* node = new Node;
        //*node = *rhs.GetNode(i);
        this->AddTail(list[i]);
    }
//    this->Size = list.Size;
//    this->HeadP = list.HeadP;
//    this->TailP = list.TailP;
//    for(unsigned int i = 0; i < list.Size; i++){
//        this->GetNode(i) = list.GetNode(i);
//    }
}
template <typename T>
LinkedList<T>::~LinkedList() {


    for(unsigned int i = 0; i < Size; i++){
        delete GetNode(Size-1-i);
    }

}

template <typename T>
LinkedList<T>::LinkedList() {
//    T data;
//    Node *next = nullptr;
//    Node *prev = nullptr;


}

