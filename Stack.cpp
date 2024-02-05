#include<iostream>
struct node                 //Structure for Stack.
{
	int val;
	node* next;
};
class Stack
{
private:
	node *TOP;
	int SIZE;
public:
	Stack()                //Constructor 
	{
		TOP = nullptr;
		SIZE = 0;
	}
	~Stack()              //Destructor
	{
		while (TOP != nullptr)      
		{
			node* temp = TOP;
			TOP = TOP->next;
			delete temp;
		}
	}
	int Size()
	{
		return SIZE;
	}
	bool empty()     //Checking wether the Stack is empty or not.
	{
		if (TOP == nullptr)
		{
			return true;
		}
		else
			return false;
	}
	void clear() 
	{
		while (!empty())
		{
			SIZE = 0;
			pop();
		}
	}
  void push(int val)       //Function for Pushing values in a Stack.
	{
	  if (TOP == nullptr)
	  {
		  TOP = new node;
		  TOP->val = val;
		  TOP->next = nullptr;
	  }
		else
		{
			node* temp;
			temp = TOP;
			TOP = new node;
			TOP->val = val;
			TOP->next = temp;
		}
		SIZE++;
     }
  void pop()    //Function for Poping values from the Stack.
  {
	  if (Is_empty())
	  {
		  std::cout << "Stack is Empty " << std::endl;
	  }
	  else
	  {
		  node* temp = TOP;
		  TOP = TOP->next;
		  delete temp;
	  }

  }
  int Top()     //Function to return the Latest value in a Stack
  {
	  if (TOP != nullptr)
	  {
		  return TOP->val;
	  }
	  else
	  {
		  std::cout << "Top contains No value " << std::endl;
	  }
  }
  Stack& operator=(const stack& rhs)
  {
	  this->clear();
	  node* temp_rhs;
	  temp_rhs = rhs.TOP;
	  if (rhs.Top == nullptr)
	  {
		  return *this;
	  }
	  else
	  {
		  node* temp = new node;
		  temp = this->TOP;
		  temp->val = temp_rhs->val;
		  temp_rhs = temp_rhs->next;
		  while (temp_rhs != nullptr)
		  {
			  temp->next = new node;
			  temp = temp->next;
			  temp->val = temp_rhs->val;
			  temp_rhs = temp_rhs->next;
		  }
	  }

  }
 
};
int main()
{
	Stack s1;
	std::cout << "Is Stack Empty ? " << s1.Is_empty() << std::endl;
	std::cout << "Size =" << s1.Size() << std::endl;
	s1.push(6);
	std::cout << "Is Stack Empty ? " << s1.Is_empty() << std::endl;
	std::cout << "Top value is " << s1.Top() << std::endl;
	std::cout << "Size =" << s1.Size() << std::endl;
	s1.push(7);
	std::cout << "Top value is " << s1.Top() << std::endl;
	s1.push(2);
	std::cout << "Top value is " << s1.Top() << std::endl;
	s1.push(9);
	std::cout <<"Top value is "<< s1.Top() << std::endl;
	std::cout << "Size =" << s1.Size() << std::endl;
	s1.pop();
	s1.pop();
	std::cout << "Top value is "<< s1.Top() << std::endl;
	std::cout << "Size =" << s1.Size() << std::endl;
}