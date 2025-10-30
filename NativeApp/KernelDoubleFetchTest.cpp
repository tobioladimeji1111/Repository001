#include <windows.h>
#include <stdio.h>

VOID ExRaiseDatatypeMisalignment(VOID){}

ULONG_PTR MmUserProbeAddress;
#define MM_USER_PROBE_ADDRESS MmUserProbeAddress
#define ASSERT(x)

#define ProbeForRead(Address, Length, Alignment) {                           \
    ASSERT(((Alignment) == 1) || ((Alignment) == 2) ||                       \
           ((Alignment) == 4) || ((Alignment) == 8) ||                       \
           ((Alignment) == 16));                                             \
                                                                             \
    if ((Length) != 0) {                                                     \
        if (((ULONG_PTR)(Address) & ((Alignment) - 1)) != 0) {               \
            ExRaiseDatatypeMisalignment();                                   \
                                                                             \
                }                                                                    \
        if ((((ULONG_PTR)(Address) + (Length)) > (ULONG_PTR)MM_USER_PROBE_ADDRESS) || \
            (((ULONG_PTR)(Address) + (Length)) < (ULONG_PTR)(Address))) {    \
            *(volatile UCHAR * const)MM_USER_PROBE_ADDRESS = 0;              \
                }                                                                    \
        }                                                                        \
}

PVOID warn1(PULONG userptr)
{
    ProbeForRead(userptr, sizeof(*userptr), 1);

    if (*userptr > 0x7FFFFFFF)
        return NULL;

    return malloc(*userptr * 2);
}