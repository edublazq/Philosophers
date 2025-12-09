# 🍝 El Problema de los Filósofos Comensales

## 📖 Descripción del Problema

El **Problema de los Filósofos Comensales** (Dining Philosophers Problem) es un problema clásico de ciencias de la computación propuesto por Edsger Dijkstra en 1965. Este problema ilustra los desafíos de la sincronización de procesos en sistemas concurrentes y los problemas de asignación de recursos compartidos.

## 🎭 El Escenario

Imagina cinco filósofos sentados alrededor de una mesa circular. Cada filósofo alterna entre dos actividades:
- **Pensar** 🤔
- **Comer** 🍝

### Las Reglas

1. **La Mesa**: Hay una mesa redonda con cinco sillas, una para cada filósofo.

2. **Los Tenedores**: En la mesa hay un plato de espaguetis para cada filósofo. Entre cada par de filósofos adyacentes hay exactamente **un tenedor** (total: 5 tenedores).

3. **La Condición para Comer**: Un filósofo **necesita DOS tenedores** para comer:
   - El tenedor de su izquierda
   - El tenedor de su derecha

4. **El Ciclo de Vida**:
   ```
   PENSAR → TENER HAMBRE → TOMAR TENEDOR IZQ → TOMAR TENEDOR DER → COMER → SOLTAR TENEDORES → PENSAR
   ```

5. **Las Restricciones**:
   - Un tenedor solo puede ser usado por un filósofo a la vez
   - Los filósofos no pueden comunicarse entre sí
   - Cada filósofo solo puede tomar un tenedor a la vez
   - Un filósofo debe soltar ambos tenedores antes de volver a pensar

## 🎨 Representación Visual

```
                 🧔 Filósofo 1
                  🍴      🍴
                /            \
          🧔 F5                F2 🧔
           🍴                    🍴
             \                  /
              \                /
               \      🍝      /
                \          /
                 \        /
                  🍴    🍴
                🧔 F4--F3 🧔
```

## ⚠️ Los Problemas a Resolver

### 1. **Deadlock (Interbloqueo)**
Si todos los filósofos toman simultáneamente el tenedor de su izquierda, ninguno podrá tomar el tenedor de su derecha. Todos quedarían esperando eternamente.

```
        🧔 (tiene izq, espera der)
         ↓                      ↑
        🍴                      🍴
         ↓                      ↑
🧔 ← 🍴 ← 🧔          🧔 → 🍴 → 🧔
     (espera izq)  (tiene der, espera izq)
```

### 2. **Starvation (Inanición)**
Algunos filósofos podrían nunca conseguir comer si otros monopolizan los recursos.

### 3. **Race Conditions (Condiciones de Carrera)**
Múltiples filósofos intentando acceder al mismo tenedor simultáneamente.

## 💡 Soluciones Posibles

### Solución 1: Número Limitado de Comensales
Permitir que solo **N-1** filósofos intenten comer simultáneamente (4 de 5).

### Solución 2: Asimetría
- Filósofos impares: toman primero el tenedor izquierdo
- Filósofos pares: toman primero el tenedor derecho

### Solución 3: Mutex/Semáforos
Usar un mutex global o semáforos para controlar el acceso a los tenedores.

### Solución 4: Arbitraje
Un "camarero" que coordina qué filósofos pueden intentar comer.

### Solución 5: Jerarquía de Recursos
Numerar los tenedores y siempre tomarlos en orden ascendente.

## 🔧 Implementación Común

```c
// Estructura típica de una solución
while (1) {
    pensar();
    tomar_tenedores();  // Sección crítica
    comer();
    soltar_tenedores();
}
```

## 📊 Conceptos Clave

- **Mutex (Mutual Exclusion)**: Mecanismo para garantizar que solo un proceso acceda a un recurso
- **Semáforos**: Variables de sincronización para controlar el acceso a recursos compartidos
- **Threads/Hilos**: Procesos ligeros que ejecutan código concurrentemente
- **Deadlock**: Estado donde los procesos esperan recursos que nunca estarán disponibles
- **Starvation**: Proceso que nunca obtiene los recursos necesarios
- **Race Condition**: Comportamiento no determinista debido a timing de procesos

## 🎯 Objetivos de Aprendizaje

Este problema enseña:
1. Programación concurrente y paralela
2. Sincronización de procesos
3. Prevención de deadlocks
4. Gestión de recursos compartidos
5. Uso de primitivas de sincronización (mutex, semáforos)
6. Diseño de sistemas distribuidos

## 📚 Referencias

- Dijkstra, E. W. (1965). "Cooperating sequential processes"
- Problema clásico de sistemas operativos y programación concurrente
- Usado ampliamente en cursos de sistemas operativos y programación paralela

## 🚀 Aplicaciones Prácticas

Este problema es análogo a situaciones reales como:
- Gestión de bases de datos (locks en tablas)
- Sistemas operativos (asignación de recursos)
- Redes de computadores (acceso al medio)
- Sistemas distribuidos (coordinación de procesos)

---

**Nota**: Este es un problema teórico diseñado para ilustrar conceptos de concurrencia. Las soluciones prácticas deben adaptarse según el contexto y requisitos específicos del sistema.