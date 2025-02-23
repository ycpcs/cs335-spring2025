---
layout: default
course_number: CS335
title: Lab - Buffer Overflow
---

# Lab - Buffer Overflow Attack Lab

### Lab Overview 
In this lab, you will explore the concept of a ```buffer overflow attack```, which is a common security vulnerability in software. By exploiting a buffer overflow, an attacker can manipulate the program's execution flow, potentially executing arbitrary code.
  - <a href="..\schedule\papers\buffer-overflow.pdf" target="_blank">Buffer Overflow Attack</a>
  - <a href=".\buffer\stack_smashing.pdf" target="_blank">Smashing The Stack For Fun And Profit, Aleph One</a>

### Part 1: Calling an Unused Function in Code
In this task, you'll work with the provided [layout.c](buffer\layout.c) program, which contains an unused function, ```log_cs335_joke```. Your goal is to call this function from the command line, ensuring you pass the correct arguments.
- To avoid Segmentation Faults caused by stack protection, disable the stack guard:
  - ```-fno-stack-protector -z execstack```
- To turn off Address Space Layout Randomization (ASLR): ```$ sudo sysctl -w kernel.randomize_va_space=0```
  - Check the current randomization status: ```$ sudo sysctl kernel.randomize_va_space```
   
- **Important**: No modifications are allowed to the ```layout.c``` program itself.
  - You will need to capture the following in your report:
    - The exact command you used to run the program.
    - Terminal output showing the function's execution.
    - Screenshots of any debugging sessions you used to determine the correct command format.
  
### Part 2: Buffer Overflow Attacks of Privileged Programs  
- Tasks Description: <a href="./buffer/Buffer_Overflow_Setuid.pdf" target="_blank">Buffer Overflow.pdf</a>
- Lab Setup files: [Labsetup.zip](buffer\Labsetup.zip)
  - The **BUF SIZE** value for Task 3 (L1) is: **180**.
  - Tasks 5 & 6 are optional and for extra credit. Rest of the tasks are required.
    - These tasks provide additional challenges (64 bit) for those who want to go beyond the basics.

- Alternative to create _badfile_: [exploit.c](buffer\exploit.c).
- NOP - [No Operation](https://www.felixcloutier.com/x86/nop)
  - NOPs are used in buffer overflow exploits to pad the payload.

#### Important Setup Instructions
- The following command can be used to link ```/bin/sh``` to ```/bin/zsh```: ```sudo ln -sf /bin/zsh /bin/sh```
- To unconditionally _make_ all targets: ```make -B```
- Debugging the program:
  - To debug the vulnerable program, use *gdb*: ```gdb stack-L1-dbg```
  - Set a breakpoint at the *bof* function: ```b bof```
  - To run the program: ```r```
  - To find the address of the buffer and frame pointer: 
    - ``` p &buffer```
    - ```p $ebp```
  - Calculate the offset between the buffer and frame pointer: ```p (0xbfffeb08 - 0xbfffeae8)```
  - Create an empty *badfile*: ```touch badfile``` 

### Grading
- Post your report in <a href="https://cs.ycp.edu/marmoset" target="_blank">Marmoset</a> by the scheduled due date in the syllabus. Your grade for this lab will be composed of:
- You need to submit a detailed lab report, with **screenshots**, to describe what you have done and what you have observed. You also need to provide explanation to the observations that are interesting or surprising. Please also list the important code snippets followed by explanation. Simply attaching code without any explanation will not receive credits.
  - 30% - Design:  The overall quality and structure of your exploit.
  - 30% - Observations: Insightfulness and depth in your understanding of the task
  - 40% - Explanation: Clarity and completeness of your report and analysis.
  - *Extra Credit*: Additional investigation beyond the requirements.

<!--
1	Familiar with Shell 5
2	Vulnerable program 5
3	Level 1 on 32 bit	30
4	Level 2 on 32 bit 30
7	dash countermeasures 15
8	ASLR 7.5
9	Other Protections	7.5
->