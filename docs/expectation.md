# ROTATE PROGRAMMING LANGUAGE

## Specs

1. High performance (native support)
1. Low learning curve
1. Cross-platform support (Linux , Windows, Mac(later))
1. immutable by default
1. [vr] file extension
1. can use C headers or have JNI support (later)
1. safety (later)
1. convert to Ts/Js/Wasm (later)
1. Multi-Threading (later)



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

```go
// immutable string
NAME: s = "a string"; 
name2: !s = "mutable string";
// 32bit int
number1 :i32 = 23;
unumber1 :ui32 = 23;
// 32bit float 
number2 :f32 = 23.0;
// 32bit double
number3 :d32 = 23.123;
```
more data types to be implemented

---

## Arrays
```go
array := [1, variable, "string"];
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
fn example() -> s {
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
  name:s = "Hello World";
  name2:s = "$name, World";
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
        //do 
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
