enum MY_ENUM {
    A,
    B,
    C,
    MY_MAX
};

int funcA(void)
{
    return 1;
}

int funcB(void)
{
    return funcA();
}

int funcC(void)
{
    return 3;
}

typedef int (*MYPFN)(void);

MYPFN g_pfns[] = {funcA, funcB, funcC};

int EnumIndexTest1(MY_ENUM my_e)
{
    if(my_e >= MY_MAX) return -1;

    //This will also generate C26011 if EspX is enabled (by setting SDLUseEspX to true)
    MYPFN pfn = g_pfns[my_e];

    return pfn();
}
