#include <iostream>
#include <any>
#include <string>
#include <cstdint>

/*
Write a function ListForEachIf that applies a function given as argument to the data within some of the nodes of the list l.
This function receives two functions:
f is a function that is applied to the node.
cond is a function that returns a boolean and it will be used to determine if the function f should be applied to the node.
The function given as argument must have a pointer *NodeL as argument.

Expected function and structure
type NodeL struct {
	Data interface{}
	Next *NodeL
}

type List struct {
	Head *NodeL
	Tail *NodeL
}

func IsPositiveNode(node *NodeL) bool {
	switch node.Data.(type) {
	case int, float32, float64, byte:
		return node.Data.(int) > 0
	default:
		return false
	}
}

func IsAlNode(node *NodeL) bool {
	switch node.Data.(type) {
	case int, float32, float64, byte:
		return false
	default:
		return true
	}
}


func ListForEachIf(l *List, f func(*NodeL), cond func(*NodeL) bool) {

}


func PrintElem(node *piscine.NodeL) {
	fmt.Println(node.Data)
}

func StringToInt(node *piscine.NodeL) {
	node.Data = 2
}

func PrintList(l *piscine.List) {
	it := l.Head
	for it != nil {
		fmt.Print(it.Data, "->")
		it = it.Next
	}
	fmt.Print("nil", "\n")
}

Usage : 
    link := &piscine.List{}

	piscine.ListPushBack(link, 1)
	piscine.ListPushBack(link, "hello")
	piscine.ListPushBack(link, 3)
	piscine.ListPushBack(link, "there")
	piscine.ListPushBack(link, 23)
	piscine.ListPushBack(link, "!")
	piscine.ListPushBack(link, 54)

	PrintList(link)

	fmt.Println("--------function applied--------")
	piscine.ListForEachIf(link, PrintElem, piscine.IsPositiveNode)

	piscine.ListForEachIf(link, StringToInt, piscine.IsAlNode)

	fmt.Println("--------function applied--------")
	PrintList(link)

	fmt.Println()

Output : 
1->hello->3->there->23->!->54->nil
--------function applied--------
1
3
23
54
--------function applied--------
1->2->3->2->23->2->54->nil
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

		void ListForEachIf(void(*f)(NodeL*), bool(*cond)(NodeL*))
		{
			NodeL* node {Head};
			while (node != nullptr)
			{
                if (cond(node))
				    f(node);
				node = node->Next;
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

	bool IsPositiveNode(NodeL* node) {
		const std::any a {node->Data};

        if (a.type() == typeid(int) || a.type() == typeid(float) || a.type() == typeid(double) || a.type() == typeid(int8_t)) {
			return std::any_cast<int>(node->Data) > 0;
        }  else {
            return false;
        }  
    }

    bool IsAlNode(NodeL* node) {
		const std::any a {node->Data};

        if (a.type() == typeid(int) || a.type() == typeid(float) || a.type() == typeid(double) || a.type() == typeid(int8_t)) {
			return false;
        }  else {
            return true;
        }  
    }

    void StringToInt(NodeL* node)
    {
        node->Data = 2;
    }

    void PrintElem(NodeL* node)
    {
       printAny(node->Data);
       std::cout << "\n";
    }
} // namespace piscine


int main()
{
    piscine::List link {};

	link.ListPushBack(1);
	link.ListPushBack("hello");
	link.ListPushBack(3);
	link.ListPushBack("there");
	link.ListPushBack(23);
	link.ListPushBack("!");
	link.ListPushBack(54);

	link.PrintList();

	std::cout << "--------function applied--------\n";
	link.ListForEachIf(piscine::PrintElem, piscine::IsPositiveNode);

	link.ListForEachIf(piscine::StringToInt, piscine::IsAlNode);

	std::cout << "--------function applied--------\n";
	link.PrintList();

    return EXIT_SUCCESS;
}