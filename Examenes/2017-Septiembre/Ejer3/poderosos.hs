module Main where

main :: IO ()
main = do
		print $ divisores 36
		print $ map (^2) (divPrimos 36)
		print $ npoderosos 10

divisores :: Int -> [Int]
divisores n = [x | x <- [1..n], n `mod` x == 0]
--Se añade a la lista todo x comprendido en ese rango que cumpla la ultima condición

esPrimo :: Int -> Bool
esPrimo n = divisores n == [1,n]

divPrimos :: Int -> [Int]
divPrimos x = [y | y <- (divisores x), esPrimo y]

esPoderoso :: Int -> Bool
esPoderoso x = [y | y <- (map (^2) (divPrimos 36)), elem y (divisores x)] == map (^2) (divPrimos 36)

auxPoderosos :: Int -> Int -> [Int]
auxPoderosos n x = if(n==0) then []
									 else if(esPoderoso x) then x:(auxPoderosos (n-1) (x+1))
									 else auxPoderosos n (x+1)

poderososHasta :: Int -> [Int]
poderososHasta n = [x | x <- [1..n],esPoderoso x ]

npoderosos :: Int -> [Int]
npoderosos n = auxPoderosos n 1

poderosos :: [Int]
poderosos = poderososHasta 10000
