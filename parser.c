#include<stdlib.h>
  
typedef enum{
  NODE_VAR_DECL,NODE_ASSIGN,NODE_Arith_OP,NODE_conditional
} NodeType;

typedef struct ASTNode{
  NodeType type;
  struct ASTNode* left;
  struct ASTNode* right;
  char text [MAX_TOKEN_LEN];
} ASTNode;
 ASTNode* createNode(NodeType type,char*text){
  ASTNode* node=(ASTNode*)malloc(sizeof(ASTNode));
  node->type=type;
  node->left=NULL;
  node->right=NULL;
  strcpy(node->text,text);
  return node;
 }
 void PrintAST(ASTNode* node, int depth){
  if(!node) return;
  for(int i=0;i<depth;i++) printf("  ");
  printf("%s\n",node->text);
  PrintAST(node->left,depth+1);
  PrintAST(node->right,depth+1);
 }
