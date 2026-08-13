#include <iostream>
#include <any>
#include <string>

/*
Write a function ListSize that returns the number of elements in a linked list l.

Expected function and structure
type NodeL struct {
	Data interface{}
	Next *NodeL
}

type List struct {
	Head *NodeL
	Tail *NodeL
}

func ListSize(l *List) int {

}

Usage :
	link := &piscine.List{}

	piscine.ListPushFront(link, "Hello")
	piscine.ListPushFront(link, "2")
	piscine.ListPushFront(link, "you")
	piscine.ListPushFront(link, "man")

	fmt.Println(piscine.ListSize(link))

Output : 
4
*/

namespace piscine
{
    class NodeL
    {
        public:
        std::any Data;
        NodeL* Next;

        NodeL(std::any data, NodeL* next=nullptr)
            : Data {data}, Next {next}
        {}
    };

    class List
    {
        public:
        NodeL* Head {nullptr};
        NodeL* Tail {nullptr};

        void ListPushFront(std::any data)
        {
            NodeL* newNode {new NodeL{data} };
            if (Head == nullptr)
                Head = newNode;
            else 
            {
                NodeL* temp {Head};
                Head = newNode;
                Head->Next = temp;
            }
        }

        int ListSize()
        {
            int count {0};
            NodeL* node {Head};
            while (node != nullptr)
            {
                count++;
                node = node->Next;
            }

            return count;
        }

        ~List()
        {
            NodeL* temp {};
            while (Head != nullptr)
            {
                temp = Head;
                Head = Head->Next;
                delete temp;
            }
        }
    };
} // namespace piscine

int main()
{
    piscine::List link;

	link.ListPushFront(std::string("Hello"));
	link.ListPushFront(std::string("2"));
	link.ListPushFront(std::string("you"));
	link.ListPushFront(std::string("man"));

	std::cout << link.ListSize();

    return EXIT_SUCCESS;
}