# Seguridad en Sistemas Informáticos - Práctica 1

> CIFRADO DE VIGENERE

    Autor: Eric Dürr sierra - alu0101027005
           eric.durr.20@ull.edu.es

    Escuela Superior de Ingeniería y Tecnología - ULL

    22-FEB-2021

Este repositorio contiene un programa creado con el lenguaje C++ y empleando técnicas TDD con el fin de simular el cifrado de Vigenere para un alfabeto que no contiene la Ñ (26 letras)

### **Compilación del ejecutable**

```bash
$ make
```

### **Ejecución del programa**

**Ejecutar el programa para lanzar el menú de opciones**

```bash
$ ./vigenere
```

### **Lanzamiento de los tests**

```bash
$ make test
```

Se compila y ejecuta el conjunto de tests para luego ejecutarlos, de suceder satisfactoriamente debe aparecer lo siguiente por terminal:

```bash
Making tests: vigenere_test
g++ -o vigenere_test ./test/includer.test.cpp
./vigenere_test
===============================================================================
All tests passed (10 assertions in 2 test cases)
```

También se puede ejecutar un despliegue detallado de los tests si ya se ha lanzado el comando anterior:

```bash
$ ./vigenere_test -s
```

## Licencia

[MIT](https://choosealicense.com/licenses/mit/)
