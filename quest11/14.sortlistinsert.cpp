#include <iostream>
#include <vector>

/*
Create a function named SortListInsert, which accepts a pointer to the head of a sorted linked list and an integer.

The function should insert a new element into the list, with its Data set to the value of the integer. 
The element should be inserted so that the linked list remains sorted in ascending order by Data. 
The function should return the head of the list.

Your function will only be tested with sorted linked lists.

Expected function and structure
func SortListInsert(l *NodeI, data_ref int) *NodeI{

}

Usage : 
PrintList(l *piscine.NodeI) {
	it := l
	for it != nil {
		fmt.Print(it.Data, " -> ")
		it = it.Next
	}
	fmt.Print(nil, "\n")
}

func listPushBack(l *piscine.NodeI, data int) *piscine.NodeI {
	n := &piscine.NodeI{Data: data}

	if l == nil {
		return n
	}
	iterator := l
	for iterator.Next != nil {
		iterator = iterator.Next
	}
	iterator.Next = n
	return l
}

func main() {

	var link *piscine.NodeI

	link = listPushBack(link, 1)
	link = listPushBack(link, 4)
	link = listPushBack(link, 9)

	PrintList(link)

	link = piscine.SortListInsert(link, -2)
	link = piscine.SortListInsert(link, 2)
	PrintList(link)
}

Output :
1 -> 4 -> 9 -> <nil>
-2 -> 1 -> 2 -> 4 -> 9 -> <nil>
*/

namespace piscine
{
     class NodeI
    {
        public:
        int Data {0};
        NodeI* Next {nullptr};

        NodeI(int data, NodeI* next=nullptr)
         : Data {data}, Next {next}
        {}
    };

    NodeI* listPushBack(NodeI* l,int data)
    {
        NodeI* newNode {new NodeI{data}};

        if (l == nullptr)
        {
            return newNode;
        }
        else
        {
            if (l->Next == nullptr)
                l->Next = newNode;
            else 
            {
                NodeI* cur {l};
                NodeI* prev {nullptr};
                while (cur != nullptr)
                {
                    prev = cur;
                    cur = cur->Next;
                }

                prev->Next = newNode;
            }
        }

        return l;
    }

    void bubbleSortNodes(std::vector<NodeI*>& vec)
    {
        int len {static_cast<int>(vec.size())};
        for (int i {0}; i < len-1; ++i)
        {
            for (int j {0}; j < len-1-i; ++j)
            {
                NodeI* a {vec[j]};
                NodeI* b {vec[j+1]};
                if (a->Data > b->Data)
                {
                    NodeI* temp {vec[j]};
                    vec[j] = vec[j+1];
                    vec[j+1] = temp;
                }
            }
        }
    }

    void updateNodeNextPtrs(std::vector<NodeI*>& vec)
    {
        int len {static_cast<int>(vec.size())};
        for (int i {0}; i < len; ++i)
        {
            NodeI* node {vec[i]};
            if (i == (len-1))
                node->Next = nullptr;
            else
                node->Next = vec[i+1];
        }
    }

    // TODO: Find another way to do this
    NodeI* SortListInsert(NodeI* l, int data)
    {
        if (l == nullptr)
            return nullptr;

        std::vector<NodeI*> vec {};
        NodeI* cur {l};
        NodeI* prev {nullptr}; // Will point to last 
        while (cur != nullptr)
        {
            vec.push_back(cur);
            prev = cur;
            cur = cur->Next;
        }

        // Add new node
        NodeI* newNode {new NodeI{data}};
        prev->Next = newNode;
        vec.push_back(newNode);

        bubbleSortNodes(vec);
        
        updateNodeNextPtrs(vec);
        
        l = vec[0];

        return l;
    }

    void PrintList(NodeI* l)
    {
        NodeI* node {l};
        while (node != nullptr)
        {
            std::cout << node->Data;
            std::cout << " -> ";
            node = node->Next;
        }

        std::cout << "<nil>\n";
    }
} // namespace piscine

int main()
{
    piscine::NodeI* link {nullptr};

	link = piscine::listPushBack(link, 1);
	link = piscine::listPushBack(link, 4);
	link = piscine::listPushBack(link, 9);

	PrintList(link);

	link = piscine::SortListInsert(link, -2);
	link = piscine::SortListInsert(link, 2);
	PrintList(link);

    return EXIT_SUCCESS;
}