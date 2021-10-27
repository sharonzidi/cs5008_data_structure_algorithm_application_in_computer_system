# Lab 9 gdb
zidi Xia

## prog 1
- What was the bug?<br>We only malloc 10 int size in memory but there are 11 integers.
- What line did the bug occur?<br>In line 16.
- What is the fix for the bug?<br>Making i = 10 instead of 11.

## prog 2
- What was the bug?<br>We didn't catch the return value. So myInteger is nothing. 
- What line did the bug occur?<br>In line 32.
- What is the fix for the bug?<br>We need to catch the return value to fix it.
