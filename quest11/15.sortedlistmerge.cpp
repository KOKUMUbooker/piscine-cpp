#include <iostream>
#include <vector>

/*
Write a function SortedListMerge that merges two lists n1 and n2 in ascending order.
During the tests n1 and n2 will already be initially sorted.

Expected function and structure
func SortedListMerge(n1 *NodeI, n2 *NodeI) *NodeI {

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
	var link2 *piscine.NodeI

	link = listPushBack(link, 3)
	link = listPushBack(link, 5)
	link = listPushBack(link, 7)

	link2 = listPushBack(link2, -2)
	link2 = listPushBack(link2, 9)

	PrintList(piscine.SortedListMerge(link2, link))
}

Output : 
-2 -> 3 -> 5 -> 7 -> 9 -> <nil>
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
    NodeI* SortedListMerge(NodeI* n1,NodeI* n2)
    {
        if (n1 == nullptr)
            return nullptr;

        std::vector<NodeI*> vec {};
        NodeI* node {n1};
        while (node != nullptr)
        {
            vec.push_back(node);
            node = node->Next;
        }

        node = {n2};
        while (node != nullptr)
        {
            vec.push_back(node);
            node = node->Next;
        }
        

        bubbleSortNodes(vec);
        
        updateNodeNextPtrs(vec);
        
        n1 = vec[0];

        return n1;
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
	piscine::NodeI* link2 {nullptr};

	link = piscine::listPushBack(link, 3);
	link = piscine::listPushBack(link, 5);
	link = piscine::listPushBack(link, 7);

	link2 = piscine::listPushBack(link2, -2);
	link2 = piscine::listPushBack(link2, 9);

	piscine::PrintList(piscine::SortedListMerge(link2, link));

    return EXIT_SUCCESS;
}