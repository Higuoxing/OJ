reorder :: [String] -> [String]
reorder (a: b: c) = c ++ [b] ++ [a]
