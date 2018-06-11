Logan Thomas
Assignment 5
5/22/2018

To Run the program, first you must install the haskell compiler. This can be
found at https://www.haskell.org/platform/

To run the file, you must first start the haskell compiler.
In the terminal, type:

	$ ghci

Next you will need to load the file to use its functions
To do this, in ghci, type:

	$ :load Assignment5.hs

Once you have loaded the haskell file, you can use the functions contained within it.
If any changes are made to Assignment5.hs while it is already loaded into ghci, you
must reload it.
In the terminal type:
	
	$ :reload

Functions:
	max3:
		Inputs:		3 Ints
		Outputs:	A tuple of 3 Ints
		Description:
			Takes the 3 Int inputs and sorts them into a tuple.
		Ex:
			max3 6 3 4
			>> (3, 4, 6)
		
	isSorted:
		Inputs:		A list of integers
		Outputs:	Boolean
		Description:
			Tells the user it the list is sorted or not
		Ex:
			isSorted [1, 2, 3, 4, 5]
			>> True
			isSorted [1, 2, 4, 3, 5]
			>> False
		
	pyths:
		Inputs:		Int
		Outputs:	List of tuples of 3 Ints
		Description:
			Lists all Pythagorean triples up to the input x.
		Ex:
			pyths 10
			>> [(3, 4, 5), (4, 3, 5), (6, 8, 10), (8, 6, 10)]
		
	sqrAll1:
		Inputs:		List of Ints
		Outputs:	List of Ints
		Description:
			Creates a new list of ints containing the squares of the input list
		Ex:
			sqrAll1 [1, 2, 3]
			>> [1, 4, 9]
		
	addPairs:
		Inputs:		2 Lists of Ints
		Outputs:	List of Ints
		Description:
			Creates a list which contains all combinations of sums of even numbers from list 1 and
			all odd numbers from list 2
		ex:
			addPairs [2, 5, 8] [5, 1, 2]
			>> [7, 3, 13, 9]