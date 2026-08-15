#include <iostream>
#include <any>

/*
Write a function ListReverse that reverses the order of the elements of a given linked list l.

Expected function and structure
type NodeL struct {
	Data interface{}
	Next *NodeL
}

type List struct {
	Head *NodeL
	Tail *NodeL
}

func ListReverse(l *List) {

}

Usage : 
	link := &piscine.List{}

	piscine.ListPushBack(link, 1)
	piscine.ListPushBack(link, 2)
	piscine.ListPushBack(link, 3)
	piscine.ListPushBack(link, 4)

	piscine.ListReverse(link)

	it := link.Head

	for it != nil {
		fmt.Println(it.Data)
		it = it.Next
	}

	fmt.Println("Tail", link.Tail)
	fmt.Println("Head", link.Head)

Output : 
4
3
2
1
Tail &{1 <nil>}
Head &{4 0xc42000a140}
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

        // Original
        // 1 -> 2 -> 3 -> null

        // Reversed
        //{1, null}   {2, *1}    {3, *2}
        // prev=null  prev=1     prev=2
        // cur=1      cur=2      cur=3
        // next=2     next=3     next=null
        void ListReverse()
        {
            NodeL* prev {nullptr};
            NodeL* cur {Head};
            NodeL* next {nullptr};

            Tail = Head; // old head becomes new tail

            while (cur != nullptr)
            {
                next = cur->Next;   // save before overwriting
                cur->Next = prev;   // reverse the link
                prev = cur;         // move prev forward
                cur = next;         // move cur forward
            }

            Head = prev; // prev ends up on the last real node
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

	link.ListPushBack(1);
	link.ListPushBack(2);
	link.ListPushBack(3);
	link.ListPushBack(4);

    std::cout << "Before reverse : \n";
    link.PrintList();
    
    std::cout << "After reverse : \n";
	link.ListReverse();

	// piscine::NodeL* it {link.Head};

	// while (it != nullptr) {
    //     piscine::printAny(it->Data);
	// 	std::cout << "\n";
	// 	it = it->Next;
	// }
    link.PrintList();

	std::cout << "Tail"; 
    piscine::PrintNode(link.Tail);
    std::cout << "\n";

    std::cout << "Head"; 
    piscine::PrintNode(link.Head);
    std::cout << "\n";

    return EXIT_SUCCESS;
}