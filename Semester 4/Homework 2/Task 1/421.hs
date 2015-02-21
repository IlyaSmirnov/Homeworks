reverseListHelper :: [a] -> [a] -> [a]
reverseListHelper xs [] = xs 
reverseListHelper xs (y:ys) = reverseListHelper (y:xs) ys

reverseList :: [a] -> [a]
reverseList xs = reverseListHelper [] xs
