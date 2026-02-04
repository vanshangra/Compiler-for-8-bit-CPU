void generateAssembly(ASTNode* node) {
  if(!node) return;
  switch(node->type){
    case NODE_VAR_DECL:
      printf("DECLARE %s\n", node->varName);
      break;
    case NODE_Arith_OP:
      generateAssembly(node->left);
      generateAssembly(node->right);
      if (node->op == OP_ADD) {
        printf("ADD\n");
      } else if (node->op == OP_SUB) {
        printf("SUB\n");
      }
      case NODE_ASSIGN:
      printf(";ASSIGN %s\n", node->varName);
      generateAssembly(node->value);
      break;
      case NODE_conditional:
      printf("IF ");
      generateAssembly(node->left);
      printf("CMP A, B\n");
      printf("JNZ END_IF\n");
      generateAssembly(node->right);
      printf("END_IF:\n");
      break;
  }
}
