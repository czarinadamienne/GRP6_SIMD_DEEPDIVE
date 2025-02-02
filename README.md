# Group 6 - Deep Dive: SIMD Programming

put project desc and specs here

## Members

* Alamay, Carl Justine
* Ang, Czarina Damienne
* Esteban, Janina Angela
* Herrera, Diego Martin

## Report

### I. Screenshots of Program output with execution time
1. DEBUG
   - C PROGRAM
     - 1 << 20 (2^20)<br/>
       ![image](https://github.com/user-attachments/assets/e444ceb2-9f16-4f8c-9822-721c6ca4439c)
       
     - 1 << 26 (2^26)
       ![image](https://github.com/user-attachments/assets/29995bda-263e-4bef-a814-f5adc8b371eb)

     - 1 << 28 (2^28)
       ![image](https://github.com/user-attachments/assets/7c5d1f78-caa5-479b-8196-f0256f4627cb)

  - X86-64 PROGRAM
    - 1 << 20 (2^20)
      ![image](https://github.com/user-attachments/assets/e82f7099-76c2-43da-8412-9b408a1e55a2)

    - 1 << 26 (2^26)
      ![image](https://github.com/user-attachments/assets/96d1e62e-cbc0-43b2-8af0-60981401c5a8)

    - 1 << 28 (2^28)
      ![image](https://github.com/user-attachments/assets/e15564ef-cda6-4922-b29e-1b2d356d0920)
      
  - SIMD XMM REGISTER
    - 1 << 20 (2^20)
      ![image](https://github.com/user-attachments/assets/e4795fb5-b3c4-4646-b237-54f5d65cb12f)

    - 1 << 26 (2^26)
      ![image](https://github.com/user-attachments/assets/3240b3e1-ddb1-425f-9f1b-d725b6367095)

    - 1 << 28 (2^28)
      ![image](https://github.com/user-attachments/assets/d96e45df-6779-4ac9-b1b9-1969fc75a909)
  
  - SIMD YMM REGISTER
    - 1 << 20 (2^20)
      ![image](https://github.com/user-attachments/assets/80bae7b1-7b43-4fd2-ac7d-9c967a463a94)

    - 1 << 26 (2^26)
      ![image](https://github.com/user-attachments/assets/5187410b-791b-43f0-966b-1211daa037d4)

    - 1 << 28 (2^28)
      ![image](https://github.com/user-attachments/assets/eb6d464b-f57f-4d19-a398-47b5a3159919)
    
  - AVERAGE TIMES
    - 1 << 20 (2^20)<br/>
      ![image](https://github.com/user-attachments/assets/0e3efdd6-f4c9-48b5-b266-241078b9ebdf)

    - 1 << 26 (2^26)<br/>
      ![image](https://github.com/user-attachments/assets/07a0bb18-37f4-41e1-8fd4-3a55855a53d8)

    - 1 << 28 (2^28)<br/>
      ![image](https://github.com/user-attachments/assets/1d9af4b4-a6f0-4b74-88d9-fe907a658707)

2. RELEASE
   -  C PROGRAM
     - 1 << 20 (2^20)
       ![image](https://github.com/user-attachments/assets/b462cfc3-f9bf-4059-b1b7-56bbb4ee215c)

     - 1 << 26 (2^26)
       ![image](https://github.com/user-attachments/assets/cc6d197e-7767-44ca-941f-a8f1c3b84714)

     - 1 << 28 (2^28)
       ![image](https://github.com/user-attachments/assets/6fbdc5cd-44b4-4e55-bdeb-c9d12612b787)

  - X86-64 PROGRAM
    - 1 << 20 (2^20)
      ![image](https://github.com/user-attachments/assets/1b040bfa-2ee6-465e-9949-15075ab3a7bf)

    - 1 << 26 (2^26)
      ![image](https://github.com/user-attachments/assets/4ee245aa-0253-4ad4-99cb-c3f221fa8df4)

    - 1 << 28 (2^28)
      ![image](https://github.com/user-attachments/assets/3a9ebe38-e578-497d-b46e-793b1f17f0c7)

  - SIMD XMM REGISTER
    - 1 << 20 (2^20)
      ![image](https://github.com/user-attachments/assets/50c1d13d-7300-484b-a1dc-2f7f78de7419)

    - 1 << 26 (2^26)
      ![image](https://github.com/user-attachments/assets/117319e9-528e-4396-989b-82efb941d035)

    - 1 << 28 (2^28)
      ![image](https://github.com/user-attachments/assets/b03f4597-f6f6-43fb-9404-2826adff4bff)

  - SIMD YMM REGISTER
    - 1 << 20 (2^20)
      ![image](https://github.com/user-attachments/assets/4bac7558-782d-47a9-b2dc-d4d8e5fa8fcb)

    - 1 << 26 (2^26)
      ![image](https://github.com/user-attachments/assets/2c7928ed-a145-434e-9a54-1219d339f41c)

    - 1 << 28 (2^28)
      ![image](https://github.com/user-attachments/assets/8834131d-80a1-4555-8b10-bd57973d41ea)

  - AVERAGE TIMES
    - 1 << 20 (2^20)<br/>
      ![image](https://github.com/user-attachments/assets/151b406a-509e-486c-9c27-2f472c56424e)

    - 1 << 26 (2^26)<br/>
      ![image](https://github.com/user-attachments/assets/adc90cbc-4580-4704-bb57-0635e7d3dd14)

    - 1 << 28 (2^28)<br/>
      ![image](https://github.com/user-attachments/assets/7516ce33-e1ef-45b7-a30b-da0773a8a6cc)

### II. Comparative table of execution time and analysis of the performance of different kernels
- A device with the following specs was used to run each implementation of the dot product formula.
  ![image](https://github.com/user-attachments/assets/9adbb5ee-c325-4e36-899d-ead55b283cb5)

Debug average execution times

| Vector size | C Program      | x86-64 Program | SIMD XMM Register | SIMD YMM Register |
| ----------- | -------------- | -------------- | ----------------- | ----------------- |
| 1 << 20     | 2.713340 ms    | 1.195887 ms    | 2.020687 ms       | 1.568683 ms       |
| 1 << 26     | 165.644127 ms  | 51.342810 ms   | 41.490890 ms      | 40.654257 ms      |
| 1 << 28     | 2044.198467 ms | 183.021090 ms  | 143.115577 ms     | 138.660233 ms     |
<br/>
Release average execution times

| Vector size | C Program      | x86-64 Program | SIMD XMM Register | SIMD YMM Register |
| ----------- | -------------- | -------------- | ----------------- | ----------------- |
| 1 << 20     | 1.796643 ms    | 1.113203 ms    | 1.058397 ms       | 0.742370 ms       |
| 1 << 26     | 51.196957  ms  | 50.529460 ms   | 38.223140 ms      | 36.910040 ms      |
| 1 << 28     | 167.466487 ms  | 203.354290 ms  | 152.361333 ms     | 139.470703 ms     |
<br/>
Debug speed factor

| Vector size | C Program      | x86-64 Program | SIMD XMM Register | SIMD YMM Register |
| ----------- | -------------- | -------------- | ----------------- | ----------------- |
| 1 << 20     | 1x             | 2.27x          | 1.34x             | 1.73x             |
| 1 << 26     | 1x             | 3.23x          | 3.99x             | 4.07x             |
| 1 << 28     | 1x             | 11.17x         | 4.07x             | 14.74x            |
<br/>
Release speed factor

| Vector size | C Program      | x86-64 Program | SIMD XMM Register | SIMD YMM Register |
| ----------- | -------------- | -------------- | ----------------- | ----------------- |
| 1 << 20     | 1x             | 1.61x          | 1.70x             | 2.42x             |
| 1 << 26     | 1x             | 1.01x          | 1.34x             | 1.39x             |
| 1 << 28     | 1x             | 0.82x          | 1.10x             | 1.20x             |

- **How much faster?**
- Looking at all test cases, the use of SIMD YMM came out to be the fastest in applying the dot product to a large dataset. At smaller vector lengths such as 2^20 the speed up factor is smaller in value with the execution times being close in value when comparing C to the assembly implementations of the dot product formula for both the debug and release mode of visual studio. When operating on a larger dataset such as 2^30, the speed up factor is much more noticeable. With debug mode, the speed up factors for x86-64, SIMD XMM, and SIMD YMM were 11.17, 14.28, and 14.74. Compared to the smaller vector length, the speed up factor grows on a larger scale for larger vector lengths when calling the assembly implementations of the dot product formula. There was an unexpected behavior in release mode where the x86-64 implementation was slower than the C implementation. This may have been due to the release mode of visual studio auto-vectorizing which may have significantly sped up the C program. Additionally, the release mode may have slower times than debug mode due to release mode possibly auto-vectorizing the C code. When calling the assembly implementations, this may slow down the CPU clock resulting in a slower speed up factor.

- **Why is it faster?**
- The reason SIMD YMM is faster than the C implementation is due to the registers being able to handle 8 int_32 elements at a time. Since the registers are 256-bits, it can process more elements per loop iteration leading to faster computation. The same applies to SIMD XMM which can handle 4 int_32 elements which computes more elements per loop iteration than in C. x86-64 is faster than C since it has direct control of the memory registers where C may have additional memory fetches introduced. This introduces a larger propagation delay in C in which x86-64 does not experience.

- **Boundary Handling?**
- The implementation of the dot product in SIMD XMM and SIMD YMM required special consideration. This was the inclusion of being able to handle vector lengths that were not multiples of 4 and multiples of 8 for XMM and YMM respectively. Due to XMM handling 4 elements at a time and YMM handling 8 elements at a time, an issue may occur in which the remaining elements at the end of the vector may not be one of these respective multiples. To address this, additional branches were included to handle this test case in which the remaining elements would be handled using a regular x86-64. For SIMD XMM, the remaining elements could possibly range from 1-3 elements while SIMD YMM would range from 1-7 elements.

### III. C Program 
- The project aims to test 4 different implementations of the dot product formula, namely in C, x86-64, SIMD XMM, and SIMD YMM. The functions for each implementation were called in one general C file where the execution times were benchmarked to see which performed the fastest set of computations. The vector sizes used were 2^20, 2^26, and 2^28. These numbers were used to test how well each implementation would work on an exponentially growing dataset.
* Dot Product Computation <br/>
  ![image](https://github.com/user-attachments/assets/dc08c092-97ee-4ea5-99dc-320cf36b5a22)
  <br/>
  Used a for loop that goes through each element of both vectors and multiplies the values of both vectors. The product is then added to sdot. This loops until it goes through all elements.<br/>

![image](https://github.com/user-attachments/assets/fa3eb18e-5217-4367-8e41-45b9c698b724)

   Since the C program is the one that will be calling all kernels and it is required to run it at least 30 times, each function that calls the kernel is enclosed in a for loop that calls the function, checks if the assembly language computed the dot product correctly, and records the execution time of that specific run. Sample code block is shown below.
<br/>
* Error Checking<br/>
  ![image](https://github.com/user-attachments/assets/62158dda-30f8-4a29-99cf-7b8a5ca12bd1)
  <br/>
  The error checkers of each kernel is found in the c program. It compares the final dot product value of the kernel with the error checker's answer. If both are equal then it prints out that the program is correct, else it will print out that the program is incorrect.


### IV. x86-64 Program
![image](https://github.com/user-attachments/assets/1ff57e9b-6d7e-4635-ad49-54e183f2fcd0)

- The x86-64 program computes for the dot product in a similar manner to the C program in which it processes one element at a time. However, the use of assembly allows for direct access memory registers which reduces the possible propagation delay that may be faced when using C as the source code's programming language. 

### V. SIMD XMM Program
![image](https://github.com/user-attachments/assets/8dba38ea-5342-4588-b07b-997e3b68e95a)

- The SIMD XMM program utilized instructions that would allow for the parallel computation of multiple elements for the dot product. This would allow for processing more elements per loop iteration. In this instance specifically, 4 elements would be processed for every loop iteration. Since the XMM registers can hold up to 128 bits, 4 elements of the data type int_32 may be processed per iteration (128 / 32 = 4). 

### VI. SIMD YMM Register
![image](https://github.com/user-attachments/assets/273e2ce8-017e-4096-ae41-1f959202313f)

- The SIMD YMM follows a similar implementation to the XMM version which leverages paralle computing for a more efficient processing of elements. The YMM register can hold up to 256 bits, which allows for more elements to be processed than the XMM register. Specifically, 8 elements of data type int_32 may be processed per loop iteration (256 / 32 = 8). 

### VII. Discussion
- Certain challenges faced during the creation of the project was the setup of the stack and the proper use of instructions. The setup of the stack posed a problem at first due to a typo in the original program. This unintentional use of typos applied as well to the use instructions in which the use of certain instructions such as movdqu or vmovdqu were misspelled. This issue was addressed through proper retracing of code to ensure all instructions were properly typed. Another issue faced was the printing of garbage values when calling the assembly functions from C. This issue was addressed through fixing the popping and pushing of specific registers. Lastly, the issue of handling elements that were not multiples of 4 and 8 for the XMM and YMM registers posed a challenge. This issue was addressed through the use of additional branches to properly handle these elements to still ensure proper computation of the dot product. 
