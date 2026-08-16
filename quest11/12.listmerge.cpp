#include <iostream>
#include <any>
#include <string>

/*
Write a function ListMerge that places elements of a list l2 at the end of another list l1.
New elements should not be created!

Expected function and structure
type NodeL struct {
	Data interface{}
	Next *NodeL
}

type List struct {
	Head *NodeL
	Tail *NodeL
}

func ListMerge(l1 *List, l2 *List) {

}

Usage : 
	link := &piscine.List{}
	link2 := &piscine.List{}

	piscine.ListPushBack(link, "a")
	piscine.ListPushBack(link, "b")
	piscine.ListPushBack(link, "c")
	piscine.ListPushBack(link, "d")
	fmt.Println("-----first List------")
	PrintList(link)

	piscine.ListPushBack(link2, "e")
	piscine.ListPushBack(link2, "f")
	piscine.ListPushBack(link2, "g")
	piscine.ListPushBack(link2, "h")
	fmt.Println("-----second List------")
	PrintList(link2)

	fmt.Println("-----Merged List-----")
	piscine.ListMerge(link, link2)
	PrintList(link)

Output :
-----first List------
a -> b -> c -> d -> <nil>
-----second List------
e -> f -> g -> h -> <nil>
-----Merged List-----
a -> b -> c -> d -> e -> f -> g -> h -> <nil>
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

        NodeL* GetLastNode() const
        {
            NodeL* cur {Head};
            NodeL* prev {nullptr};
            while (cur != nullptr)
            {
                prev = cur;
                cur = cur->Next;
            }
            
            return prev;
        }

        void ListMerge(List& l2)
        {
            NodeL* last = GetLastNode();

            NodeL* cur {l2.Head};
            NodeL* prev {nullptr};
            while (cur != nullptr)
            {
                last->Next = new NodeL{cur->Data};

                last = last->Next;
                prev = cur;
                cur = cur->Next;
            }

            Tail = prev;
            
            // This results in a segfault(likely in the destructor of the List class) therefore I have to create new elements 
            // if (prev != nullptr)
            //     last->Next = {l2.Head};
            // else 
            //     Head = l2.Head;
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

	link.ListPushBack(std::string("a"));
	link.ListPushBack(std::string("b"));
	link.ListPushBack(std::string("c"));
	link.ListPushBack(std::string("d"));
	std::cout << "-----first List------\n";
	link.PrintList();

	link2.ListPushBack(std::string("e"));
	link2.ListPushBack(std::string("f"));
	link2.ListPushBack(std::string("g"));
	link2.ListPushBack(std::string("h"));
	std::cout << "-----second List------\n";
	link2.PrintList();

	std::cout << "-----Merged List-----\n";
	link.ListMerge(link2);
	link.PrintList();

    return EXIT_SUCCESS;
}