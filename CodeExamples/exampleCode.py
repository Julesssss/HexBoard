import random

#############
# Structure
# UI > Board > Territory
# UI > Board > Player

# helper functions
def printTerritories():
    print('')
    print('// Game State')
    for t in territories:
        t.printData()
        print('')

# Represents a tile on the board
class Territory:
    id = 0
    name = "empty"
    owner = 0
    army = 0

    def __init__(self, name, id):
        self.name = name
        self.id = id

    def takeTerritory(self, newOwner):
        self.owner = newOwner
        print(str(self.name) + ' taken by player ' + str(self.owner))

    def reinforce(self, armyCount):
        self.army += armyCount
        print(str(self.name) + ' reinforced by ' + str(self.army))

    def attack(self, attackingPlayer, attackArmyCount):
        print(str(self.name) + ' attacked by player ' + str(attackingPlayer))
        
        if self.army == 0:
            self.takeTerritory(attackingPlayer)
            self.reinforce(attackArmyCount)
        else:
            # TODO calculate fight results
            print('TODO')
        

    def printData(self):
        print('Territory: ' + str(self.name) + ', ID: ' + str(self.id))
        print('owner: ' + str(self.owner))
        print('army count: ' + str(self.army))

# Init Game
print('')
print('// Init game')
territories = []
territories.append(Territory('England', 1))
territories.append(Territory('Portugal', 2))
territories.append(Territory('France', 3))
territories.append(Territory('Germany', 4))

printTerritories()

# Give starting territories 
print('')
print('// Give starting territories')
territories[0].takeTerritory(1)
territories[0].reinforce(10)
print('')
territories[1].takeTerritory(2)
territories[1].reinforce(10)

printTerritories()

# Attack: player.makeAttack()??
print('')
print('// Attack')
territories[0].reinforce(-5) # TODO REMEMBER THAT LIST INDEX != TERRITORY ID
territories[3].attack(1, 5)

printTerritories()