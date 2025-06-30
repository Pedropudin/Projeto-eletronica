# Fonte-tensaoAjustavel
Trabalho 1 da matéria "SSC0180 Eletronica para Computacao", criação de uma fonte com tensão ajustável

## Especificações
O trabalho exige que os alunos montem um circuito eletrônico que recebe na entrada uma tensão alta e alternada, mais especificante de uma tomada, o que no brasil consiste de 127V e 60Hz. O circuito deve converter isso para uma tensão menor e contínua.

Além disso, é necessário utilizar um potênciometro de forma que seja possível ajustar a tensão, sendo o máximo de aproximadamente 12V e o mínimo 3V.

## Componentes
Para montar o circuito em questão, foram utilizados os seguintes componentes:

| Quantidade | Componente               | Valor R$            | Função                                                                    |
| ---------- | ------------------------ | ------------------- | ------------------------------------------------------------------------- |
| 1          | Transformador            | Em torno de R$50,00 | Reduzir a tensão                                                          |
| 1          | Ponte de Diodo           | R$3,90              | Converte a parte negativo do sinal senoidal para positiva (ou vice-versa) |
| 1          | Capacitor elco - 1000µF  | R$2,00              | Armazena carga que pode ser liberada posteriormente                       |
| 1          | LED 5mm Vermelho         | R$0,50              | Brilha quando recebe energia                                              |
| 1          | Diodo Zenner 13V         | R$0,50              | Funciona como um diodo, porém com uma corrente pequena máxima pequena     |
| 1          | Potenciômetro - 10kΩ, 1W | R$7,00              | Exerce uma resistência variável que é controlada por um botão giratório   |
| 1          | Resistor 3kΩ - Carvão    | R$0,07              | Possui resistência determinada                                            |
| 1          | Resistor 2.2kΩ - Carvão  | R$0,07              | Possui resistência determinada                                            |
| 1          | Resistor 3.3kΩ - Carvão  | R$0,07              | Possui resistência determinada                                            |
| 1          | Resistor 510Ω - Carvão   | R$0,07              | Possui resistência determinada                                            |
| 1          | Resistor 100Ω - Metal    | R$1,90              | Possui resistência determinada                                            |
| 1          | Resistor 120Ω - Metal    | R$1,90              | Possui resistência determinada                                            |
| 1          | Transistor 2N2222A NPN   | R$2,60              | Amplifica e seleciona se um sinal passa por ele ou não                    |
| 1          | Protoboard 400 furos     | R$21,70             | Possui ligações que permite que a conexão entre os componentes            |
| 5          | Jumper Macho-Macho       | R$0,70              | Liga dois pontos da protoboard                                            |
| **Total**  | R$95,78                  |

Observações: 
- O transformador foi fornecido pelo professor, porém é possível utilizar o transformador de qualquer eletrônico antigo, bastando ajustar as resistências para a razão do transformador em questão.
- Para reduzir custos poderiam ser utilizados 4 diodos no lugar da ponte, porém foi escolhido não fazer isso pois como o circuito foi montado em uma protoboard as conexões não são perfeitas, assim muitas conexões podem aumentar a resistência interna do circuito, fazendo com os resistores tivessem que ser ajustados e causando possíveis problemas no circuito por conexões mal feitas.
- Novamente para reduzir custos e melhorar a aparência do circuito alguns jumpers foram substituídos por pequenos fios de metal (recortados das pernas dos resistores que são os componentes mais baratos), diminuindo a poluição visual no circuito e economizando 95% do preço de cada jumper substituído (pois um resistor substitui 2 jumpers).

## Funcionamento do Circuito

## Imagem do Circuito

## Vídeo do Circuito Funcionando

## Imagem esquemática da PCB