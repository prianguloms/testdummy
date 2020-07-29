# testdummy project
You are a dev, your code needs testing, but you hate writing tests... you are not alone, let testdummy write those tests for your project.

## testdummy@mshackathon2020
Welcome! Our goal is to **auto generate** a test project for an existing C++ project. This test project would cover both unit tests and integration tests. Don't worry, no dummy will be hurt on the process.

Test generation is a subtopic of code generation. Code generation is a common tool on most popular IDEs, from generating getters and setters, to creating classes based on a missing dependency. A popular tool in the 2000s that had the ability to generate code was [Resharper](https://www.jetbrains.com/help/resharper/Code_Generation_in_CPP.html#gmock).

### From zero to dummy... what do we need to tackle?

#### Find what to test
We first need a *dataset* of all declarations in a project for which we'll generate tests. A declaration could be a variable, method, class, import, package.

We obtain a program's declarations by exploring its ASTs and building a dependency graph (Priscila's dissertation). A dependency means declaration *X* references declaration *Y*.

[CppAst](https://github.com/foonathan/cppast) open-source library seems a good option for harvesting a C++ project ASTs. 

#### Reuse others' work... as much as possible
[IntelliTest](https://docs.microsoft.com/en-us/visualstudio/test/generate-unit-tests-for-your-code-with-intellitest?view=vs-2019) is Microsoft's Visual Studio tool for generating unit tests for C# code, however, Microsoft does not seem to have an equivalent for C++.

There seems to be a couple commercial solutions for automated unit tests generation, one that caught my attention was [Parasoft](https://www.parasoft.com/products/parasoft-c-ctest/), but did not try.

However, there are several well known open-source C++ classic test frameworks, among them: [GoogleTest](https://github.com/google/googletest), [UnitTest++](https://github.com/unittest-cpp/unittest-cpp/wiki) and [Boost](https://github.com/boost-ext/ut), none of them generates tests automatically.

After much searching, the closest open-source solution for C++ test generation is the work of a Spotify engineer: [RapidCheck](https://engineering.atspotify.com/2015/06/25/rapid-check/), source code [here](https://github.com/emil-e/rapidcheck). 

*Looks like the most viable option is to build upon RapidCheck and GoogleTest.*

#### Integration tests require integration points
All integration points should have a test. How do we identify integration points? Our dependency graph comes in handy for this one: 

    When X has a non-parenting dependency towards Y, and either X or Y are methods, we consider this an integration point.

Parenting (containment) is a type of dependency in which a  declaration *V* is declared within declaration *W*, for example, *V* is a global variable of class *W*.

#### Create good tests
A good test assess a set of properties that must always hold true, regardless of the input(s), aka *correctness*. The challenge is: how do we deduct correct response for a function call from its signature?

## Project goals
### P0 goals
1. Add complexity to our helloworld case study project:
    * Add at least 3 more classes to helloworld
    * Add at least 1 method for each class that references another class's method.
1. Write program that builds a dependency graph for our case study.
1. Write program that *generates* a test class 

### P1 goals
1. Identify how to assess *correctness* in a test.
1. Create dataset with properties per declaration.
1. Write program that identifies declarations that require unit testing.
1. Write program that identifies declarations that require integration testing.

### P2 goals
1. Write program that recieves as input a C++ project path, and combines previous work plus the actual execution:
    * Builds its dependency graph and declarations dataset
    * Creates a new empty test project
    * Generates unit tests
    * Generates integration tests
    * Executes all tests   

### P3 goals
1. Automatic reporting on results
1. Definition of metrics
1. Research whether it is possible to transform our testdummy engine to use ML, particularly a neural network. 

## Set your environment up 
Setting your environment might take up to 1hr.

- **C++ coding in VS Code**. 
Please follow instructions in this link: 
https://code.visualstudio.com/docs/cpp/config-msvc, you can stop before "Create Hello World" section. We already have the latter in this folder.
- **Compile and run helloworld**. Helloworld project is our case study, we'll generate a test project for it. You can find its code base in this same folder. Helloworld project already contains both tasks.json and launch.json, the first one is required for building, the second for running. You can build using Terminal > Run Build Task. You can run and debug using Run > Start Debugging.




