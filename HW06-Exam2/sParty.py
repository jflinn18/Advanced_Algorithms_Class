import pdb


ans = []

while True:
	parties = []
	budget = raw_input().split(" ")
	num_parties = int(budget[1])
	budget = int(budget[0])
	 
	if budget == 0 and num_parties == 0:
		break
	
	for x in range(num_parties):
		party = raw_input().split(" ")
		#pdb.set_trace()
		try:
			parties.append((int(party[0]), int(party[1])))
		except ValueError:
			pdb.set_trace()
		
	#dp = [[0]*budget]*num_parties
	dp = [[(0,0)]*budget]*num_parties
	
	#pdb.set_trace()
	"""
	---Pseudocode---
	for i from 1 to n do:
        for j from 0 to W do:
			if w[i] > j then:
				m[i, j] := m[i-1, j]        <-- This is a 2D vector
			else:
				m[i, j] := max(m[i-1, j], m[i-1, j-w[i]] + v[i])
	"""
	for i in range(1,num_parties):
		for j in range(budget):
			if parties[i][0] > j:    # Maybe flip these things
				dp[i][j] = dp[i-1][j]
			else:
				#dp[i][j] = max(dp[i-1][j], dp[i-1][j-parties[i][0]] + parties[i][1]) #cmp tuples by one value
				#               tuple        tuple                        value
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-parties[i][0]] + parties[i][1])
	
	print dp
	ans.append(dp[-1][-1]) # dp is all 0s
	#pdb.set_trace()
	
	resp = raw_input()
	
for a in ans:
	print a
	