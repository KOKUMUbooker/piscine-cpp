#include <iostream>
#include <any>
#include <string>

/*
Write a function ListAt that takes a pointer to the head of the list l and an int pos as parameters. 
This function should return the pointer to the NodeL in the position pos of the linked list l.
In case of error the function should return nil.

Expected function and structure
type NodeL struct {
	Data interface{}
	Next *NodeL
}

func ListAt(l *NodeL, pos int) *NodeL{

}

Usage : 
	link := &piscine.List{}

	piscine.ListPushBack(link, "hello")
	piscine.ListPushBack(link, "how are")
	piscine.ListPushBack(link, "you")
	piscine.ListPushBack(link, 1)

	fmt.Println(piscine.ListAt(link.Head, 3).Data)
	fmt.Println(piscine.ListAt(link.Head, 1).Data)
	fmt.Println(piscine.ListAt(link.Head, 7))

Output : 
1
how are
<nil>
*/

namespace piscine
{
    void printAny(const std::any& a) {
        if (!a.has_value()) {
            std::cout << "Empty";
        } else if (a.type() == typeid(int)) {
            std::cout << std::any_cast<int>(a);
        }  else if (a.type() == typeid(std::string)) {
            std::cout << std::any_cast<std::string>(a);
        } else if (a.type() == typeid(const char*)) {
            std::cout << std::any_cast<const char*>(a);
        } else {
            std::cout << "Unknown type: " << a.type().name();
        }
    }

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

        NodeL* ListAt(int pos) const
        {
            if (Head == nullptr)
                return nullptr;

            NodeL* node {Head};
            int i {0};
            while (node != nullptr)
            {
                if (i == pos)
                    return node;
                
                node = node->Next;
                ++i;
            }
            
            return nullptr;
        }

        void PrintList()
        {
            NodeL* node {Head};
            while (node != nullptr)
            {
                printAny(node->Data);
                node = node->Next;
                std::cout << " -> ";
            }

            std::cout << "<nil>\n";
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

    
    void PrintNode(NodeL* node)
    {
        if (node == nullptr)   
            std::cout << "<nil>";
        else
        {
            std::cout << "{ ";
            printAny(node->Data);
            std::cout << " " << node->Next << " }\n";
        }
    }
    
} // namespace piscine

int main()
{
	piscine::List link {};

	link.ListPushBack("hello");
	link.ListPushBack("how are");
	link.ListPushBack("you");
	link.ListPushBack(1);
    link.PrintList();

	piscine::printAny(link.ListAt(3)->Data);
    std::cout << "\n";
	piscine::printAny(link.ListAt(1)->Data);
    std::cout << "\n";
	piscine::PrintNode(link.ListAt(7));
    std::cout << "\n";

    return EXIT_SUCCESS;
}