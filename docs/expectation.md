# ROTATE PROGRAMMING LANGUAGE

## Specs

1. High performance (native support)
1. Low learning curve
1. Cross-platform support (Linux , Windows, Mac(later))
1. [.vr] file extension


---

## OVERVIEW

## Hello World

```rust
log("Hello World");
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
// immutable string
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

example of a function that returned a string

---

## Imports

```c
// for files
import "file.vr";
```

```c
// for std libs
import stdio;
```

---

## Strings

```dart
string name = "Hello World";
string name2 = "$name, World";
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

```fs
match x {
    | 1 :
        // do
        break;
    | 2 :
        // do
        break;
    | 3 :
        // do
        break;
}
```

---

## Loops

for and while same as C with another foreach loop

```dart
foreach(i, 0..10) {
    log("$i");
}
```

---

## Structs

> same as C

---

## OOP (later)
