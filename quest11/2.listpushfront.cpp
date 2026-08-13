#include <iostream>
#include <any>
#include <string>

/*
Write a function ListPushFront that inserts a new element NodeL at the beginning of the list l while using the structure List

Expected function and structure
type NodeL struct {
	Data interface{}
	Next *NodeL
}

type List struct {
	Head *NodeL
	Tail *NodeL
}

func ListPushFront(l *List, data interface{}) {

}

Usage : 
    link := &piscine.List{}

	piscine.ListPushFront(link, "Hello")
	piscine.ListPushFront(link, "man")
	piscine.ListPushFront(link, "how are you")

	it := link.Head
	for it != nil {
		fmt.Print(it.Data, " ")
		it = it.Next
	}
	fmt.Println()

Output : 
how are you man Hello
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

        // Deallocate memory
        ~List()
        {
            NodeL* temp {nullptr};
            while(Head != nullptr)
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
    piscine::List link {};

	link.ListPushFront(std::string("Hello"));
	link.ListPushFront(std::string("man"));
	link.ListPushFront(std::string("how are you"));

    piscine::NodeL* node {link.Head};
    while (node != nullptr)
    {
        std::cout << std::any_cast<std::string>(node->Data) << " ";
        node = node->Next;
    }

    return EXIT_SUCCESS;
}