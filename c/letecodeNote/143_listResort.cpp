#include <iostream>
#include <forward_list>
using namespace std;
/*
    题目：给定一个单链表L：L0->L1->...->Ln-1->Ln，将其重新排列后变为L0->Ln->L2->Ln-1...
*/
// template <T>
// struct ListResort
// {
//     void listResort(forward_list<T> head)
//     {
//         forward_list<T>::iterator slow, fast;
//         while (fast != )
//         {
//             /* code */
//         }
        

//     }
// }
struct ListNode
{
    int data;
    struct ListNode* next;
};
struct List
{

    void listReverse(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return;
        }
        ListNode *slow = head, *fast = head->next; 
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *second = slow->next;
        slow->next = NULL;
        reverse(second);
        ListNode *merList = NULL;
        mergeList(head, second, merList);
        
    }

private:
    void reverse(ListNode* head)
    {
        ListNode *temp = NULL, *newHead = NULL;
        while (head != NULL)
        {
            temp = head;
            head = head->next;

            head->next = newHead;
            newHead = head;
        }
        head = newHead;
    }

    void mergeList(ListNode* first, ListNode *second, ListNode *merList)
    {
        while (first != NULL && second != NULL)
        {
            merList = first;
            first = first->next;

            merList->next = second;
            second = second->next;

            merList = merList->next->next;
        }
        if(first != NULL)
        {
            merList->next = first;
        }
    }

};

int main()
{
    // shared_ptr<List*> l = 
    return 0;
}