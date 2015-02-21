position :: Integer -> [Integer] -> Integer 
position _ [] = 1
position n (x : xs) 
        | (x == n) = 1
	| (xs == []) = 2
        | otherwise = 1 + position n xs