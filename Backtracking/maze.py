
def move_x(option,x):
	if option==0:
		return x-1 #up
	elif option==1:
		return x   #right
	elif option==2:
		return x+1 #down
	elif option==3:
		return x   #left

def move_y(option,y):
	if option==0:
		return y   #up
	elif option==1:
		return y+1 #right
	elif option==2:
		return y   #down
	elif option==3:
		return y-1 #left

def path_finder(x,y,option,xf,yf,maze):
	while option<4 :
		if maze[move_x(option,x)][move_y(option,y)]=='#':
			option+=1
		elif maze[move_x(option,x)][move_y(option,y)]=='$':
			option+=1
		else:
			maze[move_x(option,x)][move_y(option,y)]='$'
			if move_x(option,x)==xf and move_y(option,y)==yf:
				return 1
			else:
				res=path_finder(move_x(option,x),move_y(option,y),0,xf,yf,maze)
				if res==1:
					return 1
				else:
					maze[x][y]='.'
					option+=1
	return 0



maze = list()
n=int(input("enter n : "))

for i in range(n):
	row = list()
	print("enter row" , i+1)
	for j in range(n):
		
		row.append(input())
	maze.append(row)

xi=int(input("enter initial x-cordinate : "))
yi=int(input("enter initial y-cordinate : "))
xf=int(input("enter final x-cordinate : "))
yf=int(input("enter final y-cordinate : "))

maze[xi][yi]='$'

if path_finder(xi,yi,0,xf,yf,maze)==1:
	print("possible solution is : ")
	for i in range(n):
		print(maze[i])
else:
	print("no possible solution")

ans_matrix