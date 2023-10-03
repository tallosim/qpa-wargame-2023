# Keyme challenge

Key: `SECURITEAM{...}`

The key length is 32 characters, and the key is composed of 8 integers.

It can be got from 5 different functions, and each one of them make tests on the key.
From the tests, we can deduce the key.

## Function One

```c
int one()
{
    char v0;
    unsigned int v1;

    v1 = 0;
    for (v0 = 0; v0 <= 7; v0 += 1)
    {
        v1 += *((int *)(ints + v0 * 4));
    }
    if (v1 != 3438883315)
        fail();
    return;
}
```

Where the sum of the 8 integers must be equal to `3438883315`.

## Function Two

```c
int two()
{
    char v0;
    unsigned int v1;

    v1 = 3735928559;
    for (v0 = 0; v0 <= 7; v0 += 1)
    {
        v1 ^= *((int *)(ints + v0 * 4));
    }
    if (v1 != 2343363816)
        fail();
    return;
}
```

Where the XOR of the 8 integers must be equal to `2343363816`.

## Function Three

```c
int three()
{
    if ((char)(isprime(ints[0]) ^ 1))
        fail();
    if ((char)(isprime(ints[1]) ^ 1))
        fail();
    if (ints[0] < ints[1])
        fail();
    return;
}
```

Where the first integer must be a prime number, the second integer must be a prime number, and the first integer must be greater than the second integer.

## Function Four

```c
int four()
{
    unsigned long v0;
    void* v1;
    void* v2;
    char v3;

    v0 = ints[0] * ints[1];
    if (v0 != 1373896615854740309)
        fail()
    v1 = 0;
    v2 = 0;
    v3 = 0;
    sprintf(&v1, "%016lx", (unsigned int)v0);
    if (strncmp(&v1, input + 8, 0x10))
        fail();
    return;
}
```

Where the product of the first and second integers must be equal to `1373896615854740309`, and the 9th to 24th characters (16 characters, 4 ints) of the input must be equal to the hexadecimal representation of the product.

## Function Five

```c
int five()
{
    if (ints[7] - ints[6] != 3135027)
        fail(); /* do not return */
    return;
}
```

Where the difference between the 8th and 7th integers must be equal to `3135027`.

## Solution

From the third and fourth functions, we know that the first and second integers are prime numbers, and their product is equal to `1373896615854740309`. We can deduce that the first and second integers are `1664574001` and `825374309`. So we have the first two integers.

```python
ints[0] = 1664574001
ints[1] = 825374309
```

From the fourth function, we know that the 9th to 24th characters of the input are equal to the hexadecimal representation of the product of the first and second integers, which is `0x13110fb162221355`. So we have the 9th to 24th characters of the input.

```python
input[8:24] = "13110fb162221355"
```

From the fifth function, we know that the difference between the 8th and 7th integers is equal to `3135027`, and the sum of the 8 integers is equal to `3438883315`. So we can deduce the 8th and 7th integers.

```python
ints[6] = (3438883315 - 3135027 - sum(ints[:6])) / 2
ints[7] = ints[6] + 3135027
```
