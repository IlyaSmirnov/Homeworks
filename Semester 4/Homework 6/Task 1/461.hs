data BinaryCharTree = Empty | Node {value :: Char, left :: BinaryCharTree, right :: BinaryCharTree}
				deriving (Eq, Show)

treeToString :: BinaryCharTree -> String
treeToString Empty = "e"
treeToString (Node x lc rc) = 'n' : x : (treeToString lc) ++ (treeToString rc)

stringToTree :: String -> BinaryCharTree
stringToTree s | ((snd(stringToTreeHelper(s))) == "") = fst(stringToTreeHelper(s))

stringToTreeHelper :: String -> (BinaryCharTree, String)
stringToTreeHelper ('e' : xs) = (Empty, xs)
stringToTreeHelper ('n' : x : xs) = (Node x (fst leftNodeWrap) (fst rightNodeWrap), (snd rightNodeWrap)) where
	leftNodeWrap = stringToTreeHelper(xs)
	rightNodeWrap = stringToTreeHelper  (snd (leftNodeWrap))