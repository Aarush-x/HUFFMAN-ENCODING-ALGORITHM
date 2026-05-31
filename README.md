# Huffman Encoder

## Overview
This project is a C++ implementation of the Huffman coding algorithm, a popular method for lossless data compression. The program calculates character frequencies, builds a Huffman tree using a custom linked list, generates optimal prefix codes, and allows users to encode and decode text files.

## Features
The application provides an interactive command-line interface with the following options:
* Print the character weights and frequencies.
* Print the binary tree structure in a Right-Root-Left format.
* Display the generated Huffman codes for each ASCII character.
* Look up the specific Huffman code for a single character input.
* Compare standard ASCII binary output with compressed Huffman binary for a given word.
* Encode a complete text file (such as in.txt) into a compressed format.
* Decode a previously encoded file back to its original text format.

## Project Structure
* CMakeLists.txt: CMake build configuration targeting C++17.
* Header Files/:
  * HuffmanManager.h: Defines the core logic for the Huffman algorithm and file definitions.
  * LinkedList.h: Defines the sorted linked list used to build the tree.
  * HuffmanStructures.h: Contains the data structures used (HuffmanData, TreeNode, ListNode).
* Cpp Files/:
  * main.cpp: Program entry point.
  * HuffmanManager.cpp: Implements frequency counting, tree traversal, encoding, and decoding.
  * LinkedList.cpp: Implements the node insertion and list management logic.

## Getting Started

### Prerequisites
* A C++ compiler supporting C++17 or higher.
* CMake (version 3.10 or minimum required).

### Building the Project
1. Open your terminal and navigate to the root directory of the project.
2. Create a new build directory:
   mkdir build
   cd build
3. Generate the build files:
   cmake ..
4. Compile the executable:
   make

### Running the Application
Run the generated executable from your build directory:
./HuffmanEncoder

Follow the menu prompts to test out the logic. You can use the provided in.txt file when testing the file encoding feature.
