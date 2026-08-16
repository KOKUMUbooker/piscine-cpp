#include <iostream>
#include <any>

/*
Write a function ListRemoveIf that removes all elements that are equal to the data_ref in the argument of the function.

Expected function and structure
type NodeL struct {
	Data interface{}
	Next *NodeL
}

type List struct {
	Head *NodeL
	Tail *NodeL
}

func ListRemoveIf(l *List, data_ref interface{}) {

}

Usage : 
    link := &piscine.List{}
	link2 := &piscine.List{}

	fmt.Println("----normal state----")
	piscine.ListPushBack(link2, 1)
	PrintList(link2)
	piscine.ListRemoveIf(link2, 1)
	fmt.Println("------answer-----")
	PrintList(link2)
	fmt.Println()

	fmt.Println("----normal state----")
	piscine.ListPushBack(link, 1)
	piscine.ListPushBack(link, "Hello")
	piscine.ListPushBack(link, 1)
	piscine.ListPushBack(link, "There")
	piscine.ListPushBack(link, 1)
	piscine.ListPushBack(link, 1)
	piscine.ListPushBack(link, "How")
	piscine.ListPushBack(link, 1)
	piscine.ListPushBack(link, "are")
	piscine.ListPushBack(link, "you")
	piscine.ListPushBack(link, 1)
	PrintList(link)

	piscine.ListRemoveIf(link, 1)
	fmt.Println("------answer-----")
	PrintList(link)

Output :
----normal state----
1 -> <nil>
------answer-----
<nil>

----normal state----
1 -> Hello -> 1 -> There -> 1 -> 1 -> How -> 1 -> are -> you -> 1 -> <nil>
------answer-----
Hello -> There -> How -> are -> you -> <nil>
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

    bool CompNodeData(std::any a, std::any b)
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

        void ListRemoveIf(std::any data_ref)
        {
            NodeL* cur {Head};
            NodeL* prev {nullptr};
            NodeL* next {nullptr};
            while (cur != nullptr)
            {
                next = cur->Next;

                if (CompNodeData(cur->Data, data_ref))
                {
                    if (prev != nullptr)
                    {
                        prev->Next = next;
                        delete cur;
                    }
                    else 
                    {
                        Head = next;
                    }
                    
                    cur = next;
                    continue;
                }

                prev = cur;
                cur = next;
            }
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
	piscine::List link2 {};

	std::cout << "----normal state----\n";
	link2.ListPushBack( 1);
	link2.PrintList();
	link2.ListRemoveIf(1);
	std::cout << "------answer-----\n";
	link2.PrintList();

	std::cout << "----normal state----\n";
	link.ListPushBack(1);
	link.ListPushBack("Hello");
	link.ListPushBack(1);
	link.ListPushBack("There");
	link.ListPushBack(1);
	link.ListPushBack(1);
	link.ListPushBack("How");
	link.ListPushBack(1);
	link.ListPushBack("are");
	link.ListPushBack("you");
	link.ListPushBack(1);
	link.PrintList();

	link.ListRemoveIf(1);
	std::cout << "------answer-----\n";
	link.PrintList();

    return EXIT_SUCCESS;
}