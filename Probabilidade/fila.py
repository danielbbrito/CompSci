import random

def main():
    status_atendente = 0
    clientes_fila = 0
    atendimentos = 0
    tempo_atendente = 0
    relogio = 0
    TC = 1.0
    TA = 0.5
    duracao = 1000
    tempo_proxima_chegada = random.expovariate(1 / TC)
    tempo_termino_atendimento = duracao
    integral_fila = 0
    tempo_anterior = 0

    while relogio <= duracao:
        if tempo_proxima_chegada < tempo_termino_atendimento:
            relogio = tempo_proxima_chegada
            integral_fila += clientes_fila * (relogio - tempo_anterior)
            tempo_anterior = relogio

            if status_atendente == 0:
                status_atendente = 1
                duracao_atendimento = random.expovariate(1 / TA)
                tempo_termino_atendimento = relogio + duracao_atendimento
                tempo_atendente += duracao_atendimento

            else:
                clientes_fila += 1
            
            duracao_chegada = random.expovariate(1 / TC)
            tempo_proxima_chegada = relogio + duracao_chegada
        else:
            relogio = tempo_termino_atendimento
            atendimentos += 1

            if clientes_fila > 0:
                duracao_atendimento = random.expovariate(1 / TA)
                clientes_fila -= 1
                tempo_termino_atendimento = relogio + duracao_atendimento
                tempo_atendente += duracao_atendimento
            else:
                status_atendente = 0
                tempo_termino_atendimento = duracao
                duracao_chegada = random.expovariate(1 / TC)
                tempo_proxima_chegada = relogio + duracao_chegada

    print(f"Clientes atendidos: {atendimentos}")
    print(f"Ocupacao atendente: {tempo_atendente / duracao}")
    print(f"Media clientes em fila: {integral_fila / duracao}")


if __name__ == "__main__":
    main()