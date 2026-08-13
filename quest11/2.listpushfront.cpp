#include <iostream>
#include <any>

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
    };

    class List
    {
        public:
        NodeL* Head {nullptr};
        NodeL* Tail {nullptr};

        void ListPushFront(std::any data)
        {
            
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

    return EXIT_SUCCESS;
}