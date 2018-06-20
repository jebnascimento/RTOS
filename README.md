# RTOS

Sistema Operacional em Tempo Real (RTOS)

Objetivo: 
Desenvolvimento de um RTOS para sistema embarcado para gerenciamento de tarefas simples como contador módulo 4, leitura do estado de um botão e leitura de um sensor LDR.

Requisitos seguidos:

Arquitetura:
Uso da plataforma Arduino e da biblioteca freeRTOS.

Algoritmo implementado:
Escalonamento por prioridade. Dada a mesma prioridade, uso do algoritmo de preempção Round Robin (chaveamento circular) para evitar que a tarefa de maior prioridade executada primeiro não permaneça indefinidamente no processador, impedindo que outras tarefas de mesma prioridade sejam executadas.
