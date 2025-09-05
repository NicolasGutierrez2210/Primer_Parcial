import Data.List (foldl')

main :: IO ()
main = do
    putStrLn "Ingrese una lista de numeros separados por espacios:"
    entrada <- getLine
    let numeros = map read (words entrada) :: [Double]
    if null numeros
       then putStrLn "La lista esta vacia, no se puede calcular el promedio."
       else do
           -- promedio definido como lambda
           let promedio = (\xs -> (foldl' (+) 0 xs) / fromIntegral (length xs))
           putStrLn $ "El promedio es: " ++ show (promedio numeros)
