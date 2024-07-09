# Modern C++ Programming

## C++ Type System

C++ organizes language types into two main categories:

- **Fundamental types**: Types provided by the language itself.
  - Arithmetic types: integer and floating point.
  - `void`
  - `nullptr`

- **Compound types**: Compositions or references to other types.
  - Pointers
  - References
  - Enumerators
  - Class Enumerators *(added in C++11 Standard)*
  - Arrays
  - `struct`, `class`, `union` *(or, since C++17, the type-safe alternative: `std::variant`)*
  - Functions
  - Lambdas

## Conversion Rules

- **Floating Point Promotion**: floating type * integer type = floating type.
- **Implicit Integer Promotion**: small_integral_type * small_integral_type = int.
- **Size Promotion**: small_type * large_type = large_type.
- **Sign Promotion**: signed_type * unsigned_type = unsigned_type.
- **Implicit Promotion**: +a / a+0 = ASCII code.

## `auto` Keyword

- Specifies that the compiler will automatically deduce the type of the variable.
- `auto` can be useful for maintainability and hiding complex type definitions.
- `auto` and `decltype` can be used to deduce the return type based on an expression.

- The `auto` keyword was reintroduced in C++11 to simplify type declarations. In earlier versions of C++, `auto` was used to indicate automatic storage duration, which was the default and rarely explicitly stated. The modern usage allows for type inference, making code more concise and maintainable.

## C++ Operators

### Operators Precedence

Unary operators >> binary operators >> bitwise operators >> logical operators >> comparison operators >> compound assignment operators >> comma operator.

### Prefix and Postfix Increment Semantics

- **Prefix Increment/Decrement** `++i`, `--i`
  - Update the value then return the new (updated) value.
- **Postfix Increment/Decrement** `i++`, `i--`
  - Save the old value (temporary), update the value then return the old value.

## Declaration / Definition

- A declaration or prototype introduces an entity with an identifier describing its type and properties.
- A definition is the implementation of a declaration. It defines the behaviour of the entity.

## Enumerators

An enumerator `enum` is a data type that groups a set of named integral constants:

```cpp
enum color_t {BLACK, BLUE, GREEN};
color_t color = BLUE;
```

## Class Enumerators

A class enumerator `enum class` is a data type added in the **C++11 Standard**. They are also known as **scoped enumerations**. They are type-safe and strongly scoped:

- **Type Safe:** They do not allow implicit conversions to int, similar to how `nullptr` does not allow conversion to 0, and do not allow comparisons with other enumerations, thus solving many type-related problems and potential bugs in code.
- **Strongly Scoped:** They do not cause variable naming problems.

Here is an example of an enum class:

```cpp
// Declaration
enum class EnumName { Value1, Value2, ValueN };

// Initialization
EnumName objectName = EnumName::Value1;

// Declaration
enum class Color { Red, Green, Blue };

// Initialization
Color col = Color::Red;
```

## Enumerators vs Class Enumerators

Classic C-enum pitfalls:

- Enums are named integer constants, so comparison with integers and other enums is allowed and doesn't cause compilation problems, but it can be overlooked in development and cause issues.
- Different enum values can't have the same name. For example, you can't have an enum value of ERROR in both the `Networking_Result` enum and the `Parsing_Result` enum. Additionally, a variable called ERROR will cause a compilation error even if it has nothing to do with the enum.

**C++11** introduced class enumerators to solve these pitfalls. This enhancement was part of the broader effort in C++11 to improve type safety and modernize the language.

## Unions

A `union` is a structure where data members share the same memory space, meaning at any given time, a union can contain no more than one object from its list of members. It always uses only enough memory to store the largest member.

A `union` can be used for:

- Saving memory space by allowing two data members that are never used at the same time to share the same piece of memory. Example:

```cpp
void F1(int x[]); // F1 changes the content of x.
void F2(float x[]); // F2 changes the content of x.
void F3(bool y) {
  int a[1000];
  float b[1000];
  if (y) {  
    F1(a);
  }
  else {
    F2(b);
  }
  // do something else
}
```

This can be rewritten as:

```cpp
void F1(int x[]); // F1 changes the content of x.
void F2(float x[]); // F2 changes the content of x.
void F3(bool y) {
  union { 
    int a[1000]; 
    float b[1000]; 
  }; 
  if (y) { 
    F1(a); 
  } 
  else { 
    F2(b); 
  }
  // do something else
}
```

Using this method is perfect for large data that is not used simultaneously. It saves memory and reduces cache misses because the same memory will be used more often.

- Accessing the same data in different ways. Example:

