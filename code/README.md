# Documentación

## Fuerza Bruta

Para la realización del algoritmo se tomaron como referencia las siguientes fuentes:

#### Fuente 1

* Titulo: Longest Common Subsequence (LCS).
* Autor: GeeksforGeeks.
* Date: 04 Mar, 2025.
* Disponible en: https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

#### Fuente 2

* Titulo: Longest Common Subsequence.
* Autor: Programiz.
* Date: 23 May, 2025.
* Disponible en: https://www.programiz.com/dsa/longest-common-subsequence

### Programa principal

El programa principal utiliza diversas librerías de C++ como lo son "iostream", "fstream", "string", "vector" y "chrono". Además el código utiliza el header "algorithm/sequence_difference.h" que provee la implementación del algoritmo de fuerza bruta para encontrar la diferencia entre 2 secuencias.

El código principal abre el archivo de entrada "data/brute_force_input/inputs.txt" y lee el valor K, correspondiente al número de pares de prueba. A continuación, itera desde 0 hasta K–1. En cada iteración lee primero la longitud n y la cadena s, luego la longitud m y la cadena t. Para cada par de strings utiliza la función "fuerza_bruta::sequenceDifference(s, t)" y escribe su salida en el archivo "data/brute_force_output/outputs.txt".

El programa principal igualmente toma el tiempo que se demora en ejecutar la función  "fuerza_bruta::sequenceDifference(s, t)" para así escribir tales datos en "data/measurements/measurements.txt", colocando linea por linea las longitudes de los strings y el tiempo de ejecución de la función.

### Scripts

Los Scripts creados fueron:

* input_generator.py
* plot_generator.py
* makefile

## Programación Dinámica

Para la realización del algoritmo se tomaron como referencia las siguientes fuentes:

#### Fuente 1

* Titulo: Longest Common Subsequence (LCS).
* Autor: GeeksforGeeks.
* Date: 04 Mar, 2025.
* Disponible en: https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

#### Fuente 2

* Titulo: Dynamic Programming.
* Autor: Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.; Stein, Clifford.
* Date: 31 Jul, 2009.
* Disponible en: https://mitpress.mit.edu/9780262533058/introduction-to-algorithms/

#### Fuente 3

* Titulo: Longest Common Subsequence.
* Autor: Programiz.
* Date: 23 May, 2025.
* Disponible en: https://www.programiz.com/dsa/longest-common-subsequence

#### Fuente 4

* Titulo: Introduction to Dynamic Programming.
* Autor: CP Algorithms.
* Date: 09 Jan, 2025.
* Disponible en: https://cp-algorithms.com/dynamic_programming/intro-to-dp.html

### Programa principal

El programa principal utiliza diversas librerías de C++ como lo son "iostream", "fstream", "string", "vector" y "chrono". Además el código utiliza el header "algorithm/sequence_difference.h" que provee la implementación del algoritmo basado en programación dinámica.

El código abre el archivo de entrada "data/dynamic_programming_input/inputs.txt" para así leer el número de casos K. En un bucle de 0 a K–1, para cada caso lee las longitudes n y m y los strings s y t, y llama a "pd::sequenceDifference(s, t)". El resultado se escribe en "data/dynamic_programming_output/outputs.txt".

El programa principal igualmente toma el tiempo que se demora en ejecutar la función "pd::sequenceDifference(s, t)" para así escribir tales datos en "data/measurements/measurements.txt", colocando linea por linea las longitudes de los strings y el tiempo de ejecución de la función.

### Scripts

Los Scripts creados fueron:

* input_generator.py
* plot_generator.py
* makefile

