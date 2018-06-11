-- 1a
data BTree a = Empty | Node a (BTree a) (BTree a) deriving (Show)

-- 1b
toList :: BTree a -> [a]
toList Empty = []
toList (Node x t1 t2) = (toList t1) ++ [x] ++ (toList t2)

-- 1c
insert :: Ord a => a -> BTree a -> BTree a
insert x Empty = (Node x Empty Empty)
insert x (Node y t1 t2)
    | x < y     = (Node y (insert x t1) t2)
    | x > y     = (Node y t1 (insert x t2))
    | otherwise = (Node y t1 t2)

-- 1d
fromList :: Ord a => [a] -> BTree a
fromList xs = foldr insert Empty xs
-- fromList xs = foldr insert Empty (reverse xs)

-- 1e
sort :: Ord a => BTree a -> BTree a
sort = fromList . toList

-- 2
lookupOrd :: Ord a => a -> [(a, b)] -> Maybe b
lookupOrd y (x:xs)
    | y == (fst x)  = Just (snd x)
    | y < (fst x)   = Nothing
    | otherwise     = lookupOrd y xs
