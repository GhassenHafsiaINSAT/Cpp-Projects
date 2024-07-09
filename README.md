# Modern C++ Programming

## C++ Type System

- C++ organizes the language types in two main categories:
  
    - **Fundamental types** : Types provided by the language itself.
        - Arithmetic types : integer and floating point.
        - `void`
        - `nullptr`
          
    - **Compound types** : Composition or reference to other types.
        - Pointers
        - References
        - Enumerators
        - Arrays
        - `struct`, `class`, `union`
        - Functions
## Conversion Rules

  - *: any operation.  

    A. **Floating Point promotion** : floating type * integer type = floating type.  
    B. **Implicit integer promotion** : small_integral_type * small_integral_type  = int.  
    C. **Size promotion** : small_type * large_type = large_type.  
    D. **Sign promotion** : signed_type * unsigned_type = unsigned_type.    
    E. **Implicit promotion** : +a / a+0 = ASCII code.    
## Auto Keyword
- It specifies that the type of the variable will be automatically deduced by the compiler
- `auto` can be very useful for maintainability and for hiding complex type definition.  
- `auto` and `decltype` can be both used to deduce the return type based on an expression.

## C++ Operators
### Operators Precedence 
- **Unary** operators >> **binary** operators >> **Bitwise** operators >> **logic** operators >> **comparison** operators >> **compound assignment** operators >> **comma** operator.  
### Prefix and postfix Increment Semantic
  - **Prefix Increment/Decrement** `++i`, `--i`
      - Update the value then return the new (updated) value.  
  - **Postfix Increment/Decrement** `i++`, `i--`
      - Save the old value (temporary), update the value then return the old value.
   
## Declaration / Definition 
- A declaration or a prototype introduces an entity with an idenitifer describing its type and propreties.
- An entity definition is the implementation of a declaration. It defines the behaviour of the entity.

## Enumerators 
- An enumerator `enum` is a data type that groups a set of named integral constants
```cpp
enum color_t {BLACK, BULE, GREEN };
color_t color = BLUE;
```
## Struct vs Union
- A struct groups different variables into a single unit, each variable has its own location in memory.  
- A union groups different variables in the same memory location.  

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
