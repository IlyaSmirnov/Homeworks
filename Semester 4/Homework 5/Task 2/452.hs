check :: (a -> Bool) -> [a] -> Bool
check cons list = foldl (\x y -> x && (cons y)) True list