
#our goal is to make both string same in minimum no of operations (add,delete char at a time , we cannot use swapping)

str1=input("enter string 1 :")
str2=input("enter string 2 :")

len1=len(str1)
len2=len(str2)

table=list()

for i in range(len2+1):
	row=[0]*(len1+1)
	if i==0:
		count=0
		for j in range(len1+1):
			row[j]=count
			count+=1
	else:
		for j in range(len1+1):
			if j==0:
				row[j]=i
			else:
				if str1[j-1]==str2[i-1]:
					row[j]=table[i-1][j-1]
				else:
					row[j]=min([row[j-1],table[i-1][j-1],table[i-1][j]])+1
	table.append(row)

print("look-up table :",table)
print("minimum operation to match both string are :" , table[len2][len1])

