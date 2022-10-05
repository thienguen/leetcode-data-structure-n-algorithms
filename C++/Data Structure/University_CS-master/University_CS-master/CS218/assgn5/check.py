with open("aSides.out") as f:
    aSides = f.read().split(',')
aSides = list(map(lambda s : int(s.strip()), aSides))

with open("pDiags.out") as f:
    pDiags = f.read().split(',')
pDiags = list(map(lambda s : int(s.strip()), pDiags))

with open("qDiags.out") as f:
    qDiags = f.read().split(',')
qDiags = list(map(lambda s : int(s.strip()), qDiags))

areas = []
perims = []
sPerims = []
dmin = 0
dmax = 0
dmid = 0
dsum = 0
dave = 0

for i in range(0,len(aSides)):
    areas.append(pDiags[i] * qDiags[i] // 2)
    perims.append(4 * aSides[i])
    sPerims.append(perims[i] // 2)

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

print("PERIMS")
dmin = 2000000
dmax = dsum = dmid = dave = 0
for h in perims:
    print(int(h), end=',')
    if h > dmax:
        dmax = h
    if h < dmin:
        dmin = h
    dsum = dsum + h
print()
dave = dsum // len(perims)
if len(perims) % 2 == 0:
    dmid = (perims[len(perims)//2] + perims[len(perims)//2-1]) // 2
else:
    dmid = perims[len(perims)//2]
print("dmax: ", dmax)
print("dmin: ", dmin)
print("dsum: ", dsum)
print("dave: ", dave)
print("dmid: ", dmid)

print("SEMIPERIMS")
dmin = 2000000
dmax = dsum = dmid = dave = 0
for h in sPerims:
    print(int(h), end=',')
    if h > dmax:
        dmax = h
    if h < dmin:
        dmin = h
    dsum = dsum + h
print()
dave = dsum // len(sPerims)
if len(sPerims) % 2 == 0:
    dmid = (sPerims[len(sPerims)//2] + sPerims[len(sPerims)//2-1]) // 2
else:
    dmid = sPerims[len(sPerims)//2]
print("dmin: ", dmin)
print("dmax: ", dmax)
print("dsum: ", dsum)
print("dave: ", dave)
print("dmid: ", dmid)
