import queue
		
resp = ""
num_stars = int(input())

ans = []

while (num_stars != 0):
	num_edges = int(input())
	edges = []
	for i in range(num_edges):
		edges.append(input())
	
	graph = []
	for i in range(num_stars):
		graph.append([])

	for e in edges:
		temp = e.split(" ")
		temp = (int(temp[0]), int(temp[1]))
		
		graph[temp[0]].append(temp[1])
		graph[temp[1]].append(temp[0])

	a = ""
	colors = {}
	colors[0] = 0
	
	que = queue.Queue()
	que.put(0)
	
	while not que.empty():
		current = que.get()
		
		for i in graph[current]:
			try:
				if colors[current] == colors[i]:
					a = "NOT BICOLORABLE"
			except:
				colors[i] = (colors[current] + 1) % 2
				que.put(i)
		
	num_stars = int(input())
	#print()
	
	if a != "NOT BICOLORABLE":
		a = "BICOLORABLE"
	ans.append(a)
	
for a in ans:
	print(a)