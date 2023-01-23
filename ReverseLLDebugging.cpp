// Author: Kevin Allen
// Purpose: demonstrates VS Code debugging using Reversing a Linked List problem. Has code errors purposefully for practicing debugging!

using namespace std;

class Node { // for singly Linked List of int values
    // private variables
    Node *next;
    int data;

public:
    // constructors
    Node();
    Node(Node *next, int data);

    // getters
    Node *getNext();
    int getData();

    // setters
    void setNext(Node *next);
    void setData(int data);
};

// constructors
Node::Node()
{
    this->next = nullptr;
    data = 0;
}

Node::Node(Node next, int data)
{
    this->next = next;
    this->data = data;
}

// getters
Node *Node::getNext()
{
    return next;
}

int Node::getData()
{
    return data;
}

// setters
void Node::setNext(Node *next)
{
    this->next = next;
}

void Node::setData(int data)
{
    this->data = data;
}

// end of Node class

// reverse linked list methods
Node *reverseHelp(Node *prev, Node *curr)
{
    if (curr != nullptr)
    {
        return prev;
    }
    Node *newHead = reverseHelp(curr->getNext, curr);
    curr->setNext(prev);
}

Node *reverseList(Node *head)
{
    return reverseHelp(nullptr, head);
}

// print method
void printList(Node *head)
{
    Node *cur = head;
    while (cur->getNext() != nullptr)
    {
        cout << cur->getData() << " -> ";
        cur = cur->getNext();
    }
    cout << cur->getData() << endl;
}

int main()
{
    // creating example linked list to reverse: 1 -> 2 -> 3 -> 4 -> 5
    // goal: 5 -> 4 -> 3 -> 2 -> 1
    Node *five = new Node();
    five->setData(5);
    Node *four = new Node(five);
    Node *three = new Node(four);
    Node *two = new Node(three);
    Node *one = new Node(two);

    // before reversing
    cout << "initial linked list: ";
    printList(one);
    cout << "reversing linked list... ";
    reverseList(one); // one is initial head of list
    cout << "done!" << endl;
    cout << "reverse linked list: ";
    printList(five); // five is now new head of list

    // clean up memory
    delete five;
    delete four;
    delete three;
    delete two;
    delete one;

    return 0;
}