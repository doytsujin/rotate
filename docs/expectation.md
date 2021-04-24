# ROTATE PROGRAMMING LANGUAGE

## Expectations

1. Low learning curve
1. [.vr] file extension
1. syntax close to C as possible (with some exceptions (rust, js, F#, D, Dart))

---

# OVERVIEW

## Hello World

```rust
fn main() {
    print "Hello World";
}
```

---

## Comments

```rust
// single line comment

/* multi line comment */

/// Documentation comment
```

---

## Variables

```rust
// immutable string because it is all caps
let NAME: str = "a string";
let mut name2: str = "mutable string";
let mut char1: char = 'c';
let mut number1: int = 23;
let mut number2: float = 23.0;
let mut number3: double = 23.123;
```
(for now dynamic types, aiming for static types later)

---

## Arrays

```rust
let array2: int = [1, 2, 3];
```

---

## Functions

```rust
fn main() {
    print "Hello World";
}
```

doesn't return unless specified

```rust
fn example() -> str {
    return "Hello World";
}
```
```rust
fn IntegerReturn() -> int {
    let x: int = 10; 
    return x;
}
```

example of a function that returned a string

---

## Imports

```c
// for files
import file;
```

```c
// for std libs
import std.io;
```
"std" lib name 
"io" file name which is "io.vr"

```c
import lib.folder.file;
```
importing ^^ a lib

---

## Strings

```cs
let name = "Hello";
let name2 = $"{name}, World";
```

---
## Operators and Logic

> pretty much the same as C 



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

## Switch statements

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

```cs
foreach(i, 0..10) {
    log($"{i}");
}
```

---
## Might consider later

### Structures
### OOP 
