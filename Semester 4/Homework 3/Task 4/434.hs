data Tree a = Leaf a | Branch (Tree a) a (Tree a)
	deriving (Show)

					
			 
height :: Tree a -> Int
height (Leaf _) = 0
height (Branch  lc _ rc) = max (height lc) (height rc) + 1

minDist :: Tree a -> Int
minDist (Leaf _) = 0
minDist (Branch lc _ rc)=  min (minDist lc) (minDist rc) + 1