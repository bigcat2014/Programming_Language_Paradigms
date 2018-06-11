Logan Thomas
Assignment 7
6/10/2018

To Run the program, first you must install the haskell compiler. This can be
found at https://www.haskell.org/platform/

To run the file, you must first start the haskell compiler.
In the terminal, type:

	$ ghci

Next you will need to load the file to use its functions
To do this, in ghci, type:

	$ :load Assignment8.hs

Once you have loaded the haskell file, you can use the functions contained within it.
If any changes are made to Assignment8.hs while it is already loaded into ghci, you
must reload it.
In the terminal type:
	
	$ :reload

Items:
	BTree:
		A data type representing a binary tree. This type has a value associated with it, as well as a left subtree and a right subtree.
		
Functions:
	toList:
		Inputs:		BTree
		Outputs:	List
		Description:
			Takes a binary tree and outputs its nodes as a list, traversed inorder
		Ex:
			assuming tree is a binary tree which looks like:
                    3
                  /   \
                 1     7
                / \   / \
               E   E E   9
                        / \
                       E   E
			toList tree
			>> [1, 3, 7, 9]
		
	insert:
		Inputs:		Value, BTree
		Outputs:	BTree
		Description:
			Takes a value to be stored in a tree and a tree to insert the value into, inserts the value as a new node in the tree
		Ex:
			insert 5 "tree from first part"
			>> a tree which looks like:
                    3
                  /   \
                 1     7
                / \   / \
               E   E 5   9
                        / \
                       E   E
		
	fromList:
		Inputs:		list of node values
		Outputs:	BTree
		Description:
			Creates a new BTree from the values in the list
		Ex:
			fromList [9, 7, 3, 1]
			>> "tree from frist part"
		
	sort:
		Inputs:		BTree
		Outputs:	BTree
		Description:
			Takes the given BTree and sorts it into a new BTree
		Ex:
			assuming tree is a tree which looks like:
                   8
                  / \
                 2   E
                / \
               E   7
                  / \
                 4   E
                / \
               3   E
              / \
             E   E

			sort tree
			>> a tree which looks like
                    8
                   / \
                  7   E
                 / \
                4   E
               / \
              3   E
             / \
            2   E
           / \
          E   E

	lookupOrd:
		Inputs:		A value a and a list of tuples [(a, b)]
		Outputs:	Either a value b or Nothing
		Description:
			Takes a value a and looks through the list, checking if the first value is in the tuple, if so it returns the second value of the tuple, otherwise it returns Nothing.

		Ex:
			lookupOrd 4 (zip [1..] [2..])
			>> 5

			lookupOrd 4 (zip [1, 3..] [2..])
			>> Nothing