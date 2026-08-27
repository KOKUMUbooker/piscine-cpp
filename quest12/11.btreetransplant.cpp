#include <iostream>

/*
Write a function BTreeTransplant that replaces a subtree in a binary search tree (BST).
The function must replace the subtree rooted at node with the subtree rooted at rplc, within the tree given by root.
The resulting tree must remain properly linked, preserving BST structure.

Expected function
func BTreeTransplant(root, node, rplc *TreeNode) *TreeNode {

}
Usage : 
	root := &piscine.TreeNode{Data: "4"}
	piscine.BTreeInsertData(root, "1")
	piscine.BTreeInsertData(root, "7")
	piscine.BTreeInsertData(root, "5")
	node := piscine.BTreeSearchItem(root, "1")
	rplc := &piscine.TreeNode{Data: "3"}
	root = piscine.BTreeTransplant(root, node, rplc)
	piscine.BTreeApplyInorder(root, fmt.Println)
Output :
3
4
5
7
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

    TreeNode* BTreeTransplant(
        TreeNode* root,
        TreeNode* node,
        TreeNode* rplc
    )
    {
        // node is the root of the entire tree
        if (node->Parent == nullptr)
        {
            root = rplc;
        }
        // node is the left child of its parent
        else if (node == node->Parent->Left)
        {
            node->Parent->Left = rplc;
        }
        // node is the right child of its parent
        else
        {
            node->Parent->Right = rplc;
        }

        // Connect replacement to node's old parent
        if (rplc != nullptr)
            rplc->Parent = node->Parent;

        return root;
    }

    TreeNode* BTreeSearchItem(TreeNode* root, std::string elem)
    {
        TreeNode* res {nullptr};
        TreeNode* node {root};

        while (node != nullptr)
        {
            if (node->Data == elem)
            {
                res = node;
                break;
            }
            else if (elem > node->Data)
            {
                node = node->Right;
            }
            else
            {
                node = node->Left;
            }
        }
        
        return res;
    }

    void BTreeApplyInorder(TreeNode* root, void (*func)(std::string data))
    {
        if (root == nullptr)
            return;
        BTreeApplyInorder(root->Left,func);
        func(root->Data);
        BTreeApplyInorder(root->Right,func);
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

    piscine::TreeNode* node { piscine::BTreeSearchItem(Root, "1")};
	piscine::TreeNode* rplc {new piscine::TreeNode{std::string("3")}};
	Root = piscine::BTreeTransplant(Root, node, rplc);
    
    auto PrintFn = [](std::string data)
    {
        std::cout << data << "\n";
    };
	piscine::BTreeApplyInorder(Root, PrintFn);

    return EXIT_SUCCESS;
}