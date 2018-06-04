Logan Thomas
Assignment 7
6/4/2018

To Run the program, first you must install the haskell compiler. This can be
found at https://www.haskell.org/platform/

To run the file, you must first start the haskell compiler.
In the terminal, type:

	$ ghci

Next you will need to load the file to use its functions
To do this, in ghci, type:

	$ :load Assignment7.hs

Once you have loaded the haskell file, you can use the functions contained within it.
If any changes are made to Assignment7.hs while it is already loaded into ghci, you
must reload it.
In the terminal type:
	
	$ :reload

Functions:
	dividers:
		Inputs:		Int and Int list
		Outputs:	Int list
		Description:
			Prints a list of elements from the Int list ls that neatly divide the Int n provided
		Ex:
			dividers 36 [1..18]
			>> [1,2,3,4,6,9,12,18]
		
	replace:
		Inputs:		2 Ints and an Int list
		Outputs:	Int List
		Description:
			Takes 2 Ints, m and n, and an Int list, ls, and replaces
			every occurance of m in ls with n and returns this
			updated list
		Ex:
			replace 5 2 [2, 5, 5, 3, 5, 6]
			>> [2, 2, 2, 3, 2, 6]
		
	sumsq:
		Inputs:		Int
		Outputs:	Int
		Description:
			Takes an Int n and outputs the sum of squares from 1 to n
		Ex:
			sumsq 10
			>> 385
		
	notWhiteSpace:
		Inputs:		Char
		Outputs:	Boolean
		Description:
			Returns False or True depending on if Char x is whitespace or not, respectively. Whitespace defined as either ' ', '\t' or '\n'
		Ex:
			notWhiteSpace 'a'
			>> True

			notWhiteSpace '\n'
			>> False
		
	total:
		Inputs:		(Integer -> Integer)
		Outputs:	(Integer -> Integer)
		Description:
			A function that accepts a function f and returns a function that accepts 1 Integer n and returns an Integer as the sum of the function f from f(1) to f(n).
			f(1) + f(2) + ... + f(n)
		ex:
			total (^2) 10
			>> 385