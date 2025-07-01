import random;

def playRound(values, level, position):
    if(position == 0):
        print("Adiciona número e mostra ordem")
        values.append(random.randint(0,4))
        [print(x) for x in values]
        
    inp = int(input("Val: "))

    return inp == values[position]

game_over = False
level = 1
position = 0
values = []

while(True):
    if(game_over):
        print("PERDEU")
        level = 1
        position = 0
        values = []
        game_over = False
    
    if(level == 1):
        print("Começando agora")

    if(playRound(values, level, position)):
        if(position == (level - 1)):
            position = 0
            level += 1
        else:
            position += 1
    else:
        game_over = True

