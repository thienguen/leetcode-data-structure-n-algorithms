filename = "data.txt"

with open(filename) as f:
	content = f.read().split(',')
content = list(map(lambda s : int(s.strip()), content))

sum = 0
min = content[0]
max = content[0]
ave = 0
negcnt = 0
negsum = 0
negave = 0
threecnt = 0
threesum = 0
threeave = 0
for h in content:
	sum = sum + h
	if h < min:
		min = h
	if h > max:
		max = h
	if h < 0:
		negcnt = negcnt + 1
		negsum = negsum + h
	if h % 3 == 0:
		threecnt = threecnt + 1
		threesum = threesum + h
threeave = threesum / len(content)
negave = negsum / len(content)
ave = sum / len(content)

print("Min:", min)
print("Max:", max)
print("Sum:",sum)
print("Average:", ave)
print("NegCount:", negcnt)
print("NegSum:", negsum)
print("NegAve:", negave)
print("ThreeCount:",threecnt)
print("ThreeSum:",threesum)
print("ThreeAverage:",threeave)
