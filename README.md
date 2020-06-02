# Bookstore Management system in C++

## How to run program

- Open terminal and run 
```
g++ sha256.cpp main.cpp -o sha256_example && ./sha256_example
```

## Objective
To build a secure bookstore management system, hence automating the process where the user buys books, automatically generating the bill for the user after the user is done shopping.

## Features
The bookstore system is a CLI tool which is built in C++.
The storage is in a file system which has  capability to store user details in **Directory.txt** and stores the records of the books sold in **Record.txt**

### SHA256
The user details stored, are hashed using SHA256, one of the most secure hashing algorithms available.
Plain text passwords are hence not stored in the system, enhancing the security for the user.

### Records
The bookstore owner has record of which books were sold, hence providing ease in management of stock.

<hr />

