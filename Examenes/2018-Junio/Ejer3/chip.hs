module Main where


type Tupla = (Float,Float,Float)

main :: IO ()
main = do
		print $ distancia_total [(3,4,10),(0,0,20),(3,4,35)]
		print $ es_subversivo [(3,4,10),(0,0,20),(3,4,35)]
		print $ es_subversivo [(3,4,10),(0,0,20),(3,4,3500)]
		print $ es_subversivo [(3,4,1000),(0,0,1010),(3,4,1035)]
		print $ velocidad_media [[(3,4,10),(0,0,20),(3,4,20)],[(3,4,10),(0,0,12),(3,4,20)]]

fst3 :: (a,b,c) -> a
fst3 (a,b,c) = a

snd3 :: (a,b,c) -> b
snd3 (a,b,c) = b

thr3 :: (a,b,c) -> c
thr3 (a,b,c) = c

auxDistancia_total :: Tupla -> [Tupla] -> Float
auxDistancia_total y (x:[]) = sqrt (((abs ((fst3 y)+(fst3 x)))^2) + ((abs ((snd3 y)+(snd3 x)))^2))
auxDistancia_total y (x:xs) = sqrt (((abs ((fst3 y)+(fst3 x)))^2) + ((abs ((snd3 y)+(snd3 x)))^2)) + auxDistancia_total x xs

distancia_total :: [Tupla] -> Float
distancia_total (x:xs) = auxDistancia_total x xs

auxEs_subversivo :: Tupla -> [Tupla] -> Bool
auxEs_subversivo y (x:[]) = if ((thr3 x - thr3 y) > 600) then True
														else False
auxEs_subversivo y (x:xs) = if ((thr3 x - thr3 y) > 600) then True
														else auxEs_subversivo x xs

es_subversivo :: [Tupla] -> Bool
es_subversivo x = auxEs_subversivo (0,0,0) x

auxVelocidad_media :: [[Tupla]] -> Float
auxVelocidad_media [] = 0
auxVelocidad_media (x:xs) = ((distancia_total x) / thr3 (last x))  + auxVelocidad_media xs

lenght_ex :: [[Tupla]] -> Float
lenght_ex [] = 0
lenght_ex (x:xs) = 1.0 + lenght_ex xs

velocidad_media :: [[Tupla]] -> Float
velocidad_media x = (auxVelocidad_media x) / (lenght_ex x)
