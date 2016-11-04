import pdb, copy, math


def getHull(sheep, right, left, direction):
    temp = []

    for s in sheep:
        if s != right and s != left:
            temp.append(s)
    try:
        slope = ((left[1] - right[1]) / (left[0] - right[0]))
    except:
        #pdb.set_trace()
        slope = float("inf")

    above = []
    below = []

    big_a = 0  # Distance to the farthest point from line
    t_a = None
    little_b = float("inf")  # Distance to the most negative point
    t_b = None
    for s in temp:
        try:
            dist = ccw(right, left, s)
        except:
            pdb.set_trace()
        if dist < 0:
            if dist < little_b:
                little_b = dist
                t_b = s
            below.append(s)
        elif dist > 0:
            if dist > big_a:
                big_a = dist
                t_a = s
            above.append(s)

    global hull

    if direction:
        if len(above) != 0:
            # pdb.set_trace()
            hull.append(t_a)
            getHull(above, right, t_a, True)
            getHull(above, t_a, left, True)

    else:
        if len(below) != 0:
            # pdb.set_trace()
            hull.append(t_b)
            getHull(below, t_b, left, False)
            getHull(below, right, t_b, False)


def ccw(right, left, s):
    return ((right[0] - left[0]) * (s[1] - left[1]) - (s[0] - left[0]) * (right[1] - left[1]))


num_tests = int(raw_input())
ans = []
hull = []
for i in range(num_tests):
    raw_input()
    sheep = []
    num_sheep = int(raw_input())

    for j in range(num_sheep):
        temp = raw_input()
        temp = temp.split(" ")
        sheep.append((int(temp[0]), int(temp[1])))

    if len(sheep) == 0:
        ans.append((0.00, []))
        continue
    if len(sheep) != 1:
        right = (float("-inf"), 0)
        left = (float("inf"), 0)
        top = (0, float("-inf"))
        bot = (0, float("inf"))
        for p in sheep:
            if p[0] < left[0]:
                left = p
            elif p[0] == left[0] and p[1] < left[1]:
                left = p
            if p[0] > right[0]:
                right = p
            elif p[0] == right[0] and p[1] > right[1]:
                right = p
            if p[1] > top[1]:
                top = p
            if p[1] < bot[1]:
                bot = p
        if left == right:
            if bot != top:
                ans.append((float(top[1] - bot[1]) * 2, [sheep.index(bot) + 1, sheep.index(top) + 1]))
                continue
            else:
                ans.append((0.00, [1]))
                continue

        hull.append(left)
        hull.append(right)

        mid = ((left[0] + right[0]) / 2.0, (top[1] + bot[1]) / 2.0)

        getHull(sheep, right, left, True)
        getHull(sheep, right, left, False)

        # -------------------------------------------------------------------
        # This is to get the ccw clockwise ordering
        kevin = []
        for s in hull:
            theta = math.atan2((s[1] - mid[1]), (s[0] - mid[0]))
            kevin.append((s, sheep.index(s) + 1, theta))

        kevin = sorted(kevin, key=lambda kevin: kevin[2])
        # Do stuff to get the counter-clockwise
        # new_kevin = []# The answer that we will push to ans
        start_point = ((float("inf"), float("inf")), 0, 0)
        # pdb.set_trace()
        for s in kevin:
            if s[0][1] < start_point[0][1]:
                start_point = s
            elif s[0][1] == start_point[0][1]:
                if s[0][0] < start_point[0][0]:
                    start_point = s
        starting_index = kevin.index(start_point)
        # pdb.set_trace()

        actual_ans = []
        circ = 0.0
        for ind in range(len(kevin)):
            actual_ans.append(kevin[(ind + starting_index) % len(kevin)][1])
            circ += math.sqrt(pow(kevin[ind][0][0] - kevin[(ind + 1) % len(kevin)][0][0], 2) + pow(
                kevin[ind][0][1] - kevin[(ind + 1) % len(kevin)][0][1], 2))

        # ------------------------------------------------------------------
        ans.append((circ, actual_ans))
        hull = []
    else:
        ans.append((0.00, [1]))

for h in range(len(ans)):
    # print '{:.2f}'.format(float(int(ans[h][0]*100))/100)
    print '{:.2f}'.format(ans[h][0])
    st = ''
    for item in ans[h][1]:
        st += str(item) + ' '
    st = st[:-1]
    # print(item, ' ', end="")
    print st
    if h != len(ans) - 1 and len(ans[h][1]) != 0:
        print