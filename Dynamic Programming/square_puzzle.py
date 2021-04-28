def ts(n):
	sum=0
	for i in range(1,n+1):
		sum+=i*i
	return sum

count1=0

matrix = list()

ans_table = list()

reduction = list()

min_distance = list()

n=int(input("how many rows and columns are there in matrix : "))

total_square = ts(n)

#matrix entered by user
for i in range(n):
	row = list()
	print("enter row " , i+1)
	for j in range(n):
		row.append(input())
	matrix.append(row)

#min distance matrix
for i in range(n):
	row = [0]*n
	if i==0:
		for j in range(n):
			if matrix[0][j]=='*':
				row[j]=0
			else:
				row[j]=-1

	else:
		for j in range(n):
			if j==0:
				if matrix[i][0]=='*':
					row[j]=0
				else:
					row[j]=-1

			else:
				if matrix[i][j]=='*':
					row[j]=0
				else:
					if min_distance[i-1][j]==-1 and min_distance[i-1][j-1]==-1 and row[j-1]==-1:
						row[j]=-1
					else:
						temp=[min_distance[i-1][j] , min_distance[i-1][j-1] , row[j-1]]
						row[j]=min([x for x in temp if x>=0])+1

	min_distance.append(row)

#reduction matrix
for i in range(n):
	row = [0]*n
	if i==0:
		for j in range(n):
			if matrix[0][j]=='*':
				row[j]=1
			else:
				row[j]=0
	else:
		for j in range(n):
			if j==0:
				if matrix[i][0]=='*':
					row[j]=1
				else:
					row[j]=0

			else:
				if min_distance[i][j]==-1:
					row[j]=0
				else:
					row[j]=min(i+1,j+1)-min_distance[i][j]
	reduction.append(row)

#final answer matrix
for i in range(n):
	row = [0]*n
	if i==0:
		count=0
		for j in range(n):
			if matrix[0][j]=='*':
				count+=1
			row[j]=count
	else:
		for j in range(n):
			if j==0:
				if matrix[i][0]=='*':
					count1+=1
				row[j]=count1
			else:
				row[j]=row[j-1]+ans_table[i-1][j]-ans_table[i-1][j-1]+reduction[i][j]
	ans_table.append(row)

answer=total_square-ans_table[n-1][n-1]

print("minimum distance table : " , min_distance)
print("reduction table : " , reduction)
print("final answer table : " , ans_table)

print("total no. of squares not containing star-boxes are : " , total_square , "-" , ans_table[n-1][n-1] , " = " , answer)


			    
