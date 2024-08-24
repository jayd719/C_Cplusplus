#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *rear;
    int count;

    LinkedList()
    {
        this->head = NULL;
        this->rear = NULL;
        this->count = 0;
    }

    // insert new Node
    void append(int val)
    {
        Node *newNode = new Node(val);

        if (this->head == NULL)
        {
            this->head = newNode;
            this->rear = newNode;
        }
        else
        {
            this->rear->next = newNode;
            this->rear = newNode;
        }

        this->count++;
    }
    // returns the
    bool contains(int val)
    {
        Node *currNode = this->head;
        while (currNode != NULL)
        {
            if (currNode->data == val)
            {
                return true;
            }

            currNode = currNode->next;
        }
        return false;
    }

    bool remove(int val)
    {
        Node *currNode = this->head;
        Node *prevNode = NULL;
        while (currNode != NULL)
        {
            if (currNode->data == val)
            {
                break;
            }
            else
            {
                prevNode = currNode;
                currNode = currNode->next;
            }
        }

        if (currNode != NULL)
        {
            if (prevNode == NULL)
            {
                this->head = currNode->next;
            }
            else if (currNode->next == NULL)
            {
                prevNode->next = NULL;
                this->rear = prevNode;
            }
            else
            {
                prevNode->next = currNode->next;
            }

            this->count--;

            return true;
        }

        return false;
    }

    void pop_front()
    {
        if (this->head == this->rear)
        {
            this->head = NULL;
            this->rear = NULL;
        }
        else
        {
            this->head = this->head->next;
        }

        this->count--;
    }
};