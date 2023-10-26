<img src="/images/logo.svg" width="30%" height="30%"></img>

# The Co C Programming Language
Co C is a systemic approach of the C programming language. The Co C syntax looks somewhat different but it is basically converted to, and fully compatible with C. Therefore, one can code valid C program if one wishes so, while mixing it with additional syntax. Needless to say, Co C is not a replacement of C.

## Usage
```
./cocc.sh examples/hello.co
gcc -o hello hello.c
./hello
```

## Example
```rust
    main()
{
    println("hello world!");
}
```
[More examples](https://github.com/0verse/coc/tree/main/examples)

## The forthcoming Co Programming Language syntax
```
"a 5        variable/array"
"< < >     enumerate/array"
"< > >    structure/object"
"< < > >   function/object"

b   "sol"
c "sağol"
ç   "sağ"
a b c ç

< color < red blue green >
< animal                 >
  kind  "cat"
  age     20
  says "myau"
>

x 10
y 20
< add < x y > x + y >

print < add < x y > >

< amra < >           >
< amra < x y >       >
< amra < x y > x + y >
< amra < x y         >
  x + y
>

yaz < amra < x y > >
yaz < "güle güle"  >
```
