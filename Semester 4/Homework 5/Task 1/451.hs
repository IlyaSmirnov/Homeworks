expansion :: Int -> [[Int]]
expansion num = expansion' num num where
	expansion' 0 _ = [[]]
	expansion' 1 _ = [[1]]
	expansion' num bound = [(x : l) | x <- [1 .. top], l <- (recoursive x)] where
		top = min bound num
		new_bound x = min x bound
		recoursive x = (expansion' (num - x) (new_bound x))