with open("pDiags.out") as f:
    pDiags = f.read().split(',')
pDiags = list(map(lambda s : int(s.strip()), pDiags))

with open("qDiags.out") as f:
    qDiags = f.read().split(',')
qDiags = list(map(lambda s : int(s.strip()), qDiags))

areas = []
dmax = 0
dsum = 0
dave = 0

for i in range(0, len(pDiags)):
    areas.append((pDiags[i] * qDiags[i]) // 2)

print("AREAS")
for h in areas:
    print(int(h), end=',')
    if h > dmax:
        dmax = h
    dsum = dsum + h
print()
dave = dsum // len(areas)
print("sum: ", dsum)
print("average: ", dave)
