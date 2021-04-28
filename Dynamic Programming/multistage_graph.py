graph = {}

n = int(input("enter no of nodes in graph : "))

table = [0]*n

for i in range(1,n):
	list1 = list()
	print("how many nodes are connected to node" , i , ":")
	node_count=int(input())
	for j in range(node_count):
		list2 = [0,0]
		list2[0]=int(input("enter node : "))
		list2[1]=int(input("enter weight : "))
		list1.append(list2)
	graph[i]=list1

print("entered graph is :" , graph)

for i in range(n,0,-1):
	if i==n:
		table[i-1]=0
	else:
		sp = list()
		l=len(graph[i])
		for j in range(l):
			sp.append(graph[i][j][1]+table[graph[i][j][0]-1])
		table[i-1]=min(sp)

print("look-up table :" , table)

print("shortest distance from node 1 to" , n , "is" , table[0] )