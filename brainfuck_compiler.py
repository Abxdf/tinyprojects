#chr takes a number as an input and returns corresponding ASCII value character
#ord takes a character and returns ascii number as the input
#storing ascii characters in cells
#character is what is stored in cells
cells=[]
numofcells=30000
index=0
def initialise():
	for i in xrange(numofcells):
		cells.append(chr(0))#store ascii codes


#start of function
def brainfuck(instruction):
	printvalue = ""
	initialise()	
	global index
	iterator=0
	while(iterator < len(instruction)):
		# + : Increments the value at the current cell by one.
		if instruction[iterator]=='+': 
			cells[index]=chr(ord(cells[index])+1)
			iterator+=1
		# - : Decrements the value at the current cell by one.
		elif instruction[iterator]=='-': 
			cells[index]=chr(ord(cells[index])-1)
			iterator+=1
		# < : Moves the data pointer to the next cell (cell on the left)
		elif instruction[iterator]=='<': 
			index-=1
			iterator+=1
		# > : Moves the data pointer to the previous cell (cell on the right).
		elif instruction[iterator]=='>': 
			index+=1;
			iterator+=1
		# . : Prints the ASCII value at the current cell (i.e. 65 = 'A')
		elif instruction[iterator]=='.':  
			printvalue+=cells[index]
			iterator+=1
		# , : Reads a single input character into the current cell.
		elif instruction[iterator]==',': 
			cells[index]=chr(int(raw_input()))
			iterator+=1
		#[ : If the value at the current cell is zero, skips to the corresponding ] .
	    #    Otherwise, move to the next instruction.'''

		elif instruction[iterator]=='[':
			#print iterator, ord(cells[index])
			if cells[index]==chr(0):
				iterator+=1
				count=0
				while(True):
					if(instruction[iterator]=='['):
						count+=1
					elif(instruction[iterator]==']'):
						count-=1
					if count == -1:
						break
					#print instruction[iterator],
					iterator+=1;
					if iterator>=len(instruction):
						print "Symbols are not paired!!!"
						return;
			else:
				iterator+=1
			# ] : If the value at the current cell is zero, move to the next instruction.
			#     Otherwise, move backwards in the instructions to the corresponding [ .
		elif instruction[iterator]==']':
			#print iterator,ord(cells[index])
			if cells[index]==chr(0):
				iterator+=1
			else:
				count=0
				iterator-=1
				while(True):
					if(instruction[iterator]=='['):
						count-=1
					elif(instruction[iterator]==']'):
						count+=1
					if count == -1:
						break;
					iterator-=1
					if iterator<0:
						print "symbols are not paired!!!"
						return;
		else:
			iterator+=1
	print printvalue
#end of function

def main():
	inputstring = raw_input(">").strip()
	brainfuck(inputstring),

if __name__ == '__main__':
	main()
