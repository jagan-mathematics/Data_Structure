//
// Created by jagan-12127 on 24/09/24.
//

#ifndef UNTITLED_LINKEDLIST_H
#define UNTITLED_LINKEDLIST_H

template<typename T>
class Node{
public:
    T data;
    Node* nextNode;



    Node(T x){
        data = x;
    }

    Node(T x, Node<T>* nextNodeRef){
        data = x;
        nextNode = nextNodeRef;
    }
};


template<typename T>
class LinkedList {
public:
    Node<T>* head = nullptr;


public:
    Node<T>* pushBack(T &data){
        if (head == nullptr){
            head = new Node<T>(data);
            return head;
        }

        if  (head->nextNode == nullptr){
            head->nextNode = new Node<T>(data);
            return head;
        }

        // x  -> y -> null
        Node<T>* temp = head;
        while (temp->nextNode != nullptr){
            if (temp->nextNode->nextNode == nullptr){
                temp->nextNode->nextNode = new Node<T>(data);
                break;
            }
            temp = temp->nextNode;
        }
        return head;
    }


    Node<T>* pushFront(T &data){
        if (head == nullptr){
            head = new Node<T>(data);
        }
        else{
            head = new Node<T>(data, head);
        }
        return head;
    }

    void insertValue(T &data, int position){
        if (head == nullptr){
            if (position == 1){
                head = new Node<T>(data);
            }
            else{
                return;
            }
        }

        if (position == 1){
            pushFront(data);
            return;
        }

        int count = 0;
        Node<T>* temp = head;
        // 0 -> 1 -> 2 -> 3
        // x -> y -> z -> a -> null
        while(temp->nextNode != nullptr){
            count++;
            if (count == position - 1){
                temp->nextNode = new Node<T>(data, temp->nextNode);
                break;
            }
            temp = temp->nextNode;
        }
    }

    T pop(){
        if (head == nullptr){
            return -1;
        }

        if (head->nextNode == nullptr){
            T value = head->data;
            head = nullptr;
            return value;
        }

        Node<T>* currentNode = head;
        // a -> b -> c -> d -> e -> null
        while (currentNode->nextNode != nullptr){
            if (currentNode->nextNode->nextNode == nullptr){
                Node<T>* temp = currentNode->nextNode;
                currentNode->nextNode = nullptr;
                T value = temp->data;
                free(temp);
                return value;
            }
            currentNode = currentNode->nextNode;
        }
        return -1;
    }


    T popFront(){
        if (head == nullptr){
            return -1;
        }

        Node<T>* temp = head;
        head = head->nextNode;
        T value = temp->data;
        free(temp);
        return value;

    }

    void pop(T& data){
        if (head == nullptr){
            return;
        }

        if (head->data == data){
            Node<T>* temp = head;
            head = head->nextNode;
            free(temp);
        }

        Node<T>* currentNode = head;
        // x -> y -> z -> a -> b -> null
        while (currentNode->nextNode != nullptr){
            if (currentNode->nextNode->data == data){
                Node<T>* temp = currentNode->nextNode;
                currentNode->nextNode = temp->nextNode;
                break;
            }
            currentNode=currentNode->nextNode;
        }
    }
};


#endif //UNTITLED_LINKEDLIST_H
