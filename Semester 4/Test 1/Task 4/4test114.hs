f :: (Floating a) => [a] -> a
f xs = sf xs 0 1 where
	sf [] acc_sum acc_cos = acc_sum / acc_cos
	sf (x : xs) acc_sum acc_cos = sf xs (acc_sum + x) (acc_cos * (cos x))