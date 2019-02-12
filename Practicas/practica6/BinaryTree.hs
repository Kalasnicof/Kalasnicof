module BinaryTree where

-- H es igual a una hoja
-- N es igual a un nodo o raiz del arbol
-- N x l r (l arbol izquierdo(left)) (r arbol derecho(right))
data Tree t = Empty
             | H t
             | N t (Tree t) (Tree t)
             deriving (Show)


--Esta función devolverá un árbol vacío, sin ningún elemento.
empty::Tree t
empty = Empty

--Esta función devolverá un árbol que consista en una única hoja que
--contenga el elemento x.
leaf :: t -> Tree t
leaf t = H t

--Esta función devolverá un árbol que contenga en la raíz el elemento x,
-- con hijo izquierdo lb e hijo derecho rb. Tanto el hijo izquierdo como el
--hijo derecho son nodos del arbol, no elementos del tipo de dato genérico.
tree :: t -> Tree t -> Tree t -> Tree t
tree x y z = N x y z

--Esta función devuelve el número de elementos del árbol.
size :: Tree t -> Int
size (H _)     = 1
size (N x l r) = 1 + size l + size r

-- Funcion preorder
-- primero visita la raíz del árbol, a  continuación recorre el subárbol
--izquierdo y, finalmente, recorre el subárbol derecho
preorder :: Tree t -> [t]
preorder Empty     = []
preorder (H x)     = [x]
preorder (N x l r) = x : (preorder l ++ preorder r)

-- Funcion postorder
--primero recorre el subárbol izquierdo, a continuación el subárbol derecho
--y, finalmente, la raíz del árbol
postorder :: Tree t -> [t]
postorder Empty     = []
postorder (H x)     = [x]
postorder (N x l r) = postorder l ++ postorder r ++ [x]

-- Funcion inorder
--primero recorre el subárbol izquierdo, a continuación el subárbol derecho
--y, finalmente, la raíz del árbol
inorder :: Tree t -> [t]
inorder Empty     = []
inorder (H x)     = [x]
inorder (N x l r) = inorder l ++ [x] ++ inorder r

--Añade el elemento x al árbol t, devolviendo el resultado.
add :: Ord t => Tree t ->  t -> Tree  t
add Empty x = leaf x
add (H c) x
    | c >= x = tree c (leaf x) empty
    | c < x = tree c empty (leaf x)
add (N c l r) x
    | c >= x = tree c (add l x) r
    | c < x = tree c l (add r x)

-- Busca en el árbol t y devuelve una lista con todos los elementos que están
-- entre xmin y xmax (inclusive). No deberá recorrerse todos los elementos del
-- árbol, ni devolver la lista (necesariamente) ordenada.
between :: Ord t => Tree t -> t -> t -> [t]
between Empty xmin xmax = []
between (H c) xmin xmax
    | c >= xmin && c <= xmax = [c]
    | otherwise              = []
between (N c l r) xmin xmax
    | c > xmax = between l xmin xmax
    | c < xmin = between r xmin xmax
    | c >= xmin && c <= xmax = [c] ++ (between l xmin xmax) ++ (between r xmin xmax)
