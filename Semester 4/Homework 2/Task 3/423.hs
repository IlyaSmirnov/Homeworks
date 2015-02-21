sumOfNumbers :: Integer -> Integer
sumOfNumbers 0 = 0
sumOfNumbers n = (n `mod` 10) + sumOfNumbers (n `div` 10)