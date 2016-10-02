nx = 10
nt = 20

# mx[t,x]

# t0
# x,y

# t1
# x,y

# ...

mx = [[0.0 for i in range(nx)] for j in range(nt)]
print "sorok szama", len(mx)


for i in range(nx):
    mx[0][i] = float(i)
    
print mx

for t in range(1,nt):
    for x in range(nx):
        mx[t][x] = (mx[t-1][x])/(t/2.0+1)

dx = 1.0/nx

with open("test.dat", "w") as f:
    for t in range(nt):
        for x in range (nx):
            f.write("%s\t%s\n" % (dx*x, mx[t][x]))
        if t < nt - 1:
            f.write("\n\n")

