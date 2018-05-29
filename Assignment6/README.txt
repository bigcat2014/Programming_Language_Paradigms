Logan Thomas
Assignment 6
5/29/2018

To Run the program, first you must install the haskell compiler. This can be
found at https://www.haskell.org/platform/

To run the file, you must first start the haskell compiler.
In the terminal, type:

	$ ghci

Next you will need to load the file to use its functions
To do this, in ghci, type:

	$ :load Assignment6.hs

Once you have loaded the haskell file, you can use the functions contained within it.
If any changes are made to Assignment6.hs while it is already loaded into ghci, you
must reload it.
In the terminal type:
	
	$ :reload

Functions:
	merge:
		Inputs:		2 Int lists
		Outputs:	1 Int list
		Description:
			Mergesorts the 2 input arrays recursively
		Ex:
			max3 [1, 2, 6] [3, 7, 8]
			>> [1, 2, 3, 6, 7, 8]
		
	gcdea:
		Inputs:		2 Ints
		Outputs:	1 Int
		Description:
			Recursively calculates the greatest common divisor of the two inputs
		Ex:
			gcdea 195 208
			>> 13
		
	qsort:
		Inputs:		List of Ord values
		Outputs:	List of Ord values
		Description:
			Performs quicksort recursively on the input list
		Ex:
			qsort [1, 4, 3, 5, 6, 2, 7, 8]
			>> [1, 2, 3, 4, 5, 6, 7, 8]
		
	qsort':
		Inputs:		List of Ord values
		Outputs:	List of Ord values
		Description:
			Performs quicksort recursively on the input list using the filter function
		Ex:
			qsort' [1, 4, 3, 5, 6, 2, 7, 8]
			>> [1, 2, 3, 4, 5, 6, 7, 8]
		
	sumSquares':
		Inputs:		Integer
		Outputs:	Integer
		Description:
			Calculates the sum of the squares of all values from 1 to n using the foldr and map functions
		ex:
			sumSquares' 10
			>> 385