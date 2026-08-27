#include <iostream>
#include <string>
#include <queue>

/*
Write a function, BTreeApplyByLevel, that applies the function given by f, to each node of the tree given by root.

Expected function
func BTreeApplyByLevel(root *TreeNode, f func(...interface{}) (int, error))  {

}

Usage :
	root := &piscine.TreeNode{Data: "4"}
	piscine.BTreeInsertData(root, "1")
	piscine.BTreeInsertData(root, "7")
	piscine.BTreeInsertData(root, "5")
	piscine.BTreeApplyByLevel(root, fmt.Println)
Output : 
4
1
7
5
*/

namespace piscine
{
    class TreeNode
    {
    public:
        TreeNode* Left{nullptr};
        TreeNode* Right{nullptr};
        TreeNode* Parent{nullptr};
        std::string Data {};

        TreeNode(std::string data,TreeNode* left=nullptr,TreeNode* right=nullptr,TreeNode* parent=nullptr)
            : Data {data}, Left {left}, Right {right}, Parent {parent}
        {}
    };

    void BTreeApplyByLevel(
        TreeNode* root,
        void (*f)(TreeNode*)
    )
    {
        if (root == nullptr)
            return;

        std::queue<TreeNode*> queue;

        queue.push(root);

        while (!queue.empty())
        {
            TreeNode* current {queue.front()};
            queue.pop();

            f(current);

            if (current->Left != nullptr)
                queue.push(current->Left);

            if (current->Right != nullptr)
                queue.push(current->Right);
        }
    }

    void BTreeInsertData(TreeNode* root,std::string data)
    {
        TreeNode* node {new TreeNode {data}};

        if (root == nullptr)
            root = node;
        else 
        {
            TreeNode* current {root};
            TreeNode* trailingParent {nullptr};
            while (current != nullptr)
            {
                trailingParent = current;
                if (data > current->Data)
                    current = current->Right;
                else 
                    current = current->Left;
            }

            node->Parent = trailingParent;
            if (data > trailingParent->Data)
                trailingParent->Right = node;
            else
                trailingParent->Left = node;
        }
    }
}

int main()
{
	piscine::TreeNode* Root {new piscine::TreeNode {std::string("4")}};
    piscine::BTreeInsertData(Root,std::string("1"));
    piscine::BTreeInsertData(Root,std::string("7"));
    piscine::BTreeInsertData(Root,std::string("5"));

    auto PrintFn = [](piscine::TreeNode* node)
    {
        std::cout << node->Data << "\n";
    };

    piscine::BTreeApplyByLevel(Root, PrintFn);

    return EXIT_SUCCESS;
}