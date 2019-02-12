module Main where

main :: IO ()
main = do
		print $ split[1,2,3,4,5,6,7]
		print $ merge [1,3,5,7] [2,4,4,6]
		print $ msort [1,1,7,2,6,5,4,9,0]
		print $ head (split[1,2,3,4,5,6,7])
		print $ last (split[1,2,3,4,5,6,7])

auxSplit :: Ord t => [t] -> [t] -> [t] -> [[t]]
auxSplit t y [] = t:( y:[])
auxSplit t y (x:[]) = auxSplit (x : t) y []
auxSplit t y (x:r:xs) = auxSplit (x : t) (r : y) xs

split :: Ord t => [t] -> [[t]]
split x = auxSplit [] [] x

delete :: Ord t => t -> [t] -> [t]
delete t [] = []
delete t (x:xs) = if( t == x ) then xs ++ []
									else x:[] ++ (delete t xs)

auxmerge :: Ord t => [t] -> [t]
auxmerge [] = []
auxmerge xs = m : auxmerge (delete m xs) where m = minimum xs

merge :: Ord t => [t] -> [t] -> [t]
merge xs ys = auxmerge (xs ++ ys)

msort :: Ord t => [t] -> [t]
msort x = merge (head (split x)) (last (split x))
