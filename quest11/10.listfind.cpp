#include <iostream>
#include <any>

/*
Write a function ListFind that returns the address of the data interface of the first node in the 
list l that is determined to be equal to ref by the function CompStr.
For this exercise the function CompStr must be used.

Expected function and structure
type NodeL struct {
	Data interface{}
	Next *NodeL
}

type List struct {
	Head *NodeL
	Tail *NodeL
}

func CompStr(a, b interface{}) bool {
	return a == b
}

func ListFind(l *List, ref interface{}, comp func(a, b interface{}) bool) *interface{} {

}

Usage : 
    link := &piscine.List{}

	piscine.ListPushBack(link, "hello")
	piscine.ListPushBack(link, "hello1")
	piscine.ListPushBack(link, "hello2")
	piscine.ListPushBack(link, "hello3")

	found := piscine.ListFind(link, interface{}("hello2"), piscine.CompStr)

	fmt.Println(found)
	fmt.Println(*found)
Output :
0xc42000a0a0
hello2
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

    bool CompStr(std::any a, std::any b)
    {
        if (a.type() == typeid(int) && b.type() == typeid(int)) {
            return std::any_cast<int>(a) == std::any_cast<int>(b);
        }  else if (a.type() == typeid(std::string) || b.type() == typeid(std::string)) {
            return std::any_cast<std::string>(a) == std::any_cast<std::string>(b);
        } else {
            return false;
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

        std::any* ListFind(std::any ref, bool (*comp) (std::any,std::any))
        {
            NodeL* node {Head};
            while (node != nullptr)
            {
                if(comp(ref,node->Data))
                    return &(node->Data);
                node = node->Next;
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

	link.ListPushBack(std::string("hello"));
	link.ListPushBack(std::string("hello1"));
	link.ListPushBack(std::string("hello2"));
	link.ListPushBack(std::string("hello3"));

	std::any* found = link.ListFind(std::any(std::string("hello2")), piscine::CompStr);

	std::cout << found << "\n";
    piscine::printAny(*found);

    return EXIT_SUCCESS;
}