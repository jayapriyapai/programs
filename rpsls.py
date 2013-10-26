# Rock-paper-scissors-lizard-Spock game
# Mini Project 1

# The key idea of this program is to equate the strings
# "rock", "paper", "scissors", "lizard", "Spock" to numbers
# as follows:
#
# 0 - rock
# 1 - Spock
# 2 - paper
# 3 - lizard
# 4 - scissors

# to use random function   
import random
    
# helper functions

def number_to_name(number):
    """
    Return string corresponding to number 
    """
    # convert number to a name using if/elif/else
    if number == 0:
        return "rock"
    elif number == 1:
        return "Spock"
    elif number == 2:
        return "paper"
    elif number == 3:
        return "lizard"
    elif number == 4:
        return "scissors"
    else:
        print "Error!"
        return None
    
   
def name_to_number(name):
    """
    Return number corresponding to name
    """
    # convert name to number using if/elif/else
    if name == "rock":
        return 0
    elif name == "Spock":
        return 1
    elif name == "paper":
        return 2
    elif name == "lizard":
        return 3
    elif name == "scissors":
        return 4
    else:
        print name+" is not an item in RPSLS game!"
        return None
  

def rpsls(name): 
    """
    Determines the winner of RPSLS game using helper functions
    name_to_number(name),number_to_name(number) and if/elif/else
    """
    
    # convert name to player_number using name_to_number
    player_number = name_to_number(name)

    if player_number != None:
        # compute random guess for comp_number using random.randrange()
        comp_number = random.randrange(0,5)
        # compute difference of player_number and comp_number modulo five
        winner = (comp_number - player_number) % 5
    
        # use if/elif/else to determine winner
        if winner < 3:
            player_win = False
        else:
            player_win = True
   
        # convert comp_number to name using number_to_name
        computer_guess = number_to_name(comp_number)
    
        # print results
        print "Player chooses "+name
        print "Computer chooses "+computer_guess
    
        if player_win:
            print "Player wins!\n"
        elif comp_number == player_number:
            print "Player and computer tie!\n"
        else:
            print "Computer wins!\n"
   
 
# test code
rpsls("rock")
rpsls("Spock")
rpsls("paper")
rpsls("lizard")
rpsls("scissors")

# test invalid case
rpsls("water")
