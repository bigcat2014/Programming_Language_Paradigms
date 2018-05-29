--
--  Logan Thomas
--  Programming Language Paradigms
--  Assignment 6
--

-- 1
merge :: [Int] -> [Int] -> [Int]
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys)
    | x > y     = [y] ++ (merge (x:xs) ys)
    | otherwise = [x] ++ (merge xs (y:ys))

-- 2
gcdea :: Int -> Int -> Int
gcdea x y
    | x == y    = x
    | x < y     = gcdea (y - x) x
    | otherwise = gcdea (x - y) y

-- 3
qsort :: Ord a => [a] -> [a]
qsort [] = []
qsort (x:xs) =
    let smallerSorted = qsort [a | a <- xs, a <= x]
        biggerSorted = qsort [a | a <- xs, a > x]
    in smallerSorted ++ [x] ++ biggerSorted

-- 4
qsort' :: Ord a => [a] -> [a]
qsort' [] = []
qsort' (x:xs) = 
    let pSmaller = (<= x)
        pBigger = (> x)
        smallerSorted = qsort' (filter pSmaller xs)
        biggerSorted = qsort' (filter pBigger xs)
    in smallerSorted ++ [x] ++ biggerSorted

-- 5
sumSquares' :: Integer -> Integer
sumSquares' n = foldr (+) 0 (map (^2) [1..n])