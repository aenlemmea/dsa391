// AVL Tree = BST + Balanced Factor.
// Balance Factor legit if it is {-1, 0, +1}. Balance Factor = left subtree levels - right subtree levels. 
// Adelson Velski Landis

// To create AVL Tree:
/*
	First: Kake rotate korbo? Je node ke add korechi sekhan theke hath bo, joto khon emon kono node pacchi na jar balance factor is not {-1, 0, 1}.
			Jake pabo with illegal balance factor, take rotate korte hobey
	Second: Ki rotation lagabo? Je node take rotate korbo decide korechi, sekhan theke 2 steps only je node ta add korechi sedike hete jabar chesta korbo,
			with noting if the two steps are LL, RR, LR or RL. Then put arrow according to the decided two directions and rotate accordingly the node that we decided to rotate. 
			In case of RL or LR, we also have to rotate the node at the end of the second step.
	
	Rotation arrow directions: https://imgur.com/a/GmgxAHT
*/


/*
Deletion Rotations:
	
	// https://www.youtube.com/watch?v=5hE2cZLTtJg
	Case 1: Deletion from ~~<<right subtree>>~~ -> Apply R rotations
				
				R0 Rotation ~ LL Rotation if BF(node) = +2 && BF(node->left child) = 0
				R1 Rotation ~ LL Rotation if BF(node) = +2 and BF(node->left child) =  +1
				R-1 Rotation ~ LR Rotation if BF(node) = +2 and BF(node->left child) = -1
	
	Case 1: Deletion from ~~<<left subtree>>~~ -> Apply L rotations

				L0 Rotation ~ RR Rotation if BF(node) = -2 && BF(node->right child) = 0
		**		L1 Rotation ~ RL Rotation if BF(node) = -2 and BF(node->right child) =  +1
				L-1 Rotation ~ RR Rotation if BF(node) = -2 and BF(node->right child) = -1
*/