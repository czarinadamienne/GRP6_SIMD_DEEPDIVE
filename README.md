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
<center>Debug average times according to vector size </center>

| Vector size | C Program      | x86-64 Program | SIMD XMM Register | SIMD YMM Register |
| ----------- | -------------- | -------------- | ----------------- | ----------------- |
| 1 << 20     | 2.713340 ms    | 1.195887 ms    | 2.020687 ms       | 1.568683 ms       |
| 1 << 26     | 165.644127 ms  | 51.342810 ms   | 41.490890 ms      | 40.654257 ms      |
| 1 << 28     | 2044.198467 ms | 183.021090 ms  | 143.115577 ms     | 138.660233 ms     |
<br/>
- **Why is it faster?**

### III. C Program 

* How to run the program
* Step-by-step bullets

### IV. x86-64 Program


### V. SIMD XMM Program


### VI. SIMD YMM Register


### VII. Discussion

