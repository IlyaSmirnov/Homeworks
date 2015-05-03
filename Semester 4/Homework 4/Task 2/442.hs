data Tree a = Leaf a | Branch (Tree a) a (Tree a)
	deriving (Show)

foldTree :: (a -> a -> a) -> a -> Tree a -> a
foldTree function start (Leaf x) = function start x
foldTree function start (Branch lc x rc) = foldTree function (foldTree function (foldTree function start lc) rc) (Leaf x)
