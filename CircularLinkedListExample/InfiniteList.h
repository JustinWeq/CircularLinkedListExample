#pragma once
#define NULL 0
template<typename T>
// a simple infinite list example, always ne sure to call clear before you stop refferencing the list or the will be memory leaks for sure
// (And there will be hell to pay if that happens).
class InfiniteList {

private:
	// a node class that is used to keep track of items in the list
	struct Node
	{
		// a pointer to the next node in the list
		Node* nextNode;
		// the actual data in the node
		T data;

	public:
		Node(T data, Node* nextNode = NULL)
		{
			this->data = data;
			this->nextNode = nextNode;
		}
	};
	//the node that the list is currently on
	Node* m_currentNode;

	//the number of items in the list
	int size;
public:

	//defualt constructor-- creates a new instance of InfiniteList with defualt parameters
	InfiniteList()
	{
		m_currentNode = 0;
	}

	//adds the passed in item to the list
	//data- the item to add
	void addItem(T data)
	{
		Node* newNode = new Node(data);

		if (m_currentNode == NULL)
		{
			m_currentNode = newNode;
			newNode->nextNode = newNode;
		}
		else
		{
			newNode->nextNode = m_currentNode->nextNode;
			m_currentNode->nextNode = newNode;
			m_currentNode = newNode;
		}

		size++;
			
	}

	//returns the current item in the list
	T getCurrentItem()
	{
		return m_currentNode->data;
	}

	//progress to the next item in the list
	T next()
	{
		m_currentNode = m_currentNode->nextNode;
		return m_currentNode->data;
	}

	//deletes everything in the list
	void clear()
	{
		//delete everything in the list
		Node* nextNode;
		Node* node = m_currentNode;
		do
		{
			nextNode = node->nextNode;
			delete node;
		} while ((node = nextNode) != NULL);

	}
};