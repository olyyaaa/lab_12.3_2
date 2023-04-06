// lab_12.03_2_AP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// ��������� ��� ������������� �������� ������
struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

// ������� ��� ��������� �������� �� ������
void push(Node** head, int data)
{
    Node* newNode = new Node(data);
    newNode->next = *head;
    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// ������� ��� ��������� �������� � ������
void deleteNode(Node** head, Node* node)
{
    if (*head == NULL || node == NULL)
    {
        return;
    }
    if (*head == node)
    {
        *head = node->next;
    }
    if (node->next != NULL)
    {
        node->next->prev = node->prev;
    }
    if (node->prev != NULL)
    {
        node->prev->next = node->next;
    }
    delete node;
}

// ������� ��� ��������� ������ �� �����
void printList(Node* head)
{
    if (head != NULL)
    {
        cout << head->data << " ";
        printList(head->next);
    }
    else
    {
        cout << endl;
    }
}


// ������� ��� ��������� �������� ����� ��������� � ��������� value
void deleteBeforeValue(Node** headRef, int value, Node* current = nullptr, Node* prev = nullptr, Node* prevPrev = nullptr)
{
    if (*headRef == nullptr || (*headRef)->next == nullptr)
    {
        // ���� ������ �� ���� ��� �� ������ ����� ���� ��������
        return;
    }

    if (current == nullptr)
    {
        current = *headRef;
    }

    if (current == nullptr || current->data == value)
    {
        if (prevPrev == nullptr)
        {
            // ���� ������� �� �������� ��� �� � ������ � ������
            return;
        }

        prevPrev->next = current;
        delete prev;
        return;
    }

    deleteBeforeValue(headRef, value, current->next, current, prev);
}



int main()
{
    Node* head = NULL;

    // ��������� ������
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);

    // ��������� ������
    cout << "List before deleting:" << endl;
    printList(head);
    deleteBeforeValue(&head, 6);

    // ��������� ������ ���� ��������� ��������
    cout << "List after deleting:" << endl;
    printList(head);

    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
