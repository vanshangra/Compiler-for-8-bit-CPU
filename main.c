int main(){
  FILE*file=fopen("input.txt","r");
  if(!file){
    perror("failed to open file");
    return 1;
  }
  ASTNode* ast= parse(file);
  fclose(file);

  printf("Assembly code generated from simpleLang\n");
  generateAssembly(ast);

  return 0;
}
