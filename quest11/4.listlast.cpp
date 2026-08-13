#include <iostream>
#include <any>
#include <string>

/*
Write a function ListLast that returns the Data interface of the last element of a linked list l.

Expected function and structure
type NodeL struct {
	Data interface{}
	Next *NodeL
}

type List struct {
	Head *NodeL
	Tail *NodeL
}

func ListLast(l *List) interface{} {

}

Usage :
	link := &piscine.List{}
	link2 := &piscine.List{}

	piscine.ListPushBack(link, "three")
	piscine.ListPushBack(link, 3)
	piscine.ListPushBack(link, "1")

	fmt.Println(piscine.ListLast(link))
	fmt.Println(piscine.ListLast(link2))

Output :
1
<nil>
*/

namespace piscine
{
    class NodeL
    {
        public:
        std::any Data;
        NodeL* Next {nullptr};

        NodeL(std::any data, NodeL* next=nullptr)
            : Data {data}, Next {next}
        {}
    };

    class List
    {
        public:
        NodeL* Head {nullptr};
        NodeL* Tail {nullptr};

        std::any ListLast()
        {
            NodeL* node {Head};
            while(true)
            {
                if (node == nullptr)
                    break;
                if (node->Next == nullptr)
                    break;
                node = node->Next;
            }

            if (node == nullptr)
            {
                return std::string("<nil>");
            }

            return node->Data;
        }

         void ListPushBack(std::any data)
        {
            NodeL* newNode {new NodeL{data}};

            if (Head == nullptr)
            {
                Head = newNode;
            }
            else
            {
                if (Head->Next == nullptr)
                    Head->Next = newNode;

                if (Tail == nullptr)
                    Tail = newNode;
                else 
                {
                    Tail->Next = newNode;
                    Tail = newNode;
                }
            }
        }

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

    void printAny(const std::any& a) {
        if (!a.has_value()) {
            std::cout << "Empty\n";
        } else if (a.type() == typeid(int)) {
            std::cout << std::any_cast<int>(a) << "\n";
        }  else if (a.type() == typeid(std::string)) {
            std::cout << std::any_cast<std::string>(a) << "\n";
        } else if (a.type() == typeid(const char*)) {
            std::cout << std::any_cast<const char*>(a) << "\n";
        } else {
            std::cout << "Unknown type: " << a.type().name() << "\n";
        }
    }
} // namespace piscine

int main()
{
    piscine::List link {};
	piscine::List link2 {};

	link.ListPushBack(std::string("three"));
	link.ListPushBack(3);
	link.ListPushBack(std::string("1"));

    piscine::printAny(link.ListLast());
    piscine::printAny(link2.ListLast());

    return EXIT_SUCCESS;
}