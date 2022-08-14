# Caso_1
 Solucion al caso 1 - "Four color theorem"

## Notas del diseño

Para modelar el mapa se cuenta con dos estructuras codependientes para la demostracion. La primera se trata de un arreglo booleano
bidimensional que modela el grafo de las regiones de manera tabular. Su tamaño es dado por la cantidad de regiones elevado al cubo.
Cada fila corresponde a la relacion que tiene una region con las otras, de manera que true equivale a adyacente. Para suministrar
el grafo se cuenta con 3 constantes, pero la tercera es meramente estetica para identificar un overlap. Por ejemplo:

*| Rn |  R1  |  R2  |  R3  | ... |*\n
*| R1 |  N/A |  Adj | !Adj | ... |*

La segunda modela los vertices del grafo y sus miembros retienen datos minimos como color e identificador para distinguir regiones.
Para complementar la tabla anterior, se debe proveer un arreglo que contiene una instancia por region y sus datos. La demostracion
recorre cada fila en busca de regiones adjacentes. Por cada pareja, determina si repiten colores. De ser así, la colorizacion dada no
cumple el teorema para el grafo del mapa.

El codigo fuente trae un ejemplo incluido del arreglo booleano y dos versiones del arreglo de vertices. Se incluye al repositorio la
representacion visual del mismo.
