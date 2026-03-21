# Tarea 5

Aplicar los conceptos de arreglos dinámicos (vectores), manejo de memoria manual en C y optimización de hardware mediante instrucciones vectoriales (AVX) para simular y calcular métricas en un sistema de partículas.

Para ello:

1. Representar una partícula mediante una estructura de datos en un espacio tridimensional, dicha estructura incluye:
   - Coordenadas espaciales: $x, y, z$.
   - Magnitud de velocidad: $v$.

2. Con la implementación de **Vectores** instanciar y almacenar $n$ cantidad de partículas.

3. Mediante una función individual recibir dos partículas por referencia y calcular la "distancia" entre ellas en cada uno de sus ejes coordenados y su velocidad.

4. Aplicar la lógica del paso anterior a arreglos completos de partículas. Para ello se Con el desarrolla un Wrapper que debe recibir dos vectores de partículas ($V_1$ y $V_2$) y retornar un vector resultante ($V_r$), donde cada elemento corresponde a la distancia calculada entre las partículas de la misma posición:

5. Intentar implementar las instrucciones vectoriales **AVX**.
