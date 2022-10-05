with open("heights.out") as f:
    heights = f.read().split(',')
heights = list(map(lambda s : int(s.strip()), heights))

with open("aSides.out") as f:
    aSides = f.read().split(',')
aSides = list(map(lambda s : int(s.strip()), aSides))

with open("cSides.out") as f:
    cSides = f.read().split(',')
cSides = list(map(lambda s : int(s.strip()), cSides))

areas = []
perims = []
sPerims = []
dmin = 0
dmax = 0
dmid = 0
dsum = 0
dave = 0

for n in range(0,len(aSides)):
    areas.append(heights[n] * ((aSides[n] + cSides[n]) // 2))

print("AREAS")
dmin = 2000000
for h in areas:
    print(int(h), end=',')
    if h > dmax:
        dmax = h
    if h < dmin:
        dmin = h
    dsum = dsum + h
print()
dave = dsum // len(areas)
if len(areas) % 2 == 0:
    dmid = (areas[len(areas)//2] + areas[len(areas)//2-1]) // 2
else:
    dmid = areas[len(areas)//2]
print("dmax: ", dmax)
print("dmin: ", dmin)
print("dsum: ", dsum)
print("dave: ", dave)
print("dmid: ", dmid)
