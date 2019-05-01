N,M = map(int, raw_input().split())
Map = {}
for _ in xrange(N):
    p,b = map(int, raw_input().split())
    if b in Map:
        Map[b] = max(p, Map[b])
    else:
        Map[b] = p

print sum(Map.itervalues())