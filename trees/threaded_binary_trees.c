// Key Idea: Don't use recursion so stack is at rest. Make in-order traversal faster.

// Main implementation idea: All te right child pointers that are normally NULL (escpecially in leaf nodes) to be set to the in-order successor. This is for singly threaded binary tree.
// In a doubly thread binary tree: The left child pointers (especially of the leaf nodes) are set to the in-order predecessor and the right child pointers are set to the in-order successor.

// We do this so that for in-order traversal we can simply iterate on the right pointers (singly threaded) and derive the in-order traversal.

