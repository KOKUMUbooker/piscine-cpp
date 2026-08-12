#include <iostream>
#include <string>

/*
Write a function ListPushBack that inserts a new element NodeL at the end of the list l while using the structure List.

Expected function and structure
    type NodeL struct {
        Data interface{}
        Next *NodeL
    }

    type List struct {
        Head *NodeL
        Tail *NodeL
    }

    func ListPushBack(l *List, data interface{}) {

    }

Usage (Go) :
    link := &piscine.List{}

    piscine.ListPushBack(link, "Hello")
    piscine.ListPushBack(link, "man")
    piscine.ListPushBack(link, "how are you")

    for link.Head != nil {
        fmt.Println(link.Head.Data)
        link.Head = link.Head.Next
    }

Output :
    Hello
    man
    how are you
*/

namespace piscine
{
    class NodeL
    {
        public:
        std::string Data;
        NodeL* Next {nullptr};

        NodeL(std::string data, NodeL* next=nullptr) 
            : Data {data}, Next {next} 
        {}
    };

    class List
    {
        public:
        NodeL* Head {nullptr};
        NodeL* Tail {nullptr};

        // Free memory
        ~List()
        {
            NodeL* temp {Head};
            while (Head != nullptr)
            {
                temp = Head;
                Head = Head->Next;
                delete temp;
            }
        }
    };
    
    void ListPushBack(List* l, std::string data)
    {
        NodeL* newNode {new NodeL{data}};

        if (l->Head == nullptr)
        {
            l->Head = newNode;
        }
        else
        {
            if (l->Head->Next == nullptr)
                l->Head->Next = newNode;

            if (l->Tail == nullptr)
                l->Tail = newNode;
            else 
                l->Tail->Next = newNode;
        }
    }

} // namespace piscine


int main()
{
    piscine::List link {};

    piscine::ListPushBack(&link, "Hello");
    piscine::ListPushBack(&link, "man");
    piscine::ListPushBack(&link, "how are you");

    piscine::NodeL* node {link.Head};
    while (node != nullptr)
    {
        std::cout << node->Data << "\n"; 
        node = node->Next;
    }

    return EXIT_SUCCESS;
}