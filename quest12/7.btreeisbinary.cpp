#include <iostream>
#include <string>

/*
Write a function BTreeIsBinary that checks whether a given binary tree satisfies the properties of a binary search tree (BST).
The function must return true if the tree respects BST rules.
    A binary search tree follows these rules:
    All values in the left subtree are strictly smaller than the node's value.
    All values in the right subtree are strictly greater than the node's value.
    Both left and right subtrees must also be valid BSTs.

Expected function
func BTreeIsBinary(root *TreeNode) bool {

}

Usage : 
	root := &piscine.TreeNode{Data: "4"}
	piscine.BTreeInsertData(root, "1")
	piscine.BTreeInsertData(root, "7")
	piscine.BTreeInsertData(root, "5")
	fmt.Println(piscine.BTreeIsBinary(root))
Output : 

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

    bool BTreeIsBinaryHelper(
        TreeNode* node,
        const std::string* min,
        const std::string* max
    )
    {
        if (node == nullptr)
            return true;

        if (min != nullptr && node->Data <= *min)
            return false;

        if (max != nullptr && node->Data >= *max)
            return false;

        return BTreeIsBinaryHelper(node->Left, min, &node->Data)
            && BTreeIsBinaryHelper(node->Right, &node->Data, max);
    }

    bool BTreeIsBinary(TreeNode* root)
    {
        return BTreeIsBinaryHelper(root, nullptr, nullptr);
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

    std::cout << std::boolalpha;
    std::cout << piscine::BTreeIsBinary(Root) << "\n";

    return EXIT_SUCCESS;
}