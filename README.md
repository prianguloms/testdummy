# testdummy project
You are a dev, your code needs testing, but you hate writing tests... you are not alone, let testdummy write those tests for your project.

## testdummy@mshackathon2020
Welcome! Our goal is to **auto generate** a test project for an existing C++ project. This test project would cover both unit tests and integration tests. Don't worry, no dummy will be hurt on the process.

### New to test generation?
Test generation is a subtopic of code generation. Code generation is a common tool on most popular IDEs, from generating getters and setters, to creating classes based on a missing dependency, as shown in this article: https://www.jetbrains.com/help/resharper/Code_Generation_in_CPP.html#gmock.


### How do we find integration points?
We build a dependency graph using a program's AST data.
A dependency means declaration *X* references declaration *Y*. Where *X* and *Y* can be a method, variable or class.

Parenting (containment) is a special type of dependency. For example declaration *V* could be a global variable of class *W*.

When *X* has a non-parenting dependency towards *Y*, and either *X* or *Y* are methods, we consider this an integration point. 

### What about unit testing?
We'll generate tests for all methods in a class.

## Set your environment up 
Setting your environment might take up to 1hr.

- **C++ coding in VS Code**. 
Please follow instructions in this link: 
https://code.visualstudio.com/docs/cpp/ceonfig-msvc, you can stop before "Create Hello World" section. We already have the latter in this folder.
- **Compile and run helloworld**. Helloworld project is our case study, we'll generate a test project for it. You can find its code base in this same folder. Helloworld project already contains both tasks.json and launch.json, the first one is required for building, the second for running. You can build using Terminal > Run Build Task. You can run and debug using Run > Start Debugging.

## Hackathon goals
### P0 goals
* Add at least 3 more classes to helloworld
* Add at least 1 method for each class that references another class's method.
* Use library fo generating unit tests
* Build dependency graph

### P1 goals
* Use/write library for integration-test generation
    *  Includes creation of integration-test template
* Test integration-test library

### P2 goals
* Write program that recieves as input a C++ project path, and:
    * Builds its dependency graph
    * Creates a new empty test project
    * Generates unit tests
    * Generates integration tests
    * Executes all tests
    * Reports tests' outcomes    
    



