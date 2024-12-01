# #first half
ret = 0
l_list = []
r_list = []
with open('day_1_input.txt', 'r') as file:
	for line in file:
		l, r = map(int, line.split())
		l_list.append(l)
		r_list.append(r)

l_list.sort()
r_list.sort()

#more pythonic
ret = sum(abs(r - l) for r, l in zip(l_list, r_list))
#instead of
for l, r in zip(l_list, r_list):
	ret += abs(r - l)
print(ret)


#second half time
	#complexity - O(N^2)
ret = 0
l_list = []
r_list = []
with open('day_1_input.txt', 'r') as file:
	for line in file:
		l, r = map(int, line.split())
		l_list.append(l)
		r_list.append(r)
for l in l_list:
	cnt = 0
	for r in r_list:
		if l == r:
			cnt += 1
	ret += l * cnt
print(ret)

	#complexity - O(N)
ret = 0
count_map = {}

with open('day_1_input.txt', 'r') as file:
	for line in file:
		l, r = map(int, line.split())
		count_map[r] = count_map.get(r, 0) + 1

	for line in file:
		l, _ = map(int, line.split())
		if l in count_map:
			ret += l * count_map[l]
print(ret)
