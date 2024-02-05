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