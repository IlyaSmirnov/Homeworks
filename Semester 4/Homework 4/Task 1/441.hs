data Tree a = Leaf a | Branch (Tree a) a (Tree a)
	deriving (Show)

findWithCondition :: Tree a -> (a -> Bool) -> Maybe a
findWithCondition (Leaf a) f = if (f a)
                            then Just a
                            else Nothing

findWithCondition (Branch a b c) f | f b = Just b
                            | otherwise = goDeep (findWithCondition a f) (findWithCondition c f)
                                            where
                                              goDeep :: Maybe a -> Maybe a -> Maybe a
                                              goDeep Nothing Nothing = Nothing
                                              goDeep (Just x) _ = Just x
                                              goDeep _ (Just x) = Just x
