# ROTATE PROGRAMMING LANGUAGE

## Expectations

1. Low learning curve
1. [.vr] file extension
1. syntax close to C and Rust as possible (with some exceptions ( js, F#, D, Dart))

---
## <a style="color:red;"> SYNTAX MAY BE CHANGED AT ANY MOMENT </a>

---
# OVERVIEW

## Hello World

```rust
import std.io;

fn main() {
    println("Hello World!");
}
```

---

## Comments

```rust
// single line comment

/* multi line comment */

/// Documentation comment
```
multiline comments cannot be nested i.e. 
```c
/*
    // allowed
    / * NOT ALLOWED * /
*/
```
---

## Variables

```rust
// immutable string 
let NAME: str = "a string";
// mutable string
let mut name2: str = "mutable string";

// immutable ascii char
let char1: char = 'c';
// immutable int
let number1: int = 23;

let number2: float = 23.0;
let number3: double = 23.123;
```

---

## Arrays

```rust
let array2[3]: int = [1, 2, 3];
```

---

## Functions

```rust
import std.io;

fn main() {
    io.println("Hello World");
}
```

doesn't return unless specified

```rust
import std.io as *;

fn example() -> str {
    return "Hello World";
}

fn main() {
    let i = example();
    println($"{i}");
}
```
```rust
fn IntegerReturn() -> int {
    let x: int = 10; 
    return x;
}
```

---

## Imports

```java
// for files
import file;
```

```java
// for std libs
import std.io;
```
"std" lib (folder) name \
"io" file name which is "io.vr"

```java
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

> pretty much the same as C with little modifications



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
    | 1 : // do         ;
    | 2 : // do         ;
    | 3 : // do         ;
    | _ : // do default ;
}
```

---

## Loops

for and while same as C with another foreach loop
```cs 
for (let i = 0; i < 10; i = i + 1) {
    println($"{i}");
}
```
```cs 
let i = 0;
while (i < 10) {
    println($"{i}");
    i = i + 1;
}
```
```cs
foreach(i, 0..10) {
    println($"{i}");
}
```

---
## Might consider later
### Structures
> structs are similar to c but with functions work same as modules 
