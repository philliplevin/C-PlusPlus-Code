// Phillip Levin, Rachel Soper
// Stack Class

#include <iostream>
#include <list>
#include <string>

using namespace std;

class Stack
{
	public:
	Stack(list<string> s); // Constructor for Stack class.
	void push(string s); // Pushes a value onto the stack.
	string top() const; // Yields the top value on the stack.
	void pop();  // Removes a value from the stack.
	int size() const; // Finds the size of the stack.
   
	private:
	list<string> elements;
   
};

Stack::Stack(list<string> s)
{
	// Assigns list s to list element 
	elements = s;
}

void Stack::push(string s)
{
	// Adds s to stack
	elements.push_front(s);
}

string Stack::top() const
{
	// Returns top of stack
	list<string> :: const_iterator it = elements.begin();
	return *it;
}

void Stack::pop()
{
	// Deletes top of stack
	list<string> :: iterator it = elements.begin();
	elements.erase(it);
}

int Stack:: size() const
{
	// Returns size of stack
	return elements.size();
}


int main()
{
	// Test code to demonstrate the functionality of the member functions for the stack class data structure 
	list<string> slist;
	Stack stack1(slist);
	stack1.push("John");
	stack1.push("Jane");
	stack1.push("Wen");
	stack1.pop();
	cout << stack1.top() << endl;
	stack1.pop();
	cout << stack1.top() << endl;
	stack1.push("Audrey");
	stack1.push("Alice");
	stack1.push("Teresa");
	stack1.pop();
	cout << stack1.top() << endl;
	stack1.pop();
	cout << stack1.top() << endl;
	cout << "Size of stack: " << stack1.size() << endl;
	cout << endl;
	
	// Prints remaining contents of the stack
	cout << "List contents: " << endl;
	while(stack1.size() != 0)
	{
		cout << stack1.top() << endl;
		stack1.pop();
	}
		
}