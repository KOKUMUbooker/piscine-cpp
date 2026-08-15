#include <iostream>
#include <any>
#include <string>
/*
Write a function ListForEach that applies a function given as argument to the data within each node of the list l.
The function given as argument must have a pointer as argument: l *List
Copy the functions Add2_node and Subtract3_node in the same file as the function ListForEach is defined.

Usage : 
type NodeL struct {
	Data interface{}
	Next *NodeL
}

type List struct {
	Head *NodeL
	Tail *NodeL
}

func ListForEach(l *List, f func(*NodeL)) {

}

func Add2_node(node *NodeL) {
	switch node.Data.(type) {
	case int:
		node.Data = node.Data.(int) + 2
	case string:
		node.Data = node.Data.(string) + "2"
	}
}

func Subtract3_node(node *NodeL) {
	switch node.Data.(type) {
	case int:
		node.Data = node.Data.(int) - 3
	case string:
		node.Data = node.Data.(string) + "-3"
	}
}

link := &piscine.List{}

piscine.ListPushBack(link, "1")
piscine.ListPushBack(link, "2")
piscine.ListPushBack(link, "3")
piscine.ListPushBack(link, "5")

piscine.ListForEach(link, piscine.Add2_node)

it := link.Head
for it != nil {
	fmt.Println(it.Data)
	it = it.Next
	}
        
Output : 
12
22
32
52
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

		void ListForEach(void(*f)(NodeL*))
		{
			NodeL* node {Head};
			while (node != nullptr)
			{
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

	void Add2_node(NodeL* node) {
		const std::any& a {node->Data};
		if (!a.has_value())
			return;

        if (a.type() == typeid(int)) {
			node->Data = std::any_cast<int>(node->Data) + 2;
        }  else if (a.type() == typeid(std::string)) {
			node->Data = std::any_cast<std::string>(node->Data) + "2";
        }  
    }

	void Subtract3_node(NodeL* node) {
		const std::any& a {node->Data};
		if (!a.has_value())
			return;

        if (a.type() == typeid(int)) {
			node->Data = std::any_cast<int>(node->Data) - 3;
        }  else if (a.type() == typeid(std::string)) {
			node->Data = std::any_cast<std::string>(node->Data) + "-3";
        }  
    }
    
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

	link.ListPushBack(std::string("1"));
	link.ListPushBack(std::string("2"));
	link.ListPushBack(std::string("3"));
	link.ListPushBack(std::string("5"));

	link.ListForEach(piscine::Add2_node);

	piscine::NodeL* it {link.Head};
	while (it != nullptr) {
		piscine::printAny(it->Data);
		std::cout << "\n";
		it = it->Next;
	}

	return EXIT_SUCCESS;
}