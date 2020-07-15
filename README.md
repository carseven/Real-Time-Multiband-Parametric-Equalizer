# Real-Time-Multiband-Parametric-Equalizer
The aim of this project is to implement a real-time digital processing application using a recently introduced low-cost DSP. The C5515 will be used. We will implement a multi-band parametric audio equalizer based on the connection of several filters in parallel to process digital audio signals sampled at 48 kHz. The system will implement several equalization modes that can be selected by the buttons provided by the DSP board. Each mode will specify the gain (or attenuation) of each band. The implementation of the different bands will be done by means of FIR type filters.

The project has been divided into two phases, an initial design of the filter and prototyping of the convolution algorithm to implement the filter on input signals. This part was developed using MATLAB as the main tool because of the convenience of working directly on the DSP using C. The other part where we would export the designed filter and implement the convolution in the DSP.

All the detailed information can be found in the [documentation](https://github.com/carseven/Real-Time-Multiband-Parametric-Equalizer/blob/master/DOCUMENTATION/MemoriaTDS.pdf) here. The documentation is in Spanish, for more information contact me.

# Ecualizador-Multibanda-Paralelo-Tiempo-Real
El objetivo de este proyecto es implementar una aplicación de procesado digital en tiempo real utilizando un DSP de bajo coste de reciente aparición. Se va a utilizar el C5515. Implementaremos un ecualizador de audio paramétrico multibanda basado en la conexión de varios filtros en paralelo para procesar señales de audios digitales muestreadas a 48 kHz. El sistema implementara varios modos de ecualización que podrán ser seleccionables mediante los pulsadores que nos proporciona la placa del DSP. Cada modo será especificado la ganancia ( o atenuación ) de cada banda. La implantación de las diferentes bandas se realizará mediante filtros tipo FIR.

Hay que mencionar que el proyecto ha sido dividido en dos fases, una inicial de diseño del filtro y prototipado del algoritmo de convolución para implementar el filtro ante señales de entrada. Esta parte fue desarrollada usando MATLAB como herramienta principal por las comodidades que nos proporciona frente trabajar directamente en el DSP usando C. La otra parte en la que exportaríamos el filtro diseñado e implementaríamos la convolución en el DSP.

Toda la información detallada se encuentra en la [documentación](https://github.com/carseven/Real-Time-Multiband-Parametric-Equalizer/blob/master/DOCUMENTATION/MemoriaTDS.pdf) aqui.
