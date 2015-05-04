list123 :: Int -> [[Int]]
list123 = (flip (list123Helper) [1, 2, 3])

list123Helper:: Int -> [a] -> [[a]]
list123Helper 0 _ = [[]]
list123Helper _[] = []
list123Helper n l = [(x : xs) | x <- l, xs <- (list123Helper (n - 1) l)]