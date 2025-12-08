// Initial Nodes (in order of insertion): 10, 20, 30, 40, 50
// New Node to Insert: 15
// Required Operation: Show the resulting tree after a manual LEFT ROTATION on the root.

// The sequential insertion of 10, 20, 30, 40, 50 forces the AVL tree to perform rotations.
// After the initial balancing (Left Rotations for the RR cases), the starting tree is:
//
// Root: 20 (Height 3)
// |--- Left: 10
// |--- Right: 40
//      |--- Left: 30
//      |--- Right: 50
//
// 
// 
// We insert 15 using the BST rules:
// - Start at Root (20): 15 < 20, go Left.
// - Move to Node 10: 15 > 10, go Right.
// - Insertion: 15 is placed as the right child of 10.
//
// Balance Check After Insertion:
// - Node 10's Balance Factor (LH - RH) becomes 0 - 1 = -1. (Balanced)
// - Node 20's Balance Factor (LH - RH) becomes 2 - 2 = 0. (Balanced)
// Conclusion: The tree is already balanced; no automatic rotation is triggered.
//
//
// 
// The longest path from the root (20) to any leaf (e.g., 20 -> 40 -> 50) contains 3 nodes.
//
// The height of the AVL tree after inserting 15 is 3.
//
//
// 4. Resulting AVL Tree After Manual Left Rotation on Root (20)
// 
// The task requires we manually perform a Left Rotation on the root (20): 
//
// Pointers in the Rotation:
// - Pivot (X): 20
// - Pivot's Right Child (Y): 40
// - T2 (Y's Left Child): 30
//
// Rotation Outcome:
// - Node 40 becomes the new root.
// - Node 20 drops to become 40's left child.
// - Node 30 moves to become 20's right child.
// - The 10 -> 15 subtree remains attached to 20's left child pointer.
//
// Final Structure:
// Root: 40
// |--- Left: 20
// |    |--- Left: 10
// |    |    |--- Right: 15
// |    |--- Right: 30
// |--- Right: 50
//
// Final Keys in Inorder Traversal: 10, 15, 20, 30, 40, 50.
//
//
