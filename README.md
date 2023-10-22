# CoreC
CoreC is a systemic programming language based on top of the C programming language.

## Cade Examples
```
#include "corec.h"

    main()
{
    println("hello world");
}
```

```
#include "corec.h"

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
#include "corec.h"

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
