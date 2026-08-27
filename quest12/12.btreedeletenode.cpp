#include <iostream>

/*
Write a function BTreeDeleteNode that deletes a given node from the tree given by root.
The resulting tree must still respect binary search tree (BST) rules after deletion.

Expected function
func BTreeDeleteNode(root, node *TreeNode) *TreeNode {

}
Usage : 
	root := &piscine.TreeNode{Data: "4"}
	piscine.BTreeInsertData(root, "1")
	piscine.BTreeInsertData(root, "7")
	piscine.BTreeInsertData(root, "5")
	node := piscine.BTreeSearchItem(root, "4")
	fmt.Println("Before delete:")
	piscine.BTreeApplyInorder(root, fmt.Println)
	root = piscine.BTreeDeleteNode(root, node)
	fmt.Println("After delete:")
	piscine.BTreeApplyInorder(root, fmt.Println)
Output : 
Before delete:
1
4
5
7
After delete:
1
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

    TreeNode* BTreeMin(TreeNode* root)
    {
        if (root == nullptr)
            return nullptr;

        TreeNode* current {root};

        while (current->Left != nullptr)
            current = current->Left;

        return current;
    }

    TreeNode* BTreeDeleteNode(TreeNode* root, TreeNode* node)
    {
        // Case 1:
        // Node has no left child.
        if (node->Left == nullptr)
        {
            root = BTreeTransplant(root, node, node->Right);
        }

        // Case 2:
        // Node has no right child.
        else if (node->Right == nullptr)
        {
            root = BTreeTransplant(root, node, node->Left);
        }

        // Case 3:
        // Node has two children.
        else
        {
            TreeNode* successor = BTreeMin(node->Right);

            // Successor is not the direct right child.
            if (successor->Parent != node)
            {
                root = BTreeTransplant(
                    root,
                    successor,
                    successor->Right
                );

                successor->Right = node->Right;
                successor->Right->Parent = successor;
            }

            root = BTreeTransplant(root, node, successor);

            successor->Left = node->Left;
            successor->Left->Parent = successor;
        }

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

    auto PrintFn = [](std::string data)
    {
        std::cout << data << "\n";
    };

    piscine::TreeNode* node { piscine::BTreeSearchItem(Root, "4")};
    std::cout << "Before delete:\n"; 
	piscine::BTreeApplyInorder(Root, PrintFn);
    Root = piscine::BTreeDeleteNode(Root, node);

    std::cout << "After delete:\n"; 
	piscine::BTreeApplyInorder(Root, PrintFn);
	piscine::TreeNode* rplc {new piscine::TreeNode{std::string("3")}};

    return EXIT_SUCCESS;
}