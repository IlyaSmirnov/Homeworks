dif_list :: (Num a) => [a] -> [a]
dif_list (z : zs) = reverse ( tail ( foldl (\(x : xs) y -> (y : (x + y) : xs)) [z] zs))

fst_pos :: (Eq a, Ord a, Num a) => [a] -> Int
fst_pos (x : y : xs) = snd ( head ( filter (\x -> ((fst x) == max_sum)) (zip sums [1..]))) where
	sums = dif_list (x : y : xs)	
	max_sum = maximum sums