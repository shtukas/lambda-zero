#ifndef BUILTINS_H
#define BUILTINS_H

#include "lib/tree.h"

extern Node* NIL;
extern Node* TRUE;
extern Node* FALSE;
extern Node* YCOMBINATOR;
extern Node* PARAMETERX;
extern Node* REFERENCEX;
extern Node* PRINT;
void initBuiltins(void);
void deleteBuiltins(void);
unsigned long long lookupBuiltinCode(Node* token);
Node* computeBuiltin(Node* builtin, long long left, long long right);

#endif
