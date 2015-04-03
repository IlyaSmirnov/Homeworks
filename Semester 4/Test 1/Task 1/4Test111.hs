prime_list :: (Integral a) => [a]
prime_list = 2 : 3 : [x | x <- [4..], (filter (\y -> 0 == (mod x y)) [2.. (div x 2)]) == [] ]