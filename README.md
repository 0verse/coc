# CoC
CoC is a systemic programming language of the C programming language.

## Cade Examples
```
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
    id id1 = {.name = "ali", .age = 244 };
    println("%s is %d years old", id1.name, id1.age);
}
```
