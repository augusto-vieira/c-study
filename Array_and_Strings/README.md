# **Vetores, Strings, Ponteiros e Memória 📚**

**Expressões constantes de strings** são avaliadas para um endereço no tempo de compilação (assim como arrays) e armazenadas na seção `.rodata` (Read-Only Data), como podemos ver no código em assembly.

📋​**Seção `.rodata`**:
A `.rodata` (Read-Only Data) é uma seção de memória onde são armazenados dados imutáveis, como:  
- **Strings literais**  
- **Constantes numéricas**  
**Exemplo de Código**
```c
char *p = "salve"; 
char v[] = "banana";
```
Analisando o código:
- **`*p`** → Variável do tipo ponteiro
- **`"salve"`** → String literal
    - Aqui, `*p` recebe o endereço da string literal `"salve"`, que está na seção `.rodata`.
- **`v[]`** → Vetor (array) de caracteres
- **`"banana"`** → String literal
    - Neste caso, a string `"banana"` é usada para inicializar o vetor `v[]`, e os caracteres são armazenados diretamente na memória alocada para o array.

❌**Afirmação Errada**:
- A ideia de que "ponteiro aponta" não está correta.
✅​**Afirmação Correta**:
**1. Ponteiros não "apontam"**
- Ponteiro é uma variável que **recebe um endereço como valor**.
- Ele não possui um comportamento especial diferente de outras variáveis em C.
✅**Exemplo Correto de "Ponteiro Apontando"**
```c
int a = 10; 
int *b = &a;
```
Aqui, `b` recebe o **endereço** de `a`.
- Fazendo a **dereferência** (`*b`), acessamos o valor armazenado em `a`.
- Podemos dizer, metaforicamente, que `*b` "aponta" para `a`, porque conseguimos acessar seu valor indiretamente.

**2. Explicação sobre Ponteiros e Vetores**
- Variáveis representam dados em um endereço.
- Ponteiros são variáveis cujo valor é um endereço.
- Vetores representam **endereços fixos** do início de cadeias de dados do mesmo tipo.
- Subscritos de arrays representam **offsets** dos dados encadeados a partir de um endereço base.

🤔**Onde as Strings Literais São Armazenadas?**
**1️⃣ Strings Literais em Ponteiros (`char *p`)**
Quando usamos um **ponteiro** para armazenar uma string literal, a string fica na **.rodata** (seção de dados somente leitura), e o ponteiro recebe o endereço dela:

```c
char *p = "hello";
```
📌 **O que acontece?**
- `"hello"` está na `.rodata` (área de dados somente leitura).
- `p` recebe o **endereço** dessa string.

**2️⃣ Strings Literais em Arrays (`char v[]`)**
Quando usamos um **vetor (`char v[]`)**, a string literal **é copiada para a pilha (stack)** no momento da inicialização:
```c
char v[] = "hello";
```
📌 **O que acontece?**
- `"hello"` **é copiada** para a pilha(**stack**) da memória local da função.
```c
v[0] = 'h'
v[1] = 'e'
v[2] = 'l'
v[3] = 'l'
v[4] = 'o'
v[5] = '\0'
```
Como os dados foram **copiados**, podemos modificar `v` normalmente:
```c
v[0] = 'H'; // OK! Modifica a string na stack.
```

**🔥 Resumo Final**

| Declaração            | Onde a string fica?         | Pode modificar?      |
| --------------------- | --------------------------- | -------------------- |
| `char *p = "hello";`  | `.rodata` (somente leitura) | ❌ Não pode modificar |
| `char v[] = "hello";` | **Stack** (cópia da string) | ✅ Pode modificar     |
Ou seja, **se for um vetor (`char v[]`), a string literal é copiada para a stack**.

---
## Práticas e Experimentos:⚗️ 

1. O que é um vetor (array)❓🤔
	- Um vetor é uma lista de elementos do **mesmo tipo**.
