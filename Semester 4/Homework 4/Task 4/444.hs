checkUnique ::  (Eq a) => [a] -> Bool
checkUnique [] = True
checkUnique(x:xs) = (not( elem x xs)) && (checkUnique xs)