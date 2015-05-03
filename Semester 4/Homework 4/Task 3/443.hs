countOfEvenMap:: [Int] -> Int
countOfEvenMap = sum . map (\x -> (x + 1) `mod` 2) 

countOfEvenFoldr:: [Int] -> Int
countOfEvenFoldr = foldr (\x y -> (x + 1) `mod` 2 + y) 0

countOfEvenFilter:: [Int] -> Int
countOfEvenFilter = length . filter (\x -> x `mod` 2 == 0) 