def box_under_attack(row,col,matrix,n):
	for i in range(row):
		if matrix[i][col]=='Q':
			return 1
	
	j=1 
	ld=col
	while ld>0:
		if matrix[row-j][col-j]=='Q':
			return 1
		j+=1
		ld-=1

	k=1
	rd=col
	while rd<n-1:
		if matrix[row-k][col+k]=='Q':
			return 1
		k+=1
		rd+=1

	return 0

def nQueen(row,col,n,matrix):
	col=0
	while col<n:
		if box_under_attack(row,col,matrix,n)==1:
			col+=1
		else:
			matrix[row][col]='Q'
			if row==n-1:
				return 1
			else:
				result=nQueen(row+1,0,n,matrix)
				if result==1:
					return 1
				else:
					matrix[row][col]=0
					col+=1
	return 0


n=int(input("enter n : "))

matrix = list()

for i in range(n):
	row=[0]*n
	matrix.append(row)

if nQueen(0,0,n,matrix)==1:
	print("possible solution is :")
	for i in range(n):
		print(matrix[i])
else:
	print("no possible solution")