```cpp
union { 
  float f; 
  int i; 
} x; 
x.f = 2.0f; 
x.i |= 0x80000000;  // set sign bit of f 
cout << x.f;        // will give -2.0 
```

In this example, the sign bit of `f` is set using the bitwise OR operator, which can only be applied to integers.

**Note:** Unions can be a source of bugs. Ensure proper maintenance and access the same member you assigned. If any member types have a nontrivial constructor, you must write code to explicitly construct and destroy that member.

## `std::variant`

At its core, `std::variant` is a union of types. It can store one value at a time from a predefined set of types. Unlike a traditional `union`, `std::variant` keeps track of its active type, ensuring correct value access.

### Examples for `std::variant`

`std::variant` allows you to store one value from a set of predefined types and keeps track of the active type:

```cpp
#include <iostream>
#include <variant>
#include <string>

int main() {
    std::variant<int, float, std::string> v;
    v = 42;
    std::cout << std::get<int>(v) << std::endl;  // Outputs: 42

    v = 3.14f;
    std::cout << std::get<float>(v) << std::endl;  // Outputs: 3.14

    v = "hello";
    std::cout << std::get<std::string>(v) << std::endl;  // Outputs: hello

    return 0;
}
```

## `struct` vs `union`

- A `struct` groups different variables into a single unit, each variable having its location in memory.
- A `union` groups different variables in the same memory location.

In a nutshell:

- The size of a `struct` is the sum of the size of all its members plus padding (for efficiency and performance).
- The size of a `union` is the size of its largest member.

## Lambda Functions

Lambda functions were introduced in C++11. Inspired by functional programming languages like Lisp, Haskell, and OCaml, they provide a practical way of defining closures (anonymous function objects that can be passed as arguments to functions or defined and invoked directly).

Lambdas are syntactic sugar over function pointers and allow for higher-order functions, such as `map`, `filter`, and `reduce` in JavaScript, enabling cleaner code.

Typically, lambdas are used to encapsulate a few lines of code that are passed to algorithms or asynchronous functions. They can access variables from the enclosing scope in three ways:

- Capture by reference.
- Capture by value.
- Capture by both (mixed capture).

Syntax for capturing variables:

- `[&]`: capture all external variables by reference.
- `[=]`: capture all external variables by value.
- `[a, &b]`: capture `a` by value and `b` by reference.

A lambda with an empty capture clause `[ ]` can only access variables that are local to it.

### Examples of Lambda Functions

Lambdas can be used in various ways, such as encapsulating code passed to algorithms:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Capture by value
    std::for_each(numbers.begin(), numbers.end(), [=](int n) {
        std::cout << n * n << " ";
    });
    std::cout << std::endl;  // Outputs: 1 4 9 16 25

    // Capture by reference
    int total = 0;
    std::for_each(numbers.begin(), numbers.end(), [&](int n) {
        total += n;
    });
    std::cout << "Total: " << total << std::endl;  // Outputs: Total: 15

    return 0;
}
```

## Memory Segments in C/C++

![image](https://github.com/GhassenHafsiaINSAT/C-Projects/assets/110825502/3cfcfbdc-c29e-4885-aacf-90334a5b7a36)

### Stack Memory

- **Characteristics**:
  - Small memory, Last-In-First-Out (LIFO) structure.
  - Allocation at compile-time.
  - Each thread has its own stack.
  - Local variables and function arguments reside here.
  - Objects inside the stack are valid only within their scope.

```cpp
int main() {
    int A[] = {1, 2, 3}; // Example of stack memory usage
}
```

### Heap (Dynamic Memory)

- **Characteristics**:
  - Larger memory area compared to stack.
  - Allocation at run-time using new (C++) or malloc (C).
  - Relies on virtual memory.
  - Memory is shared among threads.

```cpp
// Dynamic memory allocation examples

// C style allocation and deallocation
int* value = (int*)malloc(sizeof(int));
free(value);

// C++ style allocation and deallocation
int* value = new int;
delete value;

// Array allocation and deallocation
int* array1 = (int*)malloc(4 * sizeof(int));
free(array1);

int* array2 = new int[4];
delete[] array2;

// Initialization with zero
int* array3 = (int*)calloc(4, sizeof(int));

int* array4 = new int[4](); // Note the parentheses in C++
```

### BSS and Data segment

- **Characteristics**:

  - .bss and .data segments hold global and static global data.
  - Larger than stack memory but slower access.

```cpp
// Examples of data segment usage
int data[] = {1, 2}; // Data segment memory
int big_data[10000000] = {}; // BSS segment memory
```

### Code Segment (.text)

- **Characteristics**:
  - Contains the actual executable code.
  - Typically read-only in modern systems.
