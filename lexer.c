#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>

#define MAX_TOKEN_SIZE 100

typedef enum {
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_UNKNOWN,
    TOKEN_EOF,
    TOKEN_INT,
    TOKEN_ASSIGN 
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_IF,
    TOKEN_EQUAL,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_SEMICOLON,
    TOKEN_UNKNOWN
  } TokenType;

typedef struct {
    TokenType type;
    char lexeme[MAX_TOKEN_SIZE];
} Token;
Void getNextToken(FILE*file, Token* token) {
    int c;
    while((c=fgetc(file))!=EOF){
        if(isspace(c)) continue;
        if(isalpha(c)){
            int i=0;
            token->lexeme[i++]=c;
            while((c=fgetc(file))!=EOF && (isalnum(c))){
                token->lexeme[i++]=c;
            }
            token->lexeme[i]='\0';
            ungetc(c,file);
            if(strcmp(token->lexeme,"int")==0){
                token->type=TOKEN_INT;
            }else if(strcmp(token->lexeme,"if")==0){
                token->type=TOKEN_IF;
            }else{
                token->type=TOKEN_IDENTIFIER;
            }
            return;
        }
        if(isdigit(c)){
            int i=0;
            token->lexeme[i++]=c;
            while((c=fgetc(file))!=EOF && isdigit(c)){
                token->lexeme[i++]=c;
            }
            token->lexeme[i]='\0';
            ungetc(c,file);
            token->type=TOKEN_NUMBER;
            return;
        }
        switch(c){
            case '=':
                token->type=TOKEN_ASSIGN;
                token->lexeme[0]='=';
                token->lexeme[1]='\0';
                return;
            case '+':
                token->type=TOKEN_PLUS;
                token->lexeme[0]='+';
                token->lexeme[1]='\0';
                return;
            case '-':
                token->type=TOKEN_MINUS;
                token->lexeme[0]='-';
                token->lexeme[1]='\0';
                return;
            case '{':
                token->type=TOKEN_LBRACE;
                token->lexeme[0]='{';
                token->lexeme[1]='\0';
                return;
            case '}':
                token->type=TOKEN_RBRACE;
                token->lexeme[0]='}';
                token->lexeme[1]='\0';
                return;
            case ';':
                token->type=TOKEN_SEMICOLON;
                token->lexeme[0]=';';
                token->lexeme[1]='\0';
                return;
            case '==':
                token->type=TOKEN_EQUAL;
                token->lexeme[0]='=';
                token->lexeme[1]='=';
                token->lexeme[2]='\0';
                return;
            default:
                token->type=TOKEN_UNKNOWN;
                token
    }
  }

                .lexeme[0]=c;
                token->lexeme[1]='\0';
                return;
        }
    }

    token->type=TOKEN_EOF;
    token->lexeme[0]='\0';
  }
  void printToken(Token*token){
    printf("Token:%d, Text:'%s'\n",token->type,token->lexeme);
  }
