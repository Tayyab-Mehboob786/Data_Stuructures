#include<iostream>
struct node
{
	int val;
	node *next;
};
class queue
{
private:
    node *F;
	node *B;
	int size;
public:
	queue()
	{
		F = nullptr;
		B = nullptr;
		size = 0;
	}
	~queue()
	{
		while (F != nullptr)
		{
			node* temp;
			temp = F->next;
			delete F;
			F = temp;
			size--;
		}
		F = B = nullptr;
		size = 0;
	}
	queue(const queue& rhs)
	{
		this->size = 0;
		this->F = this->B = nullptr;
		node* temp;
		temp = rhs.F;
		while (temp != nullptr)
		{
			this->push(temp->val);
			temp = temp->next;
		}
	}
	void push(const int &val)
	{
		node* temp;
		temp = new node;
		if (temp == nullptr)
		{
			throw("Overflow");
		}
		temp->val = val;
		temp->next = nullptr;
		if (F == nullptr)
		{
			F = B = temp;
		}
		else
		{
			B->next = temp;
			B = temp;
		}
		size++;
	}
	int Front()const
	{
		if (F == nullptr)
		{
			throw("Underflow");
		}
		return F->val;
	}
	int Back()const
	{
		if (F == nullptr)
		{
			throw("Underflow");
		}
		return B->val;
	}
	bool empty()const
	{
		if (size == 0)
		{
			return true;
		}
		else
			return false;
	}
	bool full()
	{
		node* temp;
		temp = new node;
		if (temp == nullptr)
		{
			return true;
		}
		else
			delete temp;
			return false;
    }
	int Size()
	{
		return size;
	}
void pop()
	{
	if (F == nullptr)
	{
		throw("Underflow");
	}
		node* temp;
		temp = F;
		F = temp->next;
		delete temp;
		if (F == nullptr)
		{
			B = nullptr;
		}
		size--;
	}
void clear()
    {
	while (F != nullptr)
	{
		node* temp;
		temp = F->next;
		delete F;
		F = temp;
		size--;
	}
	F = B = nullptr;
	size = 0;
    }
};
int main()
{
	try {
		queue q1;
		q1.push(1);
		q1.push(3);
		q1.push(5);
		q1.push(7);
		q1.push(9);
		queue q2(q1);
		q1.pop();
		q1.pop();
		q2.pop();
		q2.pop();
		std::cout << "********FOR FIRST QUEUE********" << std::endl;
		std::cout<<"First value of Queue= " << q1.Front() << std::endl;
		std::cout<<"Last value of Queue= "  << q1.Back() << std::endl;
		std::cout<<"Size of Queue= " << q1.Size() << std::endl;
		std::cout<<"Empty or not(0/1): " << q1.empty() << std::endl;
		std::cout<<"Full or not(0/1): " << q1.full() << std::endl;
		std::cout << "********FOR SECOND QUEUE********" << std::endl;
		std::cout << "First value of Queue= " << q2.Front() << std::endl;
		std::cout << "Last value of Queue= " << q2.Back() << std::endl;
		std::cout << "Size of Queue= " << q2.Size() << std::endl;
		std::cout << "Empty or not(0/1): " << q2.empty() << std::endl;
		std::cout << "Full or not(0/1): " << q2.full() << std::endl;
		q1.clear();
		std::cout << "First value of Queue= " << q1.Front() << std::endl;
	}
	catch (const char* msg)
	{
		std::cout << msg << std::endl;
	}
}