### Comprison between Fixed Point Math and Float Point Math 
####  FPU IS DISABLED
#### This expriment tested on  <h6> STM32F446RE MCU
   
   ##### I tried to validate a powerful technique called Fixed Point Math.
So I tested the difference between execution time of Fixed Point Math and Float Point Math on STM32F446RE (FPU disabled).
1-First test I filled an array of (Hundred) elements with dummy float numbers then calculated the average of this numbers into each of fixed point function and float point function.
The result of execution time was
Fixed point : 0.000511us
Float point : 0.002161us

2- Second test I get the average of array of (Thousand) floating dummy elements and the result was
Fixed point : 0.005094us
Float point : 0.011616us

3- Third test I filled an array of (Thousand) with dummy (integer) numbers, the result was
Fixed point : 0.007105us
Float point : 0.010019us

All test cases are tested on (16 Mhz) HSI as a System Clock and base timer with 24 prescaler

   ------------                                      |Fixed Point function  | Float Point function
   -----------                                       | ------------         | -------------
Execution time for 100 iteration with float array    | 0.000511us           | 0.002161us
Execution time for 1000 iteration with float array   | 0.005094us           | 0.011616us
Execution time for 1000 iteration with integer array | 0.007105us           | 0.010019us
