# Praticar
**Pilha (Stack)**

Aplicações comuns: rastreamento de chamadas de funções em execução 
(pilhas de chamada), operações desfazer/refazer em softwares e gerenciamento de 
memória em sistemas computacionais. 

```python
# Criando uma lista vazia que terá a função de uma pilha
pilha = []
# Adicionando elementos ao final da pilha (LIFO)
pilha. append(l)
pilha. append(2)
pilha. append( 3)
# Removendo o último elemento da pilha (primeiro a sair)
ultimo_elemento = pilha.pop()
# Imprimindo o último elemento da fila
print(f'O último elemento da fila é: {ultimo_elemento}')
```
## Exercício 1
- **Objetivo**: implementação de um Sistema de Atendimento ao Cliente com 
Filas de Espera. 
- **Cenário**: um sistema de atendimento ao cliente em que clientes aguardam 
atendimento em uma fila. 
- **Implementação**: utilização de uma fila para gerenciar a ordem de chegada 
de clientes. 
- **Operações**: 
    - Enfileirar: adição de clientes à fila. 
    - Desenfileirar: atendimento ao próximo cliente. 
    - Benefícios: garante atendimento na ordem de chegada, organizando eficientemente os pedidos de cliente.

## Exercício 2
- **Objetivo**: implementação de um Editor de Texto com Recurso de Desfazer (Undo). 
- **Cenário**: um editor de texto em que o usuário pode desfazer a última ação realizada. 
- **Implementação**: utilização de uma pilha para armazenar as ações do usuário. 
- **Operações**: 
    - Empilhar: adição de cada ação à pilha. 
    - Desempilhar: desfazer a última ação. 
    - Benefícios: oferece uma funcionalidade de desfazer eficiente, permitindo ao usuário reverter ações anteriores. 