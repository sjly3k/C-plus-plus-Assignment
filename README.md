# :high_brightness: C++ Assignments in 2019, Fall Semester :high_brightness:

## 1. Student Management System Dev.

### Assignment Requirements

- You have to fully develop a Student Information Management System. This program should support inserting/searching/displaying student information. 
- After the program is terminated, the inserted student information should be maintained. This requires you to use file processing. (Do not use external library for the file processing. Use only C++ built-in libraries.)

### How can I solve this assignment
- With OOP concept, using class, inheritance, getter/setter, constructor/destructor, file I/O techniques.
- Develop Insert, Search function.

### How can you use this program

**Step 1**
- **Option 1** 
  - 🍴 Fork this repo!
  
- **Option 2** 
  - 👯 Clone this repo to your local machine using `https://github.com/onlyyou-teamb/Server.git`

**Step 2**
Execute exe file and take one file as an argument. Like this :
- a.exe file1.txt

**Step 3**
Choose menu.
- In Search, you can search member through member's name, studentID, department name. And you can see the list which is listed alphabetically.
- In Modify, you have to input member name, and write down his/her information again.
- In Insert, you can input member's information.

**Step 4**
- **HACK AWAY!** 🔨🔨🔨

**Step 5**
- 🔃 Create a new pull request 

## Update Issues

**UPDATE 1 (9/30, Mon)**
  
  - Seperate Main file into 2 cpp, header files (management / student).
  - Satisfied all requirements what my professor wants. 
  ```
    <1> Input StudentID exactly 10 digits.
    <2> Input Name, Department without any blanks.
  ```

## 2. Infinite Integer Calculator

### Assignment Requirements

- You have to fully develop a Infinite Integer Calculator System. This program should support (+ / - / *) operator.
- You should support when the given number is bigger than pow(2, 31)-1.

### How can I solve this assignment
- With OOP concept, using class, friend, const, static constants, opearator overloading, constructor/destructor techniques.
- Develop Insert, Search function.

### How can you use this program

**Step 1**
- **Option 1** 
  - 🍴 Fork this repo!
  
- **Option 2** 
  - 👯 Clone this repo to your local machine using `https://github.com/onlyyou-teamb/Server.git`

**Step 2**
Execute your IDE (CLion, Visual Studio 20XX, and etc) and open this 3 files.
(main.cpp, inf_int.h, inf_int.cpp)

**Step 3**
Go to main.cpp, write codes that you want to calculate using (+ / - / *) operator.

**Step 4**
- **HACK AWAY!** 🔨🔨🔨

**Step 5**
- 🔃 Create a new pull request 

### Update Issues

**UPDATE 1 (10/14, Mon)**
  
  - Memory allocation problem occurs.
  ```
    <1> Solve this problem with using realloc and re-calculate the size of new object.
  ```
