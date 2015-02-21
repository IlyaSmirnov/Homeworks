listOfDegrees :: Integer -> [Integer]
listOfDegrees n = [2^x | x <- [1..n]]