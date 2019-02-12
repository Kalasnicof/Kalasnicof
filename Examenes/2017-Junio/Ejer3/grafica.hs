module Main where

main :: IO ()
main = do
		print $ curveZeroes [8.0,0.0,-2.0,-0.2,3.0,8.0,10.0,9.5,8.0,6.3,-0.3,-5.0,-6.0,-4.2,-0.3,0.0,0.0,0.3,0.8,3.5,4.0,0.5,0.0,0.0,0.2,0.5,4.0]

auxCurve :: Double -> [Double] -> Integer

auxCurve f [] = 0
auxCurve f (x:xs) = if((f == 0.0) && (x /= 0.0)) then 1 + auxCurve x xs
                    else if((f > 0.0) && x < 0.0) then 1 + auxCurve x xs
                    else if(f < 0.0 && x > 0.0) then 1 + auxCurve x xs
                    else auxCurve x xs


--Cuenta el numero de cruces con al recta no los cuentas
-- si se mantiene ahi un rato
curveZeroes :: [Double] -> Integer
curveZeroes (x:xs) = auxCurve x xs
