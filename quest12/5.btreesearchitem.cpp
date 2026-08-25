#include <iostream>
#include <string>

/*
Write a function that returns the TreeNode whose Data field is equal to elem. If the element is not found in the tree, the function must return nil.

Expected function
func BTreeSearchItem(root *TreeNode, elem string) *TreeNode {

}

Usage : 
    root := &piscine.TreeNode{Data: "4"}
	piscine.BTreeInsertData(root, "1")
	piscine.BTreeInsertData(root, "7")
	piscine.BTreeInsertData(root, "5")
	selected := piscine.BTreeSearchItem(root, "7")
	fmt.Print("Item selected -> ")
	if selected != nil {
		fmt.Println(selected.Data)
	} else {
		fmt.Println("nil")
	}

	fmt.Print("Parent of selected item -> ")
	if selected.Parent != nil {
		fmt.Println(selected.Parent.Data)
	} else {
		fmt.Println("nil")
	}

	fmt.Print("Left child of selected item -> ")
	if selected.Left != nil {
		fmt.Println(selected.Left.Data)
	} else {
		fmt.Println("nil")
	}

	fmt.Print("Right child of selected item -> ")
	if selected.Right != nil {
		fmt.Println(selected.Right.Data)
	} else {
		fmt.Println("nil")
	}

Outout : 
Item selected -> 7
Parent of selected item -> 4
Left child of selected item -> 5
Right child of selected item -> nil
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

    // func BTreeSearchItem(root *TreeNode, elem string) *TreeNode
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
    piscine::TreeNode* selected = piscine::BTreeSearchItem(Root, "7");
    std::cout << "Item selected -> ";
	if (selected != nullptr) {
		std::cout << selected->Data << "\n";
	} else {
		std::cout << "nil" << "\n";
	}

	std::cout << "Parent of selected item -> ";
	if (selected->Parent != nullptr) {
		std::cout << selected->Parent->Data << "\n";
	} else {
		std::cout << "nil" << "\n";
	}

	std::cout << "Left child of selected item -> ";
	if (selected->Left != nullptr) {
		std::cout << selected->Left->Data << "\n";
	} else {
		std::cout << "nil" << "\n";
	}

	std::cout << "Right child of selected item -> ";
	if (selected->Right != nullptr) {
		std::cout << selected->Right->Data << "\n";
	} else {
		std::cout << "nil" << "\n";
	}

    return EXIT_SUCCESS;
}