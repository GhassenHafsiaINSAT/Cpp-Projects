# Modern C++ Programming

## C++ Type System

- C++ organizes the language types into two main categories:
  - **Fundamental types**: Types provided by the language itself.
    - Arithmetic types: integer and floating point.
    - `void`
    - `nullptr`
  - **Compound types**: Composition or reference to other types.
    - Pointers
    - References
    - Enumerators
    - Class Enumerators *( added in C++ 2011 Standard)*
    - Arrays
    - `struct`, `class`, `union` *(or since C++ 17 we can use the type-safe alternative: `std::variant`)*
    - Functions
    - Lambdas

## Conversion Rules

- *: any operation.  
    A. **Floating Point promotion**: floating type* integer type = floating type.
    B. **Implicit integer promotion** : small_integral_type *small_integral_type  = int.
    C. **Size promotion** : small_type* large_type = large_type.
    D. **Sign promotion** : signed_type * unsigned_type = unsigned_type.  
    E. **Implicit promotion** : +a / a+0 = ASCII code.  

## Auto Keyword

- It specifies that the compiler will automatically deduce the type of the variable
- `auto` can be useful for maintainability and hiding complex type definitions.  
- `auto` and `decltype` can be used to deduce the return type based on an expression.

## C++ Operators

### Operators Precedence

- **Unary** operators >> **binary** operators >> **Bitwise** operators >> **logic** operators >> **comparison** operators >> **compound assignment** operators >> **comma** operator.  

### Prefix and postfix Increment Semantic

- **Prefix Increment/Decrement** `++i`, `--i`
  - Update the value then return the new (updated) value.  
- **Postfix Increment/Decrement** `i++`, `i--`
  - Save the old value (temporary), update the value then return the old value.

## Declaration / Definition

- A declaration or a prototype introduces an entity with an identifier describing its type and properties.
- An entity definition is the implementation of a declaration. It defines the behaviour of the entity.

## Enumerators

- An enumerator `enum` is a data type that groups a set of named integral constants

```cpp
enum color_t {BLACK, BULE, GREEN };
color_t color = BLUE;
```

## Class Enumerators

- A class enumerator `enum class` is a data type added in the **C++ 11 Standard**. They are also known as **`scoped enumerations`**.

They are ***type safe***, ***strongly scoped*** variation of enumerations:

- **Type Safe:** as they do not allow implicit conversions to int similar to how `nullptr` does not allow conversion to 0 and does not allow comparisons with other enumerations. Thus, solving many type-related problems and potential bugs in code.
- **Strongly Scoped:** as they do not cause variable naming problems. *(This will be further discussed in the next section)*.

Here is an example of an enum class:

```cpp
// Declaration
enum class EnumName{ Value1, Value2, ValueN};

// Initialisation
EnumName ObjectName = EnumName::Value1;

// Declaration
enum class Color{ Red, Green, Blue};

// Initialisation
Color col = Color::Red;
```

## Enumerators VS Class Enumerators

Here are some of the classic C-enum pitfalls:

- Enums are Named Integer Constants so comparison with integers, and other enums is allowed and doesn't cause a compilation problem but it can be overlooked in development and cause problems.
- Different Enums Values can't have the same name, you can't have for example an enum value of ERROR in Networking_Result enum and Parsing_Result enum. **This problem can be caused by variables too:** A variable called ERROR will cause a compilation error even if it has nothing to do with the enum.

**C++ 11** introduced Class enumerators to solve these pitfalls.

## Unions

- A `union` is a structure where data members share the same memory space: This definition means that at any given time, a union can contain no more than one object from its list of members. It also means that no matter how many members a union has, it always uses only enough memory to store the largest member.
- A `union` can be used for:
  - saving memory space by allowing two data members that are never used at the same time to share the same piece of memory. Example:

    This code here:
  
  ```cpp
  void F1(int   x[]); // F1 changes the content of x.
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

  can be written as this:
  
  ```cpp
  void F1(int   x[]); // F1 changes the content of x.
  void F2(float x[]); // F2 changes the content of x.
  void F3(bool y) {
    union { 
      int   a[1000]; 
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

  Using this method is perfect for big Data that is not used at the same time. It saves data as well as reduces the amount of cache misses because the same memory will be used more. This affects memory especially if the data is big enough. Putting simple variables into a union is not optimal because it prevents the use of register variables.
  
- accessing the same data in different ways. Example:

    ```cpp
    union { 
      float f; 
      int i; 
    } x; 
    x.f = 2.0f; 
    x.i |= 0x80000000;  // set sign bit of f 
    cout << x.f;        // will give -2.0 
    ```

  In this example, the sign bit of f is set by using the bitwise OR operator, which can only be applied to integers.

- ***BE AWARE:*** Unions can be a source of bugs. Be sure to maintain it well. You're responsible for ensuring that you always access the same member you assigned. If any member types have a nontrivial constructor, then you must write code to explicitly construct and destroy that member.

## Std::Variant

At its core, `std::variant` is a `union` of types. It can store one value at a time from a predefined set of types. Unlike a traditional `union`, `std::variant` keeps track of its active type, ensuring that you access the correct value.

## Struct vs Union

- A struct groups different variables into a single unit, each variable has its location in memory.
- A union groups different variables in the same memory location.

In a nutshell, struct members each have an offset while union members all have an offset of 0 in memory:

- The Size of a struct is the sum of the size of all its members + padding. (structure padding is used for efficiency and performance purposes).
- The Size of a union is the size of its biggest member.
