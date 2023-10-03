int _init()
{
    if (true)
        return;
    0();
    return;
}

long long sub_401020()
{
    void* v0;  // [bp-0x8]

    v0 = 0;
    goto *((long long *)4210560);
}

long long sub_401030()
{
    void* v0;  // [bp-0x8]

    v0 = 0;
    return sub_401020();
}

long long sub_401040()
{
    unsigned long long v0;  // [bp-0x8]

    v0 = 1;
    return sub_401020();
}

long long sub_401050()
{
    unsigned long long v0;  // [bp-0x8]

    v0 = 2;
    return sub_401020();
}

long long sub_401060()
{
    unsigned long long v0;  // [bp-0x8]

    v0 = 3;
    return sub_401020();
}

long long sub_401070()
{
    unsigned long long v0;  // [bp-0x8]

    v0 = 4;
    return sub_401020();
}

long long sub_401080()
{
    unsigned long long v0;  // [bp-0x8]

    v0 = 5;
    return sub_401020();
}

long long sub_401090()
{
    unsigned long long v0;  // [bp-0x8]

    v0 = 6;
    return sub_401020();
}

long long sub_4010a0()
{
    unsigned long long v0;  // [bp-0x8]

    v0 = 7;
    return sub_401020();
}

long long sub_4010b0()
{
    unsigned long long v0;  // [bp-0x8]

    v0 = 8;
    return sub_401020();
}

long long sub_4010c0()
{
    unsigned long long v0;  // [bp-0x8]

    v0 = 9;
    return sub_401020();
}

long long _start()
{
    char v0;  // [bp+0x0], Other Possible Types: unsigned long
    unsigned long v1;  // [bp+0x8]
    unsigned long long v2;  // rsi
    unsigned long v3;  // rax
    unsigned long long v4;  // rdx

    v2 = *((long long *)&v0);
    v0 = v3;
    __libc_start_main(main, v2, &v1, __libc_csu_init, __libc_csu_fini, v4); /* do not return */
}

// No decompilation output for function sub_4011ae

Exception thrown decompiling function deregister_tm_clones: 'Jump' object has no attribute 'depth'
Exception thrown decompiling function register_tm_clones: 'Jump' object has no attribute 'depth'
extern char __TMC_END__;

long long __do_global_dtors_aux()
{
    unsigned long v0;  // [bp-0x8]
    char v1;  // [bp+0x0]
    unsigned long v3;  // rax

    if (__TMC_END__)
        return v3;
    v0 = &v1;
    if (true)
    {
        __TMC_END__ = 1;
        return deregister_tm_clones();
    }
    __cxa_finalize();
    __TMC_END__ = 1;
    return deregister_tm_clones();
}

long long frame_dummy()
{
    return register_tm_clones();
}

int fail()
{
    puts("Hmm. I think that still needs a little work...");
    exit(0xffffffff); /* do not return */
}

int isprime(unsigned long a0)
{
    unsigned int v0;  // [bp-0x10]
    unsigned int v1;  // [bp-0xc]
    uint128_t v3;  // xmm0lq
    unsigned long long v4;  // xmm0lq
    uint128_t v5;  // xmm0

    if (!(unsigned int)a0)
    {
        return 0;
    }
    else if (!((char)a0 & 1))
    {
        return 0;
    }
    else if ((unsigned int)a0 != 1)
    {
        if ((unsigned int)a0 >= 0)
        {
            v3 = (unsigned int)a0;
        }
        else
        {
            v4 = (unsigned int)a0 >> 1 | (unsigned int)a0 & 1;
            v3 = v5 * 2;
        }
        sqrt((unsigned long long)v3);
        *((unsigned int *)&v3) = (unsigned int)v3 + 0x3ff0000000000000;
        v1 = v3;
        v0 = 2;
        while (true)
        {
            if (v0 > v1)
            {
                return 1;
            }
            else if ((0 CONCAT (unsigned int)a0) /m v0 >> 32)
            {
                v0 += 1;
            }
            else
            {
                return 0;
            }
        }
    }
    else
    {
        return 1;
    }
}

extern struct_0 *input;
extern struct_0 *ints;
extern struct_0 *longs;

int main()
{
    printf("Please input key: ");
    __isoc99_scanf("%ms");
    if (strlen(input) != 44)
        fail(); /* do not return */
    input->field_2b = 0;
    input = &input->padding_0[11];
    ints = input;
    longs = input;
    one();
    two();
    three();
    four();
    five();
    puts("Thank you for recovering my key! :)");
    free(&input->padding_0[11]);
    return 0;
}

extern unsigned long long ints;

int one()
{
    char v0;  // [bp-0xd]
    unsigned int v1;  // [bp-0xc]

    v1 = 0;
    for (v0 = 0; v0 <= 7; v0 += 1)
    {
        v1 += *((int *)(ints + v0 * 4));
    }
    if (v1 != 3438883315)
        fail(); /* do not return */
    return;
}

extern unsigned long long ints;

int two()
{
    char v0;  // [bp-0xd]
    unsigned int v1;  // [bp-0xc]

    v1 = 3735928559;
    for (v0 = 0; v0 <= 7; v0 += 1)
    {
        v1 ^= *((int *)(ints + v0 * 4));
    }
    if (v1 != 2343363816)
        fail(); /* do not return */
    return;
}

extern unsigned int ints[2];

int three()
{
    if ((char)(isprime(ints[0]) ^ 1))
        fail(); /* do not return */
    if ((char)(isprime(ints[1]) ^ 1))
        fail(); /* do not return */
    if (ints[0] < ints[1])
        fail(); /* do not return */
    return;
}

extern unsigned long long input;
extern unsigned int ints[2];

int four()
{
    unsigned long v0;  // [bp-0x30]
    void* v1;  // [bp-0x28]
    void* v2;  // [bp-0x20]
    char v3;  // [bp-0x18]

    v0 = ints[0] * ints[1];
    if (v0 != 1373896615854740309)
        fail(); /* do not return */
    v1 = 0;
    v2 = 0;
    v3 = 0;
    sprintf(&v1, "%016lx", (unsigned int)v0);
    if (strncmp(&v1, input + 8, 0x10))
        fail(); /* do not return */
    return;
}

extern unsigned int ints[8];

int five()
{
    if (ints[7] - ints[6] != 3135027)
        fail(); /* do not return */
    return;
}

long long __libc_csu_init(unsigned long long a0, unsigned long long a1, unsigned long long a2)
{
    void* v2;  // rbx

    if (false)
        return _init();
    v2 = 0;
    do
    {
        v2 += 1;
    } while (v2 != 1);
    return *((long long *)(4210016 + rbx<8> * 8))(a0, a1, a2);
}

long long __libc_csu_fini()
{
    unsigned long v1;  // rax

    return v1;
}

long long _fini()
{
    unsigned long v1;  // rax

    return v1;
}
