#include <iostream>
#include <any>
#include <string>

/*
Write a function ListClear that deletes all nodes from a linked list l.
Tip: assign the list's pointer to nil.

Expected function and structure
func ListClear(l *List) {

}

Usage : 
	link := &List{}

	piscine.ListPushBack(link, "I")
	piscine.ListPushBack(link, 1)
	piscine.ListPushBack(link, "something")
	piscine.ListPushBack(link, 2)

	fmt.Println("------list------")
	PrintList(link)
	piscine.ListClear(link)
	fmt.Println("------updated list------")
	PrintList(link)

Output : 
------list------
I -> 1 -> something -> 2 -> <nil>
------updated list------
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

        void ListClear()
        {
           NodeL* temp {nullptr};
           while (Head != nullptr)
           {
                temp = Head;
                Head = Head->Next;
                delete temp;
           }  
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
                    Tail->Next = newNode;
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
    piscine::List link {};

	link.ListPushBack("I");
	link.ListPushBack(1);
	link.ListPushBack("something");
	link.ListPushBack(2);

	std::cout << "------list------\n";
	link.PrintList();
	link.ListClear();
	std::cout << "------updated list------\n";
	link.PrintList();

    return EXIT_SUCCESS;
}