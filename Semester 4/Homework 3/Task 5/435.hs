is_pair :: Char -> Char -> Bool	
is_pair x y = (is_correct x y) || (is_correct y x) where
	is_correct '(' ')' = True
	is_correct '[' ']' = True
	is_correct '{' '}' = True
	is_correct _ _     = False

is_correct_sequence :: String -> Bool
is_correct_sequence s  = (check s) == [] where	
	check = foldl (stack_op) [] where
		stack_op [] x = [x]
		stack_op (s : ss) x
			|is_pair x s = ss
			|otherwise = (x : s : ss)	