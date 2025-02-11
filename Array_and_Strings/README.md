# **Vetores, Strings, Ponteiros e Memória 📚**

**Variáveis vs Endereços ⚖️​**

Uma **variável** tem várias informações associadas a ela, como nome, endereço e tipo de dado.

O **endereço** é apenas um valor de memória, sem dados associados.

- O que é um vetor (array)❓🤔
	- Um vetor é uma lista de elementos do **mesmo tipo**.
- O que é um vetor (array) na **Linguagem C**❓🤔
	- Em C, o conceito de vetor é uma cadeia de dados do mesmo tipo na memória.
	- Ao escrever no vetor, você está manipulando diretamente a memória. 💾

- O que é um ponteiro❓🤔
	- Um ponteiro é uma **variável** especializada em armazenar o **endereço de memória**.
- O que é o **nome de um vetor**❓🤔🏷️
	- O nome de um vetor, é o próprio `endereço do vetor.`
	- Na compilação, esse nome é trocado pelo número do endereço da memória, onde o primeiro dado associado será encontrado.

> O vetor é processado na compilação. Na hora da conversão para Assembly, ele perde qualquer atributo de variável.

**Assembly 🛠️**
- No Assembly, quem cumpre o papel de variável é o `rótulo`. O rótulo é um indicador de um endereço e é o mais próximo de uma variável. Ele está relacionado ao nome de um vetor.
- Já o **ponteiro** é uma variável de fato, **não apenas o nome ou o endereço**.

- Qual é a diferença entre um ponteiro e um vetor❓🤔⚖️
	- **Ponteiro**: É uma variável que guarda um endereço.
	- **Vetor**: Ele é próprio endereço.

**✍️Explicação sobre Ponteiros e Vetores**:
- Variáveis representam dados em um endereço.
- Ponteiros são variáveis cujo valor é um endereço.
- Vetores representam **endereços fixos** do início de cadeias de dados do mesmo tipo.
- Subscritos de arrays representam **offsets** dos dados encadeados a partir de um endereço base.

**⏩Conceito de  Offset**
- **Offset**: Indica a posição de um dado na memória. Tudo começa do zero em baixo nível.
- **Offset de 1**: Depende do tipo de dado do vetor. Exemplo: se for um inteiro, ele estará a 4 bytes após o zero.
- **Offset de 2**: Vai estar a 8 bytes após o zero.
```c
    int arr[3] = {5, 10, 15};
    
    // Exibindo o endereço de cada elemento
    printf("Endereço de arr[0]: %p\n", &arr[0]);  // 0xddd70
    printf("Endereço de arr[1]: %p\n", &arr[1]);  // 0xddd74
    printf("Endereço de arr[2]: %p\n", &arr[2]);  // 0xddd78
   
    // Offset +1 e +2
    printf("Endereço de arr[2]: %p\n", &arr[0]+2);  // 0xddd78 +2 está movendo o ponteiro 2 posições para frente
    printf("Endereço de arr[2]: %p\n", &arr[1]+1);  // 0xddd78 +1 está movendo o ponteiro 1 posição para frente
    printf("Endereço de arr[2]: %p\n", &arr[2]);    // 0xddd78
```

❌**Afirmação Errada**:
- A ideia de que "ponteiro aponta" não está correta.

✅​**Afirmação Correta**:
- **Ponteiros não "apontam**".
- Ponteiro é uma variável que `recebe um endereço como valor`.
- Ele não possui um comportamento especial ou diferente de outras variáveis em C.

✅**Exemplo Correto de "Ponteiro Apontando"**
```c
int a = 10; 
int *b = &a;
```
Aqui, `b` recebe o **endereço** de `a`.
- Fazendo a **dereferência** (`*b`), acessamos o valor armazenado em `a`.
- Podemos dizer, metaforicamente, que `*b` "aponta" para `a`, porque conseguimos acessar seu valor indiretamente.

---
🆘 **Expressões constantes de Strings Literais**:
- O que é uma String Literal❓🤔
	- Uma string literal é um vetor de caracteres com um terminador.
	- `Sem o terminador`, é apenas um conjunto de caracteres.

**Expressões constantes de strings** são avaliadas para um endereço no tempo de compilação (assim como arrays) e armazenadas na seção `.rodata`, como podemos ver no código em assembly.

📋​**Seção `.rodata`**:
A `.rodata` (Read-Only Data) é uma seção de memória onde são armazenados dados mutáveis, como:  
- **Strings literais**  
- **Constantes numéricas**  

**Exemplo de Código**:
```c
char *p = "salve";       // Recebe um endereços
char v[] = "banana";     // O próprio Endereço
```

