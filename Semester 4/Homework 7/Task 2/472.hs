import System.Random
data Tree a = Empty
            | Node a (Tree a) (Tree a)
			
mapT :: (a ->b) -> Tree a -> Tree b
mapT _ Empty = Empty
mapT f (Node x l r) = Node (f x) (mapT f l) (mapT f r)

randomT :: Tree Int -> Tree Int
randomT t = mapT (fst .random . mkStdGen) t