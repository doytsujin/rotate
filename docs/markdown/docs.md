
# Table of Contents

- [Table of Contents](#table-of-contents)
- [About](#about)
- [Overview](#overview)
  - [Display output](#display-output)
  - [Comments](#comments)
  - [Variables](#variables)
  - [Arrays](#arrays)
  - [Functions](#functions)
  - [Imports](#imports)
  - [Strings](#strings)
  - [Operators and Logic](#operators-and-logic)
  - [If statements](#if-statements)
  - [Match statements](#match-statements)
  - [Loops](#loops)
- [Considering Later](#considering-later)
  - [Structures](#structures)



<a id="org2650e01"></a>

# About

-   Low learning curve.
-   [.vr] file extension.
-   syntax close to C-like languages and Rust
-   static typing and scripting language

WARNING: SYNTAX MAY CHANGE AT ANY MOMENT


<a id="orgd9b36f5"></a>

# Overview


<a id="org8532d75"></a>

## Display output
```rust
    import std.io;
    
    fn main() {
        println("Hello World!");
    }
```

<a id="orgd333e22"></a>

## Comments
```rust
    // single line comment
    /* multiline
       comment */
    /// documentation comment

    /*
        // allowed
        /* not allowed * /
    */
```

<a id="orgfd6ff67"></a>

## Variables
```rust
    // immutable string
    let NAME: str = "a string";
    // mutable string
    let mut name: str = "mutable string";
    
    // immutable ascii char
    let char1: char = 'a';
    // immutable int
    let x: int = 1;
    
    let num: float = 12.0;
```

<a id="org80d3a7d"></a>

## Arrays
```rust
    let array[3]: int = [1, 2, 3];
```

<a id="orgb312b69"></a>

## Functions

use arrow for return type.
dont use arrow for void functions.
```rust
    fn example() -> str {
        return "example string";
    }
```

<a id="orgadff989"></a>

## Imports

import folder.file;
```java
    import std.io;
```

<a id="orge80f9db"></a>

## Strings
```rust
    let name = "Hello";
    let name2 = #"{name}, World!"#;
```

<a id="orgbb1a1a5"></a>

## Operators and Logic

same as C and Rust with little modifications


<a id="org932973b"></a>

## If statements
```rust
    if x == 1 {
        // code
    } else if x == 2 {
        // code
    } else {
        // code
    }
```


<a id="orgd060ad8"></a>

## Match statements
```rust
    match x {
        | 1 : // do ;
        | 2 : // do ;
        | 3 : // do ;
        | _ : // default;
    }
```

<a id="org543c904"></a>

## Loops

for and while loops as well as a foreach loop

```rust
    foreach (i, 0..2) {
        println(#"{i}"#);
    }
```

<a id="orgca00f24"></a>

# Considering Later


<a id="orgffc2296"></a>

## Structures

similar to C but without typedef and with functions

---

