import math

tri = []

num_inupts = int(input())

for i in range(0, num_inupts):
	tri.append(int(input()))
	
for i in tri:
	t = math.ceil((-1+math.sqrt(1+8*i))/2)
	upper = t*((t+1)/2)
	if t % 2 == 0:
		print("TERM ", i, " IS ", int((t - (upper - i))), "/", int((t+1)-(t - (upper - i))), sep="")
	else:
		print("TERM ", i, " IS ", int((t+1)-(t - (upper - i))), "/", int((t - (upper - i))), sep="")