import Data.Char
import Data.List
import Data.List.Split

swapfl :: [a] -> [a]
swapfl []      = []
swapfl [x]     = [x]
swapfl (x: xs) = (last xs : init xs) ++ [x]

encryptOneWord :: String -> String
encryptOneWord []      = []
encryptOneWord (x: xs) = (show $ ord x) ++ swapfl xs

encryptThis :: String -> String
encryptThis ss = intercalate " " $ encryptOneWord <$> (splitOn " " ss)
