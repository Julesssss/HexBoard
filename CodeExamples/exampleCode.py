import random

###########################
#
# Class hierachy: 
#   GameBoard > Territory > Army
# 
# Class Structure:
#   GameBoard: territories[]
#   GameBoard: players[]
#     Territory: id
#     Territory: name
#     Territory: owner
#     Territory: army
#       Army: count
#   BattleUtils
# 

# Helper functions
def printTerritories():
    print('')
    print('// Game State')
    for t in gameBoard.territories:
        t.printData()
        print('')

# Game Board
class GameBoard:
    territories = []
    players = []

    def __init__(self):
        self.territories.append(Territory('England', 1))
        self.territories.append(Territory('Portugal', 2))
        self.territories.append(Territory('France', 3))
        self.territories.append(Territory('Germany', 4))

        self.takeStartingTerritory(self.territories[0], 1)
        self.takeStartingTerritory(self.territories[1], 2)

    def takeStartingTerritory(self, territory, newOwner):
        territory.takeTerritory(newOwner)
        territory.reinforce(10)

    def attack(self, attackTerritory, defendTerritory, attackAmount):
        if defendTerritory.army == 0:
            attackTerritory.reinforce(-5)
            defendTerritory.takeTerritory(attackTerritory.owner)
            defendTerritory.reinforce(attackAmount)
        else:
            # TODO calculate fight results
            print('TODO')


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

    def printData(self):
        print('Territory: ' + str(self.name) + ', ID: ' + str(self.id))
        print('owner: ' + str(self.owner))
        print('army count: ' + str(self.army))


# Init Game
print('')
print('// Init game')
gameBoard = GameBoard()
printTerritories()

# Attack with army
print('')
print('// Attack')
attackTerritory = gameBoard.territories[0]
defendTerritory = gameBoard.territories[3]
gameBoard.attack(attackTerritory, defendTerritory, 5)

printTerritories()

