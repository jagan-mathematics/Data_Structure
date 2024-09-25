//
// Created by jagan-12127 on 25/09/24.
//

#ifndef UNTITLED_DOUBLYLINKLIST_H
#define UNTITLED_DOUBLYLINKLIST_H

template<typename T>
class Node{
public:
    T data;
    Node* nextNode;
    Node* prevNode;



    Node(T x){
        data = x;
    }

    Node(T x, Node<T>* nextNodeRef, Node<T>* previousNodeRef){
        data = x;
        nextNode = nextNodeRef;
        prevNode = previousNodeRef;
    }

    Node(T x, Node<T>* nextNodeRef){
        data = x;
        nextNode = nextNodeRef;
    }
};

template<typename T>
class DoublyLinkList {
public:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

public:
    Node<T>* pushBack(T &data){
        if (head == nullptr){
            head = new Node<T>(data);
            tail = head;
            return head;
        }

        // x  <-> y <-> null
        auto* temp = new Node<T>(data, nullptr, tail);
        tail->nextNode = temp;
        tail=temp;
        return head;
    }

    Node<T>* pushFront(T &data){
        if (head == nullptr){
            head = new Node<T>(data);
            tail=head;
        }
        else{
            auto* temp = new Node<T>(data, head, nullptr);
            head->prevNode = temp;
            head = temp;
        }
        return head;
    }


    T popFront(){
        if (head== nullptr){
            return -1;
        }
        // a <-> b <-> c <-> d <-> null
        Node<T>* temp = head;
        head = head->nextNode;
        if (head != nullptr){
            head->prevNode = nullptr;
        } else{
            tail = head;
        }
        temp->nextNode = nullptr;
        T value = temp->data;
        free(temp);
        return value;
    }


    T pop() {
        if (head== nullptr){
            return -1;
        }

        if (head->nextNode == nullptr){
            T val = head->data;
            head = nullptr;
            tail = nullptr;
            return val;
        }
        // a <-> b <-> c <-> d <-> null
        Node<T>* temp = tail;
        tail = tail->prevNode;
        if (tail != nullptr){
            tail->nextNode = nullptr;
        } else{
            head = nullptr;
        }
        temp->prevNode = nullptr;
        T value = temp->data;
        free(temp);
        return value;
    }


    T pop(int position) {
        if (head== nullptr){
            return -1;
        }
        // a <-> b <-> c <-> d <-> null
        int count = 0;
        Node<T>* temp = head;
        while(temp!= nullptr) {
            count++;
            if (count == position) {
                break;
            }
            temp = temp->nextNode;
        }

        if (temp == nullptr){
            return -1;
        }
        Node<T>* backNode = temp->prevNode;
        Node<T>* frontNode = temp->nextNode;
        T val = temp->data;

        if (frontNode != nullptr && backNode != nullptr){
            backNode->nextNode = frontNode;
            frontNode->prevNode = backNode;
            temp->nextNode = nullptr;
            temp->prevNode = nullptr;
            free(temp);
        }else if (frontNode == nullptr && backNode == nullptr){
            head = nullptr;
            tail = nullptr;
            free(temp);
        }
        else if (backNode == nullptr){
            // we are in head
            popFront();
        }
        else{
            // we are in tail
            pop();
        }
        return val;
    }


    void insertValue(T value, int position) {
        if (head == nullptr){
            if (position == 1){
                // push front of the list
                pushFront(value);
            }
            return;
        }

        if (position == 1){
            pushFront(value);
            return;
        }
        // a <-> b <-> c <-> d <-> null
        int count = 0;
        Node<T>* temp = head;
        while(temp!= nullptr) {
            count++;
            if (count == position) {
                break;
            }
            temp = temp->nextNode;
        }


        if (temp == nullptr){
            if (count + 1 == position){
                //push back of the tail
                pushBack(value);
            }
            return;
        }
        Node<T>* backNode = temp->prevNode;
        auto* newNode = new Node<T>(value, temp, backNode);
        backNode->nextNode=newNode;
        temp->prevNode=newNode;
    }
};


#endif //UNTITLED_DOUBLYLINKLIST_H
