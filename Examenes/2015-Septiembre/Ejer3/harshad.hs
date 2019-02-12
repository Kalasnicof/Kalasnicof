module Main where

main :: IO ()
main = do
		print $ mod 50 10
		print $ digitos 1
		print $ mod 1 (sum (digitos 1))
		print $ sum (digitos 1)
		print $ harshad
		print $ harshadBounded 10 60

digitos :: Integer -> [Integer]
digitos 0 = []
digitos x = (mod x 10):(digitos (div x 10))

auxharshad :: Integer -> Integer -> [Integer]
auxharshad x y =  if(x==(y+1)) then []
									else if( (mod x (sum (digitos x))) == 0 ) then x:(auxharshad (x+1) y)
					 		    else  (auxharshad (x+1) y)

harshad :: [Integer]
harshad = auxharshad 1 10000

harshadBounded :: Integer -> Integer -> [Integer]
harshadBounded x y = auxharshad x y
