# SISTEMAS OPERATIVOS - LA FUNCION PIPE

En este taller se vera como funciona la funcion pipe, y simular su comportamiento en un shell.
Se probara teniendo como base el comando cat /etc/hosts | sort, pero ejecutandolo a travez
de un programa .c

El archivo que lo contiene el programa es:

* [Ejemplo_Pipe](pipesInAction.c)

Para ejecutarlo debera compilarse, se recomienda hacerlo con el comando
```
gcc pipesInAction.c -o pipesInAction
```
Y luego ejecutarlo con
```
./pipesInAction
```
Se vera que el resultado es el mismo que si se hiciera un cat /etc/hosts | sort
