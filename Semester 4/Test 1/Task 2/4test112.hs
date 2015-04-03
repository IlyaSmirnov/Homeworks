data Tree a = Leaf a | Branch (Tree a) a (Tree a)
	deriving (Show)
	
negativehelper :: (Ord a, Num a) => Tree a -> [a] -> [a]
negativehelper (Leaf a) (buf) 
	| a < 0 = (a : buf)
	| otherwise = buf

negativehelper (Branch lc a rc) (buf) 
	| a < 0 = negativehelper (rc) (a : other)
	| otherwise = negativehelper (rc) (other) where
 		other = negativehelper (lc) (buf)

negativefilter :: (Ord a, Num a) => Tree a -> [a]
negativefilter t = negativehelper t []