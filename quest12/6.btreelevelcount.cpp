#include <iostream>

/*
Write a function BTreeLevelCount that returns the number of levels in a binary tree (i.e., the height of the tree).

Expected function
func BTreeLevelCount(root *TreeNode) int {

}

Usage : 
	root := &piscine.TreeNode{Data: "4"}
	piscine.BTreeInsertData(root, "1")
	piscine.BTreeInsertData(root, "7")
	piscine.BTreeInsertData(root, "5")
	fmt.Println(piscine.BTreeLevelCount(root))

Output :
3
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

    // BTreeLevelCount(root *TreeNode) int
    int BTreeLevelCount(TreeNode* root)
    {
         // Base Case: If the tree is empty, return 0
        if (root == nullptr)
            return 0;

        // Recursively find the height of left and right subtrees
        int leftHeight {BTreeLevelCount(root->Left)};
        int rightHeight {BTreeLevelCount(root->Right)};

        // Height of current node is 1 + the maximum of its subtrees
        return 1 + std::max(leftHeight,rightHeight);
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
    std::cout << piscine::BTreeLevelCount(Root) << "\n";

    return EXIT_SUCCESS;
}