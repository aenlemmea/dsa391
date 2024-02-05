/*
				[35  55]
				/   |   \
			  /     |     \  
		[25 32]  [38 41]   [70 83]

		A 3 Way Tree		   ~ M Way Tree
		2 Keys, MAX 3 children ~ M - 1 keys, M Children


		M -> degree of the tree.

		M way Search Tree: Every sub tree is also an M way search tree. 
		Memory Model: [Pointer Key Pointer]
		
		Subtree nodes that hold keys are all less than the parent Key value
		See the video for better clarity regarding what this means @ 6:35: https://youtu.be/WBfmEprDUWs&t=395

		Keys are stored in ascending order.


		================================================

		B Tree ~ M Way Tree but with Balance! 
		We balance so that leafs can remain at a same level => Tree becomes denser => height dependency is shortened to logarithmic time
			
			- All leaf nodes at same level
			- Number of keys:
				- Root = Internal Nodes = External Nodes = (M - 1) MAX
				- Root = 1 ; Internal Nodes = External Nodes =  (ceil(M/2) - 1)) MIN
			
			- Number of children:
				- Leaf cannot have children so no restrictions!
				- Root = Internal Nodes = (M) MAX
				- Root = 2 (if not leaf) ; Internal Nodes = (ceil(M/2)) MIN
		
		Insertion: https://youtu.be/b_cqFnjbL7Y
		Deletion: https://youtu.be/jeZag9ZorPM
*/