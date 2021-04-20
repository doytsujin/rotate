# ROTATE PROGRAMMING LANGUAGE

## Expectations

1. Low learning curve
1. [.vr] file extension


---

## OVERVIEW

## Hello World

```rust
print "Hello World";
```

---

## Comments

```rust
// single line comment

/* multi line comment */

/// Documentaion comment
```

---

## Variables

```c
// immutable string because it is all caps
str NAME = "a string";
str name2 = "mutable string";
char char1 = 'c';
int number1 = 23;
float number2 = 23.0;
double number3 = 23.123;
```

more data types to be implemented

---

## Arrays

```rust
int[] array2 = [1, 2, 3];
```

start at zero

---

## Functions

```rust
fn main() {
    log("Hello World");
}
```

doesnt return unless specified

```rust
fn example() -> str {
    return "Hello World";
}
```
```rust
fn IntegerReturn() -> int {
    int x = 10;
    return x;
}

```

example of a function that returned a string

---

## Imports

```rust
// for files
import "file.vr";
```

```rust
// for std libs
import stdio;
```

---

## Strings

```py
str name = "Hello";
str name2 = "$name, World";
```

## Operators and Logic

> same as C

---

## If Statements

```rust
if x == 2 {
    // code
} else if x == 3 {
    // code
} else {
    // code
}
```

---

## Switch statments

```fsharp
match x {
    | 1 : // do
    | 2 : // do
    | 3 : // do
    | _ : // do default
}
```

---

## Loops

for and while same as C with another foreach loop

```d
foreach(i, 0..10) {
    log("$i");
}
```

---
## Might consider later
### Structs
### OOP 
