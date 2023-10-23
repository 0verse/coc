# The CoC Programming Language
CoC is a systemic programming language of the C programming language.

## Usage
```
./cocc.sh hello.coc
gcc -o hello hello.c
./hello
```

## Cade Examples
```rust
    main()
{
    println("hello world");
}
```

```
    main()
{
    i8 a = 5;

        if (a == 4)
    {
        println("a is %d", a);
    }
        or (a == 5)
    {
        println("a is %d", a);
    }
        fi
    {
        println("a is %d", a);
    }

}
```

```
    main()
{
    u8 a = '+';

        switch (a)
    {
        case '/':
            println("a is %c", a);
            break;
        case '*':
            println("a is %c", a);
            break;
        case '+':
            println("a is %c", a);
            break;
        case '-':
            println("a is %c", a);
        esac:
            println("a is other charcter");
    }
}
```

```
    def struct
{
    u8* name;
    u16 age;
}   id;

    main()
{
    id id1 = {.name = "ali", .age = 296};
    println("%s is %d years old", id1.name, id1.age);
}
```

```
    say_hello(u8* name)
{
    println("hello %s", name);
}

    i32 add(i32 a, i32 b)
{
    return a + b;
}

    main()
{
    u8* ad = "Kral Marks";
    say_hello(ad);

    i32 a = 250, b = 250;
    i32 c = add(a, b);
    println("%d + %d is %d", a, b, c);
}
```
