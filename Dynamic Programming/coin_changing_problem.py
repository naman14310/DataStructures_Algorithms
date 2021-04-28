n=int(input("enter no : "))
c=int(input("upto how much value of coins , u want to use in combination : "))

matrix = list()

for i in range(1,c+1):
	row=[0]*(n+1)
	if i==1:
		row=[1]*(n+1)
	else:
		for j in range(n+1):
			if j==0:
				row[0]=1
			else:
				if i>j:
					row[j]=matrix[i-1][j]
				else:
					sum=0
					for k in range(int(j/i)+1):
						sum+=matrix[i-1][j-(i*k)]
					row[j]=sum
	matrix.append(row)

print("look-up table : " , matrix)

print("total no. of combination formed : " , matrix[c][n])
