El sistema debe cumplir lo siguiente:

1. Debe incluir sensores y actuadores.
2. Los sensores deben heredar de una clase abstracta Sensor.
3. Los actuadores deben heredar de una clase abstracta Actuator.
4. Debe existir una clase Device central que:
   - Herede de EventHandler y CommandHandler.
   - Coordine toda la lógica del sistema.
   - Contenga el estado del sistema como atributos de clase (NO variables locales).
5. El archivo sketch.ino debe ser minimalista:
   - Solo debe instanciar Device.
   - Solo debe llamar setup() y loop() delegando todo al Device.

6. Debe implementarse separación clara:
   - CommandHandler: lógica de cálculo / transformación de datos.
   - EventHandler: manejo de eventos del sistema.
   - Sensors: solo lectura de datos.
   - Actuators: solo salida (LCD, LED, Serial, etc).

7. Debe incluir:
   - Uso de funciones bien separadas.
   - Evitar lógica en el sketch.
   - Código limpio y modular en varios archivos (.h y .cpp).

8. Si hay cálculos físicos o matemáticos:
   - Deben implementarse dentro del CommandHandler.
   - El estado debe almacenarse en atributos del Device.

9. Debe incluir salida por Serial con los valores principales del sistema.

---

CASO IOT A DISEÑAR:

[DESCRIBE AQUÍ TU CASO]


---

REQUISITOS EXTRA:
- Usar ESP32 en Wokwi
- Pines deben ser definidos claramente
- Debe incluir archivos separados:
  Sensor.h, Actuator.h, Device.h, Device.cpp, etc.
