#include <iostream>

/*
Write a function that applies a given function f to each element in the tree using a preorder walk.

Expected function
func BTreeApplyPreorder(root *TreeNode, f func(...interface{}) (int, error)) {

}

Usage : 
	root := &piscine.TreeNode{Data: "4"}
	piscine.BTreeInsertData(root, "1")
	piscine.BTreeInsertData(root, "7")
	piscine.BTreeInsertData(root, "5")
	piscine.BTreeApplyPreorder(root, fmt.Println)

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

    void BTreeApplyPreorder(TreeNode* root, void (*func)(std::string data))
    {
        if (root == nullptr)
            return;
        func(root->Data);
        BTreeApplyPreorder(root->Left,func);
        BTreeApplyPreorder(root->Right,func);
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
    piscine::BTreeApplyPreorder(Root, [](std::string data){
        std::cout << data << "\n" ;
    });

    return EXIT_SUCCESS;
}