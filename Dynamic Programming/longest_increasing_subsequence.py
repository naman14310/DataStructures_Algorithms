def count(arr,lis):
	arr1=list()
	for j in range(1,len(arr)):
		if arr[j]>arr[0]:
			arr1.append(lis[j-1])
		else:
			arr1.append(0)

	return max(arr1)


arr = list()

n = int(input("how many no. you want to enter : "))

lis = [0]*n

print("enter numbers : ")

for i in range(n):
	arr.append(int(input()))

for i in range(n-1 , -1 , -1):
	if(i==n-1):
		lis[i]=1

	else:
		lis[i]=count(arr[i:],lis[i+1:])+1

print("length of longest increasing subsequence will be :" , max(lis))
