module ArrayPolynomial where

type Poly = [Float]

-- Esta función devolverá un polinomio que sólo contiene una x (el coeficiente
-- de grado 1 vale 1).
x::Poly
x = [1,0]

-- Esta función devolverá un polinomio que contenga como término independiente
-- la constante c (el coeficiente de grado 0 vale c).
coef :: Float -> Poly
coef c = [c]

--Esta funcion dado dos polinomios te devuelve la suma de los dos
addPoly :: Poly -> Poly -> Poly
addPoly [] [] = []
addPoly x y = if(length x > length y) then addPoly ((replicate (length x - length y) 0) ++ y) x
              else if(length y > length x) then addPoly ((replicate (length y - length x) 0) ++ x) y
              else ((head x) + (head y)):[] ++ (addPoly (tail x) (tail y))

-- Esta función suma todos los polinomios que haya en la lista lp y devuelve
-- el resultado.
padd :: [Poly] -> Poly
padd [] = []
padd (x:[]) = x
padd (x:xs) = addPoly x (padd xs)

-- Esta funcion es una funcion aleatoria para multiplicar
mulPoly :: Poly -> Poly -> [Poly]
mulPoly [] [] = []
mulPoly [] x = []
mulPoly x y = ((map(*(head x)) y) ++ (replicate (length x - 1) 0)) :[] ++ (mulPoly (tail x) y)

-- Esta función multiplica todos los polinomios que haya en la lista lp y
-- devuelve el resultado.
pmul :: [Poly] -> Poly
pmul [] = []
pmul (x:[]) = x
pmul (x:xs) = padd (mulPoly x (pmul xs))

-- Esta función evalúa el polinomio p para el valor x, devolviendo como
-- resultado el correspondiente número real resultado.
peval :: Poly -> Float -> Float
peval [] x = 0
peval y x = ((head y)* (x ^ (length y - 1))) + (peval (tail y) x)

-- Esta función calcula la derivada analítica del polinomio p, dando como
-- resultado otro polinomio.
pderv :: Poly -> Poly
pderv [x] = []
pderv x = ((head x) * (fromIntegral (length x - 1) :: Float)):[] ++ (pderv (tail x))
