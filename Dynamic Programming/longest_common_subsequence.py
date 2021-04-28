str1 = input("enter string 1 :")
str2 = input("enter string 2 :")
len1=len(str1)
len2=len(str2)

table = list()

for i in range(len2+1):
	if i==0:
		row=[0]*(len1+1)
	else:
		row = [0]*(len1+1)
		for j in range(len1+1):
			if j==0:
				row[j]=0
			else:
				if str1[j-1]==str2[i-1]:
					row[j]=table[i-1][j-1]+1
				else:
					row[j]=max([row[j-1],table[i-1][j]])
	table.append(row)

print("lool-up table :",table)
print("longest common subsequence in the given two strings is :",table[len2][len1])