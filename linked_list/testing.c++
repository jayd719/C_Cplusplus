#include <iostream>
#include <stdlib.h>
#include "linkedList.c++"

using namespace std;

void test_append(LinkedList *list, int items[], int count)
{
    for (int i = 0; i < count; i++)
    {
        list->append(items[i]);
    }
}

void print_linked_list(LinkedList *list)
{
    Node *curr_node = list->head;
    cout << "\tCount: " << list->count << "\n\tItems: [";
    while (curr_node != NULL)
    {
        cout << curr_node->data;
        curr_node = curr_node->next;
        if(curr_node!=NULL){
            cout<<", ";
        }
    }
    cout << "]\n";
}

int main()
{
    system("clear");

    // test cases
    int testing_elements[] = {1, 2, 3, 4, 5, 6, 7};

    cout << "Testing Linked List\n";
    cout << "\n";
    // create new instace of linked list
    LinkedList *listOne = new LinkedList();
    // test functions

    // Tesing Append Function;
    cout << "Testing Append\n";
    test_append(listOne, testing_elements, sizeof(testing_elements) / sizeof(testing_elements[0]));
    print_linked_list(listOne);
    cout << "\n\n";

    // Testing Contains;
    cout << "Testing Contains\n";
    cout<< "\tContains(10): "<<listOne->contains(10)<<"\n";
    cout<< "\tContains(1): "<<listOne->contains(1)<<"\n";
    cout<< "\tContains(6): "<<listOne->contains(6)<<"\n";
    cout << "\n\n";

    // Testing Remove()
    cout<<"Testing Remove\n";
    cout<<"Remove(10):" <<listOne->remove(10);
    print_linked_list(listOne);

    cout<<"Remove(1):" <<listOne->remove(1);
    print_linked_list(listOne);

    cout<<"Remove(7):" <<listOne->remove(7);
    print_linked_list(listOne);

    cout<<"Remove(4):" <<listOne->remove(4);
    print_linked_list(listOne);
    cout << "\n\n";

    cout<<"Tesing pop_front()\n";
    listOne->pop_front();
    print_linked_list(listOne);


    return 0;
}