## fixed-point-vs-float-point-on-stm32-MCU-no-FPU
## No FPU used
#### This expriment tested on  <h6> STM32F446RE MCU

   ------------                                      |Fixed Point function  | Float Point function
   -----------                                       | ------------         | -------------
Execution time for 100 iteration with float array    | 0.000511us           | 0.002161us
Execution time for 1000 iteration with float array   | 0.005094us           | 0.011616us
Execution time for 1000 iteration with integer array | 0.007105us           | 0.010019us