Analisando o código:
- **`*p`** → Variável do tipo ponteiro
- **`"salve"`** → String literal
    - Aqui, `*p` recebe o endereço da string literal `"salve"`, que está na seção `.rodata`.
- **`v[]`** → Vetor (array) de caracteres
- **`"banana"`** → String literal
    - Neste caso, a string `"banana"` é usada para inicializar o vetor `v[]`, e os caracteres são armazenados diretamente na memória alocada para o array.

**Onde as Strings Literais São Armazenadas**❓🤔💭

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

---
## Prática e Experimento:⚗️ 

>O `'*'` asterisco  é chamado de **operador de dereferência**. Ele é usado para pegar o valor a partir de um endereço.

Como percorrer os caracteres dentro de uma string❓🤔🔍
```c
// Utilizando um vetor
printf("%c", str[2]);

// Utilizando um ponteiro
printf("%c", *(pstr + 2));
```

Como acessar um elemento de uma string literal através de um ponteiro❓🤔🔬
```c
char *pstr = "simpatia";
printf("%c", *(pstr + 3));  // 'p'
```

Deslocamento para acessar outro local de memória❓🤔🏃‍♂️
```c
char *pstr = "simpatia";
char *pstr2 = "caderno";

printf("%c", *(pstr2 - 3)); // 'i' 
```

Para o exemplo abaixo, o caractere apresentado será  `i` da string "simpatia" ou  `j` da "Laranja"❓🤔🔄
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

Visualizando ⚙️🔍

```c
int main(){
   // Exemplo de um ponteiro "que aponta"
   char x = 'x';
   char *px = &x;
   x = 'p';
   
   // Ponteiro 'p' aponta 'x', logo, o valor de seu conteúdo sempre será o mesmo de x
   printf("Conteudo: x \t = %c\n", x);  
   printf("Conteudo: px \t = %c\n\n", *px);

   
   // Comprovando que um ponteiro guarda um endereço, não que ele aponta.
   char *pstr = "simpatia";
   char *pstr2 = pstr;

   pstr = "caderno";

   // Ponteiro 'pstr' guarda um valor diferente de 'pstr2'
   printf("Conteudo: pstr \t = %s\n", pstr);  
   printf("Conteudo: pstr2\t = %s\n\n", pstr2);

   printf("Endereco: &pstr \t = %p\n", &pstr);
   printf("Endereco: &pstr2 \t = %p\n\n", &pstr2);

   printf("Conteudo: pstr  \t = %p\n", pstr);
   printf("Conteudo: pstr2 \t = %p\n", pstr2);

   printf("string: simpatia \t = %p\n", &"simpatia");
   printf("string: caderno \t = %p\n", &"caderno");

   printf("Desreferenciar: *pstr \t = %c\n", *pstr);
   printf("Desreferenciar: *pstr2\t = %c\n", *pstr2);

return 0;
}
```

```bash
Conteudo: x      = p
Conteudo: px     = p

Endereco: &pstr          = 0x7fff0c2be700
Endereco: &pstr2         = 0x7fff0c2be708

Conteudo: pstr           = caderno
Conteudo: pstr2          = simpatia

Conteudo: pstr           = 0x5595a6fec00d
Conteudo: pstr2          = 0x5595a6fec004
string: simpatia         = 0x5595a6fec004
string: caderno          = 0x5595a6fec00d
Desreferenciar: *pstr    = c
Desreferenciar: *pstr2   = s
```


| Declaração     | Endereço da Memória | Conteúdo da Memória |
| -------------- | ------------------- | ------------------- |
| char x = 'x';  | 0x7fffc922897f (**A**)  | 'x'                 |
| char *px = &x; | 0x7fffc9228980 (B)  | 0x7fffc922897f (**A**)  |
| x = 'p';       | 0x7fffc922897f (**A**)  | 'p'                 |

| Declaração               | Endereço da Memória | Conteúdo da Memória |
| ------------------------ | ------------------- | ------------------- |
| char *pstr = "simpatia"; | 0x7ffdd7ce1f00 (**C**) | 0x55f5e200b004  (**1**) |
| char *pstr2 = pstr;      | 0x7ffdd7ce1f08 (D)  | 0x55f5e200b004  (**1**) |
| pstr = "caderno";        | 0x7ffdd7ce1f00 (**C**)  | 0x5595a6fec00d (2)|

| Declaração  | Endereço da Memória | Conteúdo da Memória |
| ----------- | ------------------- | ------------------- |
| "simpatia"; | 0x55f5e200b004 (**1**)| 's'               |
| "caderno";  | 0x55f5e200b00d (2) | 'c'                  |
