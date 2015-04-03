data Press = Book { title :: String, author :: String, cost :: Int}
		| Magazine { title :: String, year :: Int, number :: Int, cost :: Int}
						
totalCost :: [Press] -> Int
totalCost x = totalcost' x 0 where
	totalcost' [] acc = acc
	totalcost' (x : xs) acc = totalcost' xs (acc + cost (x))