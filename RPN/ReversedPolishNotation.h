#ifndef zad1_H_INCLUDED
#define zad1_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cmath>
#include <cstring>

using namespace std;

template <typename T>
struct Node
{
	T data;
	Node* next;
};

template <typename T>
class LStack
{
	Node<T>* topNode;
	void copy(Node<T>*);
	void eraseLStack();
	void copyLStack(LStack const&);

public:
	LStack();
	LStack(LStack const&);
	LStack& operator=(LStack const&);
	~LStack();

	void ResetStack() {
		eraseLStack();
	}

	bool empty() const;
	void push(T const&);
	T pop();
	T top() const;

	void print();
};

template<typename T>
void LStack<T>::copy(Node<T>* toCopy)
{
	if (toCopy == nullptr)
		return;
	copy(toCopy->next);
	push(toCopy->data);
}

template<typename T>
void LStack<T>::eraseLStack()
{
	while (!empty())
		pop();
}

template<typename T>
void LStack<T>::copyLStack(LStack const &ls)
{
	topNode = nullptr;
	copy(ls.topNode);
}

template<typename T>
LStack<T>::LStack()
{
	topNode = nullptr;
}

template<typename T>
LStack<T>::LStack(LStack const &ls)
{
	copyLStack(ls);
}

template<typename T>
LStack<T> & LStack<T>::operator=(LStack const &ls)
{
	if (this != &ls) {
		eraseLStack();
		copyLStack(ls);
	}
	return *this;
}

template<typename T>
LStack<T>::~LStack()
{
	eraseLStack();
}

template<typename T>
bool LStack<T>::empty() const
{
	return topNode == nullptr;
}

template<typename T>
void LStack<T>::push(T const &element)
{
	Node<T>* p = new Node<T>;
	p->data = element;
	p->next = topNode;
	topNode = p;
}

template<typename T>
T LStack<T>::pop()
{
	if (empty()) {
		//cerr << "Empty stack!" << endl;
		return 0;
	}

	Node<T>* p = topNode;
	topNode = topNode->next;
	T x = p->data;
	delete p;

	return x;
}

template<typename T>
T LStack<T>::top() const
{
	if (empty()) {
		//cerr << "Empty stack!" << endl;
		return 0;
	}

	return topNode->data;
}

template<typename T>
void LStack<T>::print()
{
	while (!empty()) {
		int x = pop();
		cout << x << " ";
	}
}

double calculate(char* s)
{
	LStack<double> values;
	int a, b;
	bool undefined = false;
	for(int i = 0; i < strlen(s); i++)
    {
		if(isdigit(s[i]))
        {
			a = s[i] - '0';
			values.push(a);
		}
		else
			{
				switch(s[i])
				{
					case '+':
						b = values.top();
						values.pop();
						a = values.top();
						values.pop();
						values.push(a + b);
                    break;

					case '-':
						b = values.top();
						values.pop();
						a = values.top();
						values.pop();
						values.push(a - b);
                    break;

					case '*':
						b = values.top();
						values.pop();
						a = values.top();
						values.pop();
						values.push(a * b);
                    break;

					case '/':
						b = values.top();
						values.pop();
						if (b == 0)
							undefined = true;
						else
						{
							a = values.top();
							values.pop();
							values.push(a / b);
						}
                    break;

                    case '%':
						b = values.top();
						values.pop();
						a = values.top();
						values.pop();
						values.push(a % b);
                    break;
				}
			}
	}
	if(undefined)
    {
        cout<<"Wrong values!"<<endl;
    }
	else
	{
		cout<<values.top();
	}
}

#endif // 1_H_INCLUDED
