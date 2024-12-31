---
layout: default
course_number: CS335
title: Lab - Buffer Overflow
---

# Lab - Buffer Overflow Attack Lab

### Lab Description and Tasks

- Lab Description: [Buffer Overflow.pdf](buffer\Buffer_Overflow_Setuid.pdf)
  - The **BUF SIZE** value for Task 3 (L1) is: **180**.
  - Tasks 5 & 6 are optional and for extra credit. Rest of the tasks are required.
  - Lab Setup files: [Labsetup.zip](buffer\Labsetup.zip)
  - Additional information on the SEED project [site](https://seedsecuritylabs.org/Labs_20.04/Software/Buffer_Overflow_Setuid/).

- [Smashing The Stack For Fun And Profit](https://insecure.org/stf/smashstack.html), Aleph One

- Alternative to create _badfile_: [exploit.c](buffer\exploit.c)
- NOP - [No Operation](https://www.felixcloutier.com/x86/nop)

### Tips

- The following command can be used to link ```/bin/sh``` to ```/bin/zsh```: ```sudo ln -sf /bin/zsh /bin/sh```
- To turn off address randomization: ```$ sudo sysctl -w kernel.randomize_va_space=0```
- Check the current randomization status: ```$ sudo sysctl kernel.randomize_va_space```
- If you forget to turn off the non-executable stack protection ``` -z execstack``` you will get a *Segmentation fault*
- Use ```-fno-stack-protector``` to turn off the StackGuard 

<!--
 - To compile the ```stack.c``` program using debug flags: ```gcc stack.c -o gdb-stack -g -z execstack -fno-stack-protector```.
 -->

- To unconditionally _make_ all targets: ```make -B```
- Now you can debug ```stack-L1-dbg``` to find the address of ```buffer``` and frame pointer ```($ebp)```
  - Start debugging by: ```gdb stack-L1-dbg```
  - To place a breakpoint at bof: ```b bof```
  - To run the program type: ```r```
  - To get address of buffer: ``` p &buffer```
  - Address of the frame pointer: ```p $ebp```
  - To find the offset: use ```p``` to substract the two, ex: ```p (0xbfffeb08 - 0xbfffeae8)```
  - You can exit gdb debugging session by typing ```quit```
- ```touch badfile``` will create an empty ```badfile```

### Grading

Post your report in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus. Your grade for this lab will be composed of:
- 30% - Design
- 30% - Observations
- 40% - Explanation
- *Extra Credit* if you pursue further investigation, beyond what is required by the lab description.

<!--

1	Familiar with Shell 5
2	Vulnerable program 5
3	Level 1 on 32 bit	30
4	Level 2 on 32 bit 30
7	dash countermeasures 15
8	ASLR 7.5
9	Other Protections	7.5

->