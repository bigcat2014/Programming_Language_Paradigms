-- 1
max3 :: Int -> Int -> Int -> (Int, Int, Int)
max3 x y z =
    if (x > y) then
        if(x > z) then
            if (y > z) then
                (z, y, x)
            else
                (y, z, x)
        else
            (y, x, z)
    else if (x > z) then
        (z, x, y)
    else if (y > z) then
        (x, z, y)
    else
        (x, y, z)

-- 2
isSorted :: Ord a => [a] -> Bool
isSorted [] = True
isSorted [x] = True
isSorted (x:xs)
    | x <= (head xs)    = isSorted xs
    | otherwise         = False

-- 3
pyths :: Int -> [(Int, Int, Int)]
pyths x = [(a, b, c) | a <- [1..x], b <- [1..x], c <- [1..x], (a^2) + (b^2) == (c^2)]

-- 4
sqrAll1 :: [Int] -> [Int]
sqrAll1 xs = [x^2 | x <- xs]

-- 5
addPairs :: [Int] -> [Int] -> [Int]
addPairs xs ys = [x+y | x <- xs, y <- ys, (x `mod` 2) == 0, (y `mod` 2) == 1]