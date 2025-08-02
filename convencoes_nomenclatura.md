# Convenções de Nomenclatura para Funções: Exemplos Certos e Errados

Ao nomear funções, é importante seguir boas práticas para garantir legibilidade, clareza e consistência no código. Abaixo estão exemplos comparando nomes de funções **corretos** e **errados**, com base em convenções de boas práticas.

## 1. Funções com Verbos

| ✅ Correto (PT/EN)              | ❌ Errado (PT/EN)               |
|-------------------------------|-------------------------------|
| `calcular_total()` / `calculate_total()` | `total_calculo()` / `total_calculation()` |
| `validar_entrada()` / `validate_input()` | `entrada_valida()` / `valid_input()` |
| `enviar_email()` / `send_email()` | `email_enviado()` / `email_sent()` |

**✔ Dica**: Use **verbos no infinitivo** para indicar ações.

---
## 2. Ação Clara

| ✅ Correto                     | ❌ Errado                      |
|------------------------------|-------------------------------|
| `adicionar_item()` / `add_item()` | `item_adicionado()` / `item_added()` |
| `remover_elemento()` / `remove_element()` | `elemento_removido()` / `element_removed()` |
| `atualizar_dados()` / `update_data()` | `dados_atualizados()` / `data_updated()` |

**✔ Dica**: Evite nomes no particípio ("-ado"/"-ido").

---

## 3. Funções de Verificação

| ✅ Correto                     | ❌ Errado                      |
|------------------------------|-------------------------------|
| `verificar_erro()` / `check_error()` | `erro_verificado()` / `error_checked()` |
| `checar_status()` / `check_status()` | `status_checado()` / `status_checked()` |
| `consultar_usuario()` / `fetch_user()` | `usuario_consultado()` / `user_fetched()` |

---

## 4. Evite Nomes Genéricos

| ✅ Correto                    | ❌ Errado                     |
|-----------------------------|------------------------------|
| `enviar_email()` / `send_email()` | `fazer_acao()` / `do_action()` |
| `salvar_dados()` / `save_data()` | `executar_tarefa()` / `execute_task()` |
| `calcular_media()` / `calculate_average()` | `realizar_calculo()` / `perform_calculation()` |

**✔ Dica**: Seja específico. Evite verbos genéricos como `fazer`, `executar`, `realizar`.

---

## 5. Verbos no Infinitivo

| ✅ Correto                       | ❌ Errado                        |
|--------------------------------|---------------------------------|
| `criar_usuario()` / `create_user()` | `usuario_criado()` / `user_created()` |
| `iniciar_sessao()` / `start_session()` | `sessao_iniciada()` / `session_started()` |
| `finalizar_processo()` / `finish_process()` | `processo_finalizado()` / `process_finished()` |

---
## Conclusão

Ao nomear funções:
- Sempre utilize **verbos no infinitivo** para indicar ações que a função realiza.
- Evite nomes **genéricos** ou **ambiguamente vagos** como `fazer()`, `executar()`, ou `realizar()`.
- Certifique-se de que o nome da função seja **específico** e reflita claramente a ação que está sendo realizada.
- Use **prefixos** ou **sufixos** que indiquem o contexto ou a categoria da função, como `calcular_`, `validar_`, `enviar_`, etc.
---
