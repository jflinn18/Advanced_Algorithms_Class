#Python 3.5
import sys
friends = {}

for line in sys.stdin:
	name = line
	name = name.split(" ") 
	name[1] = int(name[1][:-1]) #Removes the endline from the age
	
	try:
		friends[name[1]] # Sees if there is a list in friends[name[1]]
		friends[name[1]].append(name[0])
	except KeyError as e: # Catches the KeyError exception that may be thrown at line 13
		friends[name[1]] = [name[0]]

for key in friends.keys():
	friends[key] = sorted(friends[key]) # Sorts alphabetically for the people with the same age
sorted_ages = sorted(list(friends.keys()), reverse=True) # Sorts by age

#Prints out the names of the friends
for x in sorted_ages:
	for y in friends[x]:
		print(y)