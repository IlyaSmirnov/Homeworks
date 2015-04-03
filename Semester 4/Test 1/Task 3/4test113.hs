elemPosition :: (Eq a) => a -> [a] -> Int
elemPosition x xs = fst(head(elemList)) where
		elemList = filter (\(_, z) -> z == x) (zip [1..] xs)