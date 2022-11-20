# Multiprocesadores

En este repositorio se encuentra el proyecto final de la materia. Se encuentra dividido por carpetas, donde en cada una hay un read me con los resultados obtenidos y una breve explicación. Además, se incluyen los códigos utilizados y el archivo del reporte en pdf. Por último, se agregan los archivos generados durante la ejecución. 

## [Actividad 1.3](https://github.com/LuisAlfPerez/Multiprocesadores/blob/main/Actividad%201.3)
## [Actividad 1.4](https://github.com/LuisAlfPerez/Multiprocesadores/blob/main/Actividad%201.4)
## [Actividad 1.5](https://github.com/LuisAlfPerez/Multiprocesadores/blob/main/Actividad%201.5)
## [Actividad 2.1](https://github.com/LuisAlfPerez/Multiprocesadores/blob/main/Actividad%202.1)
## [Actividad 2.2](https://github.com/LuisAlfPerez/Multiprocesadores/blob/main/Actividad%202.2)

## Servidor

Para realizar las pruebas con máquina virtual, se utilizó el servicio que provee Google. Después de realizar una cuenta e ingresar un método de pago, se otorga un crédito gratuito para probar el sistema. 

![Servidor](https://github.com/LuisAlfPerez/Multiprocesadores/blob/main/servidor2.jpg)

Se montó una máquina virtual con las siguientes características:

![Servidor](https://github.com/LuisAlfPerez/Multiprocesadores/blob/main/servidor.jpg)

Una vez que se tenía acceso al servicio, fue necesario configurarlo para poder trabajar de manera correcta. Para ello se utilizaron los siguientes comandos: 

    sudo apt-get update
    sudo apt-get install git-all
    sudo apt-get install libomp-dev
    sudo apt-get install gcc
    
Posteriormente, se clonó este repositorio para facilitar el trabajo.
    
    git clone https://github.com/LuisAlfPerez/Multiprocesadores.git
    
Se ejecutó el programa en cada una de las carpetas. Una vez que ya se tenían los resultados, especialmente los que involucraban imágenes (actividad 2.1 y 2.2) se realizaba un push al repositorio, para evitar un manejo complicado de archivos. 

    git add .
    git commit -m "Add results"
    git push
    
