main = fmap ((\[n,m,a] -> product [(x+a-1)`quot`a | x <- [n,m]]) . map (read :: String -> Integer) . words) getLine >>= print