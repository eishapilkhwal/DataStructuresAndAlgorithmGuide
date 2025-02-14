# Tree Data Structure

A **Tree** is a hierarchical data structure that is widely used in various applications, such as the **Admin System of an Organization**.

---

## Key Concepts

### 1. **Basic Terminologies**
- **Root Node**: The topmost node of the tree (e.g., `1` in the example below).
- **Leaf Node**: Nodes with no children (e.g., `4`, `5`, `6`).
- **Parent Node**: A node that has one or more children (e.g., `2` is the parent of `4` and `5`).
- **Child Node**: Nodes directly connected and below a parent node (e.g., `4` and `5` are children of `2`).
- **Siblings**: Nodes that share the same parent (e.g., `4` and `5` are siblings).
- **Ancestor**: Any node that lies on the path from the root to a given node (e.g., `1` and `2` are ancestors of `4`).

### 2. **Binary Tree**
- A tree where each node has **at most two children**: **Left Child** and **Right Child**.
- Example of a binary tree:

     1                           - Level 1, Depth 1
    / \
   2   3                         - Level 2, Depth 2
  / \    \ 
 4   5    6                      - Level 3, Depth 3

 
### 3. **Levels and Subtrees**
- **Levels**: Nodes that share the same depth from the root (e.g., `4`, `5`, and `6` are at **Level 3**).
- **Subtree**: A tree consisting of a node and all its descendants (e.g., subtree of `2` includes `4` and `5`).

---

## Examples

1. **Children of `2`**: `4`, `5`
2. **Number of Leaves**: `3` (Nodes: `4`, `5`, `6`)
3. **Parent of `3`**: `1`
4. **Level of `5`**: `3`
5. **Subtree of `2`**: Includes `4` and `5`
6. **Ancestor of `4`**: `1`, `2`

---

## Traversal Techniques

### 1. **Depth-First Search (DFS)**
   - Traverses as deep as possible along each branch before backtracking.
   - Types:
     - **Preorder Traversal**: Root → Left → Right  : O(n)
     - **Inorder Traversal**: Left → Root → Right  : O(n)
     - **Postorder Traversal**: Left → Right → Root  : O(n)

### 2. **Breadth-First Search (BFS) / Level Order Traversal**  : O(n)
   - Visits nodes level by level from top to bottom.
   - **Uses a Queue** to keep track of nodes to be visited.

---

## Traversal Example

For the Binary Tree:

     1                           
    / \
   2   3                         
  / \    \ 
 4   5    6  


- **Preorder Traversal**: `1, 2, 4, 5, 3, 6`
- **Inorder Traversal**: `4, 2, 5, 1, 3, 6`
- **Postorder Traversal**: `4, 5, 2, 6, 3, 1`
- **Level Order Traversal (BFS)**: `1, 2, 3, 4, 5, 6`

---

## Time Complexity
- Traversal: **O(n)**, where `n` is the number of nodes in the tree.
- Space Complexity for BFS: **O(w)**, where `w` is the maximum width of the tree (the maximum number of nodes at any level).

---

## Use Case

### **Admin System of an Organization**
- The **root node** represents the top-level admin.
- **Child nodes** represent departments or employees.
- **Leaf nodes** represent individual employees or resources without subordinates.


## Related Problems
- [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/description/)
- [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/description/)
- [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/description/)


