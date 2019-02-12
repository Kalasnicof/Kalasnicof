module TupleListPolynomial where

type Term = (Float,Int)
type Poly = [Term]

-- Esta función devolverá un polinomio que sólo contiene una x (el coeficiente
-- de grado 1 vale 1).
x::Poly
x = [(1.0,1)]

-- Esta función devolverá un polinomio que contenga como término independiente
-- la constante c (el coeficiente de grado 0 vale c).
coef :: Float -> Poly
coef c = [(c,0)]

--Esta funcion dado dos polinomios te devuelve la suma de los dos
addPoly :: Poly -> Poly -> Poly
addPoly [] [] = []
addPoly [] x = x
addPoly x [] = x
addPoly x y = if(snd(head x) > snd(head y)) then (head x):[] ++ (addPoly (tail x) y)
              else if(snd(head x) < snd(head y)) then (head y):[] ++ (addPoly x (tail y))
              else ((fst(head x) + fst(head y)),snd(head x)):[] ++ (addPoly (tail x) (tail y))

-- Esta función suma todos los polinomios que haya en la lista lp y devuelve
-- el resultado.
padd :: [Poly] -> Poly
padd [] = []
padd (x:[]) = x
padd (x:xs) = addPoly x (padd xs)

-- Esta funcion dados dos terminos te devuelve la multiplicacion de los dos
mulTerm :: Term -> Term -> Term
mulTerm x y = ((fst(x) * fst(y)), (snd(x) + snd(y)))

--Esta funcion dado un termino y un polinomio te devuelve la multiplicacion de
-- ese termino por todos los terminos del polinomio, map adaptado
mapTerm :: Term -> Poly -> Poly
mapTerm x [] = []
mapTerm x y = (mulTerm x (head y)):[] ++ (mapTerm x (tail y))

-- Esta funcion es una funcion aleatoria para multiplicar
mulPoly :: Poly -> Poly -> [Poly]
mulPoly [] x = []
mulPoly x y = (mapTerm (head x) y) :[] ++ (mulPoly (tail x) y)

-- Esta función multiplica todos los polinomios que haya en la lista lp y
-- devuelve el resultado.
pmul :: [Poly] -> Poly
pmul (x:[]) = x
pmul (x:xs) = padd (mulPoly x (pmul xs))

-- Dado un termino y un valor te devuelve el resultado de sustituir la x de
-- ese termino por el valor pasado
teval :: Term -> Float -> Float
teval x y = (fst(x) * (y ^ snd(x)))

-- Esta función evalúa el polinomio p para el valor x, devolviendo como
-- resultado el correspondiente número real resultado.
peval :: Poly -> Float -> Float
peval [] x = 0
peval y x = (teval (head y) x) + (peval (tail y) x)

-- Dado un termino te devuelve la derivada de ese termino
tderv :: Term -> Term
tderv x = (fst(x) * (fromIntegral (snd(x)) :: Float),(snd(x)-1))

-- Esta función calcula la derivada analítica del polinomio p, dando como
-- resultado otro polinomio.
pderv :: Poly -> Poly
pderv [] = []
pderv x = (tderv (head x)):[] ++ (pderv (tail x))
