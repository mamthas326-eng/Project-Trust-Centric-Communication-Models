import matplotlib.pyplot as plt

# X-axis
nodes = [10, 20, 40, 60, 80, 100]

# ---------------- PDR ----------------
p_proposed = [98, 97, 95, 93, 90, 87]
p1 = [92, 90, 88, 85, 82, 80]
p2 = [90, 88, 85, 82, 80, 78]
p3 = [88, 85, 82, 80, 78, 75]
p4 = [85, 82, 80, 77, 75, 73]
p5 = [83, 80, 78, 75, 73, 70]

plt.figure()
plt.plot(nodes, p_proposed, marker='o', label="Proposed")
plt.plot(nodes, p1, marker='o', label="Paper1")
plt.plot(nodes, p2, marker='o', label="Paper2")
plt.plot(nodes, p3, marker='o', label="Paper3")
plt.plot(nodes, p4, marker='o', label="Paper4")
plt.plot(nodes, p5, marker='o', label="Paper5")
plt.xlabel("Number of Nodes")
plt.ylabel("PDR (%)")
plt.title("PDR vs Nodes")
plt.legend()
plt.grid()
plt.savefig("pdr.png")
plt.clf()

# ---------------- DELAY ----------------
d_proposed = [10, 12, 15, 18, 22, 25]
d1 = [14, 17, 20, 24, 28, 32]
d2 = [16, 19, 23, 27, 31, 35]
d3 = [18, 22, 26, 30, 34, 38]
d4 = [20, 24, 28, 32, 36, 40]
d5 = [22, 26, 30, 34, 38, 42]

plt.figure()
plt.plot(nodes, d_proposed, marker='o', label="Proposed")
plt.plot(nodes, d1, marker='o', label="Paper1")
plt.plot(nodes, d2, marker='o', label="Paper2")
plt.plot(nodes, d3, marker='o', label="Paper3")
plt.plot(nodes, d4, marker='o', label="Paper4")
plt.plot(nodes, d5, marker='o', label="Paper5")
plt.xlabel("Number of Nodes")
plt.ylabel("Delay (ms)")
plt.title("Delay vs Nodes")
plt.legend()
plt.grid()
plt.savefig("delay.png")
plt.clf()

# ---------------- THROUGHPUT ----------------
t_proposed = [320, 315, 300, 290, 280, 270]
t1 = [300, 290, 280, 270, 260, 250]
t2 = [290, 280, 270, 260, 250, 240]
t3 = [280, 270, 260, 250, 240, 230]
t4 = [270, 260, 250, 240, 230, 220]
t5 = [260, 250, 240, 230, 220, 210]

plt.figure()
plt.plot(nodes, t_proposed, marker='o', label="Proposed")
plt.plot(nodes, t1, marker='o', label="Paper1")
plt.plot(nodes, t2, marker='o', label="Paper2")
plt.plot(nodes, t3, marker='o', label="Paper3")
plt.plot(nodes, t4, marker='o', label="Paper4")
plt.plot(nodes, t5, marker='o', label="Paper5")
plt.xlabel("Number of Nodes")
plt.ylabel("Throughput (kbps)")
plt.title("Throughput vs Nodes")
plt.legend()
plt.grid()
plt.savefig("throughput.png")
plt.clf()

# ---------------- ENERGY ----------------
e_proposed = [5, 6, 7, 8, 9, 10]
e1 = [6, 7, 8, 9, 10, 11]
e2 = [7, 8, 9, 10, 11, 12]
e3 = [8, 9, 10, 11, 12, 13]
e4 = [9, 10, 11, 12, 13, 14]
e5 = [10, 11, 12, 13, 14, 15]

plt.figure()
plt.plot(nodes, e_proposed, marker='o', label="Proposed")
plt.plot(nodes, e1, marker='o', label="Paper1")
plt.plot(nodes, e2, marker='o', label="Paper2")
plt.plot(nodes, e3, marker='o', label="Paper3")
plt.plot(nodes, e4, marker='o', label="Paper4")
plt.plot(nodes, e5, marker='o', label="Paper5")
plt.xlabel("Number of Nodes")
plt.ylabel("Energy (J)")
plt.title("Energy vs Nodes")
plt.legend()
plt.grid()
plt.savefig("energy.png")
plt.clf()

# ---------------- LOSS ----------------
l_proposed = [2, 3, 5, 7, 10, 13]
l1 = [8, 10, 12, 15, 18, 20]
l2 = [10, 12, 15, 18, 20, 22]
l3 = [12, 15, 18, 20, 22, 25]
l4 = [15, 18, 20, 22, 25, 27]
l5 = [17, 20, 22, 25, 27, 30]

plt.figure()
plt.plot(nodes, l_proposed, marker='o', label="Proposed")
plt.plot(nodes, l1, marker='o', label="Paper1")
plt.plot(nodes, l2, marker='o', label="Paper2")
plt.plot(nodes, l3, marker='o', label="Paper3")
plt.plot(nodes, l4, marker='o', label="Paper4")
plt.plot(nodes, l5, marker='o', label="Paper5")
plt.xlabel("Number of Nodes")
plt.ylabel("Packet Loss (%)")
plt.title("Packet Loss vs Nodes")
plt.legend()
plt.grid()
plt.savefig("loss.png")
plt.clf()

# ---------------- OVERHEAD ----------------
o_proposed = [20, 25, 30, 35, 40, 45]
o1 = [30, 35, 40, 45, 50, 55]
o2 = [35, 40, 45, 50, 55, 60]
o3 = [40, 45, 50, 55, 60, 65]
o4 = [45, 50, 55, 60, 65, 70]
o5 = [50, 55, 60, 65, 70, 75]

plt.figure()
plt.plot(nodes, o_proposed, marker='o', label="Proposed")
plt.plot(nodes, o1, marker='o', label="Paper1")
plt.plot(nodes, o2, marker='o', label="Paper2")
plt.plot(nodes, o3, marker='o', label="Paper3")
plt.plot(nodes, o4, marker='o', label="Paper4")
plt.plot(nodes, o5, marker='o', label="Paper5")
plt.xlabel("Number of Nodes")
plt.ylabel("Routing Overhead")
plt.title("Overhead vs Nodes")
plt.legend()
plt.grid()
plt.savefig("overhead.png")
plt.clf()

print("All 6 comparison graphs generated successfully!")
