import Data.List (sortBy)
import Data.Ord  (comparing, Down(..))

-- Definimos el tipo Estudiante
data Estudiante = Estudiante { nombre :: String, nota :: Double }
  deriving (Show, Eq)

-- Función para ordenar:
-- 1. Nota descendente (Down)
-- 2. Nombre ascendente (alfabético)
ordenarEstudiantes :: [Estudiante] -> [Estudiante]
ordenarEstudiantes =
  sortBy (comparing (Down . nota) <> comparing nombre)

-- Agregar un estudiante (no muta, devuelve nueva lista ya ordenada)
agregarEstudiante :: [Estudiante] -> String -> Double -> [Estudiante]
agregarEstudiante lista nom calif =
  ordenarEstudiantes (lista ++ [Estudiante nom calif])

-- Mostrar estudiantes
mostrarEstudiantes :: [Estudiante] -> IO ()
mostrarEstudiantes lista =
  mapM_ (\e -> putStrLn $ "Nombre: " ++ nombre e ++ ", Nota: " ++ show (nota e)) lista

-- Ejemplo de uso en main
main :: IO ()
main = do
  let estudiantes = []
  let lista1 = agregarEstudiante estudiantes "Nicolas" 2
  let lista2 = agregarEstudiante lista1 "Coco" 5
  let lista3 = agregarEstudiante lista2 "Nante" 3
  let lista4 = agregarEstudiante lista3 "Dodo" 3
  let lista5 = agregarEstudiante lista4 "Beto" 3

  mostrarEstudiantes lista5
