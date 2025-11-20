Danny Hido - CS 33211 Operating Systems - Fall 2025
# OS Assignment Two

This project implements the Bankers Algoritm. The Bankers Algorithm is a deadlock-avoidance method used in operating systems to ensure resource allocation to processes never
enters an unsafe state. The algorithm checks whether a system has enough available resources to satisfy the maximum needs of every process without causing deadlock.
This project implements a simulation of the Bankers Algorithm.

## Files
input.txt - contains details on the system under simulation. Contains information on process allocation, maximum, and available resources.
main.cpp - contains the algorithm. Reads in the systems status and processes from input.txt then runs the Bankers Algorithm to check if the system is in a safe state. The result is outputted to the console.

## How to Run

Must be run in a linux environment with g++ compiler

compile main.cpp: g++ main.cpp -o main
run in terminal: ./main

output will be state of the system (safe or unsafe) and order of processes (if safe).
