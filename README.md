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
- ![5d663dbf-c72b-405b-bce6-a8d6706a2ae1](https://github.com/user-attachments/assets/d3342ce8-d38e-4319-863d-fbce980a0116)

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
Debug average execution times

| Vector size | C Program      | x86-64 Program | SIMD XMM Register | SIMD YMM Register |
| ----------- | -------------- | -------------- | ----------------- | ----------------- |
| 1 << 20     | 2.713340 ms    | 1.195887 ms    | 2.020687 ms       | 1.568683 ms       |
| 1 << 26     | 165.644127 ms  | 51.342810 ms   | 41.490890 ms      | 40.654257 ms      |
| 1 << 28     | 2044.198467 ms | 183.021090 ms  | 143.115577 ms     | 138.660233 ms     |

- **How much faster?**
- Looking at all test cases, the use of SIMD YMM came out to be the fastest in applying the dot product to a large dataset. At smaller vector lengths such as 2^20 the speed up factor is smaller in value with the execution times being close in value when comparing C to the assembly implementations of the dot product formula for both the debug and release mode of visual studio. When operating on a larger dataset such as 2^30, the speed up factor is much more noticeable. With debug mode, the speed up factors for x86-64, SIMD XMM, and SIMD YMM were 11.17, 14.28, and 14.74. Compared to the smaller vector length, the speed up factor grows on a larger scale for larger vector lengths when calling the assembly implementations of the dot product formula. There was an unexpected behavior in release mode where the x86-64 implementation was slower than the C implementation. This may have been due to the release mode of visual studio auto-vectorizing which may have significantly sped up the C program. Additionally, the release mode may have slower times than debug mode due to release mode possibly auto-vectorizing the C code. When calling the assembly implementations, this may slow down the CPU clock resulting in a slower speed up factor.

- **Why is it faster?**
- The reason SIMD YMM is faster than the C implementation is due to the registers being able to handle 8 int_32 elements at a time. Since the registers are 256-bits, it can process more elements per loop iteration leading to faster computation. The same applies to SIMD XMM which can handle 4 int_32 elements which computes more elements per loop iteration than in C. x86-64 is faster than C since it has direct control of the memory registers where C may have additional memory fetches introduced. This introduces a larger propagation delay in C in which x86-64 does not experience.

- **Boundary Handling?**
- The implementation of the dot product in SIMD XMM and SIMD YMM required special consideration. This was the inclusion of being able to handle vector lengths that were not multiples of 4 and multiples of 8 for XMM and YMM respectively. Due to XMM handling 4 elements at a time and YMM handling 8 elements at a time, an issue may occur in which the remaining elements at the end of the vector may not be one of these respective multiples. To address this, additional branches were included to handle this test case in which the remaining elements would be handled using a regular x86-64. For SIMD XMM, the remaining elements could possibly range from 1-3 elements while SIMD YMM would range from 1-7 elements.

### III. C Program 

* How to run the program
* Step-by-step bullets

### IV. x86-64 Program


### V. SIMD XMM Program


### VI. SIMD YMM Register


### VII. Discussion
- Certain challenges faced during the creation of the project was the setup of the stack and the proper use of instructions. The setup of the stack posed a problem at first due to a typo in the original program. This unintentional use of typos applied as well to the use instructions in which the use of certain instructions such as movdqu or vmovdqu were misspelled. This issue was addressed through proper retracing of code to ensure all instructions were properly typed. Another issue faced was the printing of garbage values when calling the assembly functions from C. This issue was addressed through fixing the popping and pushing of specific registers. Lastly, the issue of handling elements that were not multiples of 4 and 8 for the XMM and YMM registers posed a challenge. This issue was addressed through the use of additional branches to properly handle these elements to still ensure proper computation of the dot product. 
