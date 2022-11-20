# Actividad 1.5
## Comparación de rendimiento entre el código ejecutado en la computadora personal y el servidor de google:

Se desarrollaron tres programas distintos, cada uno con un objetivo diferente: evaluar la velocidad del caché, de la memoria RAM y del disco duro. El caché fue probado por un programa que calcula el área bajo la curva, mientras la RAM y el disco duro con una ecuación diferencial. Para el caso del disco duro se escriben los resultados en un archivo de texto, lo que hace que el tiempo de guardado sea más lento.

## Rendimiento en computadora personal

Para que fuera equivalente la comparación del desempeño entre los programas, se utilizó el mismo número de pasos: 12,000,000. En el caso del área bajo la curva, al trabajar los 6 hilos al mismo tiempo, se toman los 12 millones. 

![Cache](https://github.com/LuisAlfPerez/Multiprocesadores/blob/main/Actividad%201.5/cache-personal.png)
Con este programa, se obtuvo el resultado en 0.084 segundos
Para las otras dos pruebas, se hicieron 2,000,000 de pasos, pero con 6 hilos, lo que las hace equivalentes. En el caso de la RAM, se calcularon los valores y se guardaron en un arreglo, lo que aseguró que no se trasladara al disco duro. 

![Ram](https://github.com/LuisAlfPerez/Multiprocesadores/blob/main/Actividad%201.5/ram-personal.png)
Con esta ejecución se tardó 0.361 segundos, que fue 0.277 segundos más lento.
Por último, se ejecutó el que guarda todo en un archivo de texto, y este fue significativamente más lento que los dos previos.
 
![SSD](https://github.com/LuisAlfPerez/Multiprocesadores/blob/main/Actividad%201.5/ssd-personal.png)
Se demoró 10.17 segundos, alrededor de diez segundos más. Con esto pudimos comprobar que es mucho más lento cuando se guarda en un archivo. 


## Rendimiento en servidor

![Servidor Google](https://github.com/LuisAlfPerez/Multiprocesadores/blob/main/Actividad%201.3/Servidor.jpg)

Se puede concluir que la respuesta en el servidor fue aleatoria, tal como era esperado. Sin embargo, se notó un poco más de orden, ya que, normalmente, mantuvieron el orden. Se observa de forma más clara en la gráfica, donde existen ciertas líneas que casi se mantienen horizontales entre diferentes corridas. 
