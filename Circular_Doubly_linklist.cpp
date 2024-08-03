#include<iostream>
struct dnode
{
    int val;
    dnode* next, * prev;
   dnode()
    {
        val = 0;
        next = nullptr;
        prev = nullptr;
    }
};
class doubly_list
{
private:
    dnode* head, * F, * B;
    int size;
public:
    doubly_list()
    {
        size = 0;
        head = new dnode;
        head->next = head;
        head->prev = head;
        F = nullptr;
        B = nullptr;
    }
    int front()
    {
        return head->next->val;
    }
    int back()
    {
        return head->prev->val;
    }
    void push_front(const int& val) //Pushing values after the dummy node[head];
    {
        dnode* temp;
        temp = new dnode;
        temp->val = val;
        temp->prev = head;
        temp->next= head->next;
        head->next->prev = temp;
        head->next = temp;
        F = temp;
        size++;
    }
    void push_back(const int& val) //Pusing values at the end (before the dummy node[head]);
    {
        dnode* temp;
        temp = new dnode;
        temp->val = val;
        temp->next = head;
        temp->prev = head->prev;
        head->prev->next = temp;
        head->prev = temp;
        B = temp;
        size++;
    }
    void pop_front() //Poping values after the dummy node[head];
    {
        dnode* temp;
        temp = new dnode;
        temp = F->next;
        head->next = temp;
        temp->prev = head;
        delete F;
        F = temp;
        size--;
    }
    void pop_back()   //Poping values at the end (before the dummy node[head]);
    {
        dnode* temp;
        temp = new dnode;
        temp = B->prev;
        head->prev = temp;
        temp->next = head;
        delete B;
        B = temp;
        size--;
    }
    void swap(int n1, int n2) //Function for swaping the values;
    {
        if (head == nullptr || n1 == n2) {

            return;
        }
        dnode* dnodeX = nullptr, * dnodeY = nullptr;
        dnode* temp = head;
        while (temp->next != head)
        {
            if (temp->val == n1) {
                dnodeX = temp;
            }
            else if (temp->val == n2) {
               dnodeY = temp;
            }
            temp = temp->next;
        }
        if (temp->val == n1) {
            dnodeX = temp;
        }
        else if (temp->val == n2) {
            dnodeY = temp;
        }
        if (dnodeX != nullptr && dnodeY != nullptr) {
            int val = dnodeX->val;
            dnodeX->val = dnodeY->val;
            dnodeY->val = val;
        }
        else {
            std::cout << "One or both nodes not found." << std::endl;
            return;
        }
    }
    void sorting() //Function for sorting the Doubly link list;
    {
        dnode* temp = head->next;
        bool check = true;
        while (check) {
            check = false;
            temp = head->next;
            while (temp->next != head)
            {
                if (temp->val > temp->next->val)
                {
                    swap(temp->val, temp->next->val);
                    check = true;
                }
                temp = temp->next;
            }
        }
    }
};
int main()
{
    doubly_list l1;
    l1.push_front(3);
    l1.push_front(67);
    l1.push_back(8);
    l1.push_back(122);
    l1.push_front(5);
    l1.push_front(87);
    l1.push_back(23);
    l1.push_back(00);
    l1.push_back(342);
    l1.push_back(653);
    l1.push_back(1010);
    l1.push_back(4);
    l1.push_back(2);
    l1.push_back(5);
    std::cout << l1.front() << std::endl;
    std::cout << l1.back() << std::endl;
    l1.sorting();
}