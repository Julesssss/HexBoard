import random

###########################
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
#   BattleOutcome
# 
###########################

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
        territory.setArmyCount(10)

    def attack(self, attackTerritory, defendTerritory, attackAmount):
        print('player ' + str(attackTerritory.owner) + ' attacking ' + defendTerritory.name)
        attackTerritory.reinforce(-attackAmount)
        battleOutcome = BattleUtils.getBattleOutcome(attackTerritory, defendTerritory, attackAmount, defendTerritory.army)
        print('attackWasSuccessful: ' + str(battleOutcome.didAttackerWin))

        if battleOutcome.didAttackerWin:
            defendTerritory.takeTerritory(attackTerritory.owner)
            defendTerritory.setArmyCount(battleOutcome.attRemainder)
        else:
            defendTerritory.setArmyCount(battleOutcome.defRemainder)


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

    def setArmyCount(self, armyCount):
        self.army = armyCount
        print(str(self.name) + ' army count set to ' + str(armyCount))

    def reinforce(self, armyCount):
        self.army += armyCount
        if (armyCount >= 0):
            print(str(self.name) + ' reinforced by ' + str(armyCount))
        else:
            print(str(self.name) + ' reduced by ' + str(armyCount))

    def printData(self):
        print('Territory: ' + str(self.name) + ', ID: ' + str(self.id))
        print('owner: ' + str(self.owner))
        print('army count: ' + str(self.army))


# Calculate battle outcome
class BattleUtils:

    @staticmethod
    def getBattleOutcome(attackTerritory, defendTerritory, attackAmount, defendAmount):
        if defendTerritory.army == 0:
            return BattleOutcome(True, attackAmount, defendAmount)
        else:
            # TODO: Replace real battle outcome logic
            attackWasSuccessful = 5 > random.randrange(1,10)

            if (attackWasSuccessful):
                return BattleOutcome(True, attackAmount, defendAmount)
            else:
                return BattleOutcome(False, defendAmount, defendAmount)


# Data structure for returning results
class BattleOutcome:
    didAttackerWin = False
    attRemainder = 0
    defRemainder = 0

    def __init__(self, didAttackerWin, attRemainder, defRemainder):
        self.didAttackerWin = didAttackerWin
        self.attRemainder = attRemainder
        self.defRemainder = defRemainder


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

print('// Attack')
attackTerritory = gameBoard.territories[1]
defendTerritory = gameBoard.territories[3]
gameBoard.attack(attackTerritory, defendTerritory, 8)
printTerritories()