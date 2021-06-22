import re
import string

def CreateFrequencyFile():
    # Create a groceryList.
    groceryList = CreateGroceryList()

    # Create a writable file.
    writeFile = open("frequency.dat", "w")

    # Write information from groceryList to the file.
    for item in groceryList:
        writeFile.write("{} {}\n".format(item, groceryList[item]))

    # CLose file writer.
    writeFile.close()

def GetItemAmount(item):
    # Creates a groceryList.
    groceryList = CreateGroceryList()
    
    # Sends back the item amount in the list.
    if item in groceryList:
        return groceryList[item]
    else:
        # If the item is not in the list then returns default int.
        return 100

def PrintStoreList():
    # Creates a groceryList.
    groceryList = CreateGroceryList()

    # Prints out the groceryList with the item name and its amount.
    for item in groceryList:
        print("{} - {}".format(item, groceryList[item]))

    return 100

def CreateGroceryList():
    # Creates a reading file of the text file name.
    readFile = open("CS210_Project_Three_Input_File.txt", "r")

    groceryList = {}

    # Goes through all lines in the file.
    for line in readFile:
        # Cleans the line of whitespace.
        line = line.strip()
        # Adds the item to the list and if it already exist then it increments its value.
        if (line in groceryList):
            groceryList[line] += 1
        else:
            groceryList[line] = 1

    # Closes the file reader.
    readFile.close()
    return groceryList