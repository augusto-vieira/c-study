
/*
  Método virtual (c++)

    class Pessoa {
        void ola() { printf("Bom dia"); }
        virtual void bye() { printf("Adeus"); }
    };
                     (casting)
    class Barulhento: Pessoa {
        void ola() { printf("BOM DIA!"); }
        virtual void bye() { printf("FALOU!"); }
    };
    ...
    Barulhento joaozinho;
    Pessoa* p = &joaozinho;
    p->ola(); p->bye();

    ---------------------------------
    Saída:
        Bom dia
        FALOU!  
    ---------------------------------

    Em C...
    void Pessoa_ola() { printf("Bom dia");
    void Pessoa_bye() { printf("Adeus"); }
    void Barulhento_ola() { printf("BOM DIA!"); }
    void Barulhento_bye() { printf("FALOU!"); }
    ...
    Barulhento* joaozinho = Barulhento_new();
    Pessoa* p = (Pessoa*)joaozinho;
    Pessoa_ola(); p->klass->bye();

    //chamada de função direta(foi o que o compilador do c++ fez)
    Pessoa_ola();
    
    // Para fazer o virtual, ele olharia o p(ponteiro)
    // o Compilador tem que olhar o objeto(p), apartir do objeto chegar na classe(klass) dele,
    // lá na sua classe pegar o endereço da sua função certa
    // Teria que ter uma tabela da Classe que teria os ponteiros das funções 
    p->klass->bye(); 

    Isto tem custo de execução, é mais lento para o processador fazer. Como c++ pretende ser tão 
    rapida como C, existe essa preocupação. Logo o programador tem a opção de usar a chamada direta(Pessoa_ola)
    e não pagar os preço de uma chamada virtual(p->klass->bye)

*/

/*
  VTables - Tabelas Virtuais = Tabela com os endereços das funções
  Colocar na tabela "Os atributos de Classe", um só para todas as instâncias de uma determinada classe.
  Em Java é conhecido como atributos Static.
*/

/*
    Métodos virtuais no htop:

    Classes que derivam de Object redefinem
    delete
    display

    Classe Panel usa o método display
    
    Na prática, uma minoria das funções!

*/
/*
    Estruturas de dados:

    Bibliotecas de coleção,
    coleção = São objetos que guardam outros objetos
              são coleções (lista,pilha,hashtable,arvore)


    Linguagens OO tipicamente oferecem coleções padrão
    
    em C:
    Coleções (vetores, hashtables) podem nos ajudar muito na gerência de memória
*/

/*
    Ownership:

    Dentro do meu objeto eu dou um malloc, se dentro dessa classe eu dei um malloc(dentro daquele arquivo .c)
    o free tem que estar dentro do mesmo arquivo.
*/

/*
  Vector_delete
  limpar as coleções(fechar a tela, setup...)
*/


