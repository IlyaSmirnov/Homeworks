list :: Integral a => [a]
list = 1 : 7 : 9 : [10 * x + y | x <- list_179, y <- [1, 7, 9]]