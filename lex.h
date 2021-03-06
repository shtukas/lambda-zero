#ifndef LEX_H
#define LEX_H

#include <stdbool.h>
#include <stdio.h>
#include "lib/tree.h"

extern bool TEST;

Hold* getFirstToken(const char* input);
Hold* getNextToken(Hold* lastToken);
bool isSameToken(Node* tokenA, Node* tokenB);
bool isThisToken(Node* token, const char* tokenString);
void printToken(Node* token, FILE* stream);
void throwTokenError(const char* type, const char* message, Node* token);
Node* newString(int location, const char* start);
Node* newEOF(void);

#endif