2. O que é um vetor (array) na **Linguagem C**❓🤔
	- O nome do vetor é um endereço. Na compilação, esse nome é trocado pelo número do endereço da memória, onde o primeiro dado associado será encontrado.
	- Em C, o conceito de vetor é uma cadeia de dados do mesmo tipo na memória.
 
 **Offset ⏩**
- **Offset**: Indica a posição de um dado na memória. Tudo começa do zero em baixo nível.
- **Offset de 1**: Depende do tipo de dado do vetor. Exemplo: se for um inteiro, ele estará a 4 bytes após o zero.
- **Offset de 2**: Vai estar a 8 bytes após o zero.

Ao escrever no vetor, você está manipulando diretamente a memória. 💾
 3. O que é uma String❓🤔
	- Uma string é um vetor de caracteres com um terminador.
	- Sem o terminador, é apenas um conjunto de caracteres.

**Exemplo em C:**
```c
char str[] = "Salve";     // Endereço 
char *pstr = "Simpatia";  // Ponteiro que recebe endereços
```

O asterisco `*` é chamado de **operador de dereferência**. Ele é usado para pegar o valor a partir de um endereço.

3. O que é um ponteiro❓🤔
	- Um ponteiro é uma **variável** especializada em armazenar o **endereço de memória**.
4. O que é o nome de um vetor❓🤔🏷️
	  - O nome de um vetor é o próprio **endereço** do vetor.

**No Assembly 🛠️**
- No Assembly, quem cumpre o papel de variável é o **rótulo**. O rótulo é um indicador de um endereço e é o mais próximo de uma variável. Ele está relacionado ao nome de um vetor.
- Já o **ponteiro** é uma variável de fato, não apenas o nome ou o endereço.

5. Como percorrer os caracteres dentro de uma string❓🤔🔍
```c
// Utilizando um vetor
printf("%c", str[2]);

// Utilizando um ponteiro
printf("%c", *(pstr + 2));
```

6. Onde se localizam uma string literal de um vetor e um ponteiro na memória❓🤔💭
	- **Vetor**: A string é alocada na pilha (**stack**), especificamente na memória local da função `main`.
	- **Ponteiro**: A string é alocada em `.rodata`, uma seção de dados somente leitura.

7. Qual é a diferença entre um ponteiro e um vetor❓🤔⚖️
	- **Ponteiro**: É uma variável que guarda um endereço.
	- **Vetor**: Ele é próprio endereço.

> O vetor é processado na compilação. Na hora da conversão para Assembly, ele perde qualquer atributo de variável. Já o ponteiro é uma variável em si, contendo um endereço na memória.

`Variáveis vs Endereços 🆚`
- Uma **variável** tem várias informações associadas a ela, como nome, endereço e tipo de dado.
- O **endereço** é apenas um valor de memória, sem dados associados.

Como acessar um elemento de uma string literal através de um ponteiro❓🤔🔬
```c
char *pstr = "simpatia";
printf("%c", *(pstr + 3));  // 'p'
```

8. Deslocamento para acessar outro local de memória❓🤔🏃‍♂️
```c
char *pstr = "simpatia";
char *pstr2 = "caderno";

printf("%c", *(pstr2 - 3)); // 'i' 
```

9. Para o exemplo abaixo, o caractere apresentado será  `i` da string "simpatia" ou  `j` da "Laranja"❓🤔🔄
```c
char *pstr = "simpatia";
char *pstr2 = "caderno";

pstr = "Laranja";         

printf("%c", *(pstr2 - 3));
```
Resultado esperado: **'i'** ✅

**Explicação: 🧠**
Inicialmente, podemos achar que a string "simpatia" foi sobrescrita pela string "Laranja". No entanto, a string "Laranja" é alocada em outra área de memória (**.rodata**) e não substitui a string "simpatia". A memória em questão não é a mesma.
```bash
.LC0:
    .string "simpatia"
.LC1:
    .string "caderno"
.LC2:
    .string "Laranja"
```
