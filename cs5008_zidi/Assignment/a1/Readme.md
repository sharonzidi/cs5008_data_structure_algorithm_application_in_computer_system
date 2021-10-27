# Readme

Feb 3 Zidi
---
### warmup.c

- a program that prints the string "VICTORY!", with a newline at the end, three times in a row.
- How to use
  - ```gcc warmup.c```
  - ```./a.out```
- output
    ```
    VICTORY!
    VICTORY!
    VICTORY!
    VICTORY!
    VICTORY!
    VICTORY!
    ```
- First three lines using a single printf with three newlines in i. Last three lines using a for loop that iterates three times.


---
### rectangle.c

- A function PrintRectangle that prints out a rectangle of the specified width and height. 
- How to use
  - ```gcc rectangle.c```
  - ```./a.out```
- output
    ```
    -----
    -   -
    -   -
    -----
    ```
- The width specifies how many dashes are used for the top and bottom lines, and the height is the overall number of rows. 

---
### fancy_rectangle.c

- A function PrintFancyRectangle that prints out a rectangle of the specified width, height using a specific character, be filled in or not. 
- How to use
  - ```gcc fancy_rectangle.c```
  - ```./a.out```
- output
    ```
    ++++
    +  +
    +  +
    +  +
    +  +
    ++++

    ++++
    ++++
    ++++
    ++++
    ++++
    ++++

    ****
    *  *
    *  *
    *  *
    *  *
    ****

    ****
    ****
    ****
    ****
    ****
    ****
    ```
- The width specifies how many chars are used for the top and bottom lines, and the height is the overall number of rows. 