/**
 * Implementace překladače imperativního jazyka IFJ22
 *
 * @file scanner.h
 * @brief Lexical analysis
 *
 * @author Dušan Slúka (xsluka00)
 */

#ifndef SCANNER_H
#define SCANNER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DYN_STR_SIZE 1

typedef enum
{
    Start,
    FID,
    VID1,
    VID2,
    Int,
    Float,
    Exp,
    Exp1,
    Exp2,
    Add,
    Sub,
    Mul,
    Div,
    Conc,
    Rol,
    Ror,
    Cul,
    Cur,
    Equ,
    Equ1,
    Equ2,
    Notequ,
    Notequ1,
    Notequ2,
    Less,
    Less1,
    Great,
    Great1,
    Com,
    Com1,
    Com2,
    Com3,
    Com4,
    String,
    String1,
    Esc,
    Esc1,
    Esc2,
    Esc3,
    Esc4,
    EOP,
    EOP2,
    EOP3,
    EEOF,
    Sem,
    Comm,
    Col,
    ERROR,
} States;

typedef enum
{
    ES_VID2,
    ES_FID,
    ES_Int,
    ES_Float,
    ES_Exp2,
    ES_Add,
    ES_Sub,
    ES_Mul,
    ES_Div,
    ES_Conc,
    ES_Rol,
    ES_Ror,
    ES_Cul,
    ES_Cur,
    ES_Equ,
    ES_Equ1,
    ES_Equ2,
    ES_Notequ,
    ES_Notequ1,
    ES_Notequ2,
    ES_Less,
    ES_Less1,
    ES_Great,
    ES_Great1,
    ES_Com1,
    ES_Com4,
    ES_String1,
    ES_KEY_WORD,
    ES_Prolog,
    ES_Comm,
    ES_Col,
    ES_EOP2,
    ES_Sem,
    ES_BIF,
    ES_EOF,
    ES_ERROR,
} End_States;

typedef struct TOKEN
{
    End_States end_state;

    union
    {
        float floating;
        int intiger;
        char *Str;
    } Value;
} TOKEN;

States Automat(States, int);

int check_for_keyword(char *);

End_States determin_EndState(States, char *);

bool check_prolog();

struct TOKEN generate_token();

#endif // SCANNER_H