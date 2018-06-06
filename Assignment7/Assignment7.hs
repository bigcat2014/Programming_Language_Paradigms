--
--  Logan Thomas
--  Programming Language Paradigms
--  Assignment 7
--

-- 1
dividers :: Int -> [Int] -> [Int]
dividers n ls = filter fn ls where
    fn x = (n `mod` x) == 0

-- 2
replace :: Int -> Int -> [Int] -> [Int]
replace m n ls = map fn ls where
    fn x
        | x == m    = n
        | otherwise = x

-- 3
sumsq :: Int -> Int
sumsq n = foldr (+) 0 ([x^2 | x <- [1..n]])

-- 4
--notWhiteSpace :: Char -> Bool
notWhiteSpace = \x -> not (elem x [' ', '\t', '\n'])

-- 5
total :: (Integer -> Integer) -> (Integer -> Integer)
total f = \n -> ((foldr (+) 0) . (map f)) [1..n]