# 0x1D. C - Binary trees

## Overview

A binary tree is a type of data structure that consists of nodes arranged in a hierarchical tree-like structure. Each node in a binary tree has at most two children, referred to as the left child and the right child. The node at the top of the tree is called the root, and it has no parent.

## Terms and Definitions

* **Root:** The root is the node at the top of the tree.
* **Parent:** A node that has children is called a parent.
* **Child:** A node directly connected to another node when moving away from the Root is called a child.
* **Leaves/Leaf:** A leaves/leaf is a node that has no children.
* **Height:** The height of a tree is the number of edges from the root to the furthest leaf.
* **Depth:** The depth of a node is the number of edges from the tree's root node to the node.
* **Size:** The size of a tree is the total number of nodes in the tree.
* **Complete:** A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.
* **Perfect:** A perfect binary tree is a type of binary tree in which every internal node has exactly two child nodes and all the leaf nodes are at the same level.
* **Balanced:** A balanced binary tree is a tree such that the heights of the two subtrees of any node never differ by more than one.
* **Full:** A full binary tree is a tree in which every node other than the leaves has two children.
* **Sibling:** A sibling is a node that has the same parent.
* **Uncle:** An uncle is a sibling of a parent.
* **Pre-order:** Pre-order traversal is to visit the root first. Then traverse the left subtree. Finally, traverse the right subtree.
* **In-order:** In-order traversal is to traverse the left subtree first. Then visit the root. Finally, traverse the right subtree.
* **Post-order:** Post-order traversal is to traverse the left subtree first. Then traverse the right subtree. Finally, visit the root.

## Data Structures

### Basic Binary Tree
```
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
```

### Binary Search Tree
```
typedef struct binary_tree_s bst_t;
```

### AVL Tree
```
typedef struct binary_tree_s avl_t;
```

### Max Binary Heap
```
typedef struct binary_tree_s heap_t;
```

## Author

* **Girmachew Zewdie** - [Github](github.com/girmesh03)