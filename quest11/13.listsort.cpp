#include <iostream>
#include <vector>

/*
Write a function ListSort that sorts the nodes of a linked list by ascending order.

Expected function and structure
type NodeI struct {
	Data int
	Next *NodeI
}

func ListSort(l *NodeI) *NodeI {

}

Usage : 
func PrintList(l *piscine.NodeI) {
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

	link = listPushBack(link, 5)
	link = listPushBack(link, 4)
	link = listPushBack(link, 3)
	link = listPushBack(link, 2)
	link = listPushBack(link, 1)

	PrintList(piscine.ListSort(link))
}
Output :
1 -> 2 -> 3 -> 4 -> 5 -> <nil>
*/

namespace piscine
{
    class NodeI
    {
        public:
        int Data {0};
        NodeI* Next {nullptr};
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
    NodeI* ListSort(NodeI* l)
    {
        if (l == nullptr)
            return nullptr;

        std::vector<NodeI*> vec {};
        NodeI* node {l};
        while (node != nullptr)
        {
            vec.push_back(node);
            node = node->Next;
        }

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

	link = piscine::listPushBack(link, 5);
	link = piscine::listPushBack(link, 4);
	link = piscine::listPushBack(link, 3);
	link = piscine::listPushBack(link, 2);
	link = piscine::listPushBack(link, 1);

	piscine::PrintList(piscine::ListSort(link));

    return EXIT_SUCCESS;
}