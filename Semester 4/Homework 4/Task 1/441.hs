data Tree a = Leaf a | Branch (Tree a) a (Tree a)
	deriving (Show)

filterTree :: (a -> Bool) -> Tree a -> [a]

filterTree p (Leaf x) = if p x 
						 then [x]
						 else []

filterTree p (Branch l x r) = if p x
                               then concat [[x], filterTree p l, filterTree p r]
                               else concat [filterTree p l, filterTree p r]