def p1(file):
    with open(file) as f:
        lines = f.readlines()
        current_elf = 0
        elfs = []
        for line in lines:
            if line == "\n":
                elfs.append(int(current_elf))
                current_elf = 0
            else:
                current_elf += int(line)
        f.close()
        return(elfs)

def p2(file):
    elfs = p1(file)
    elfs.sort(reverse=True)
    return elfs[0] + elfs[1] + elfs[2]

print(f"p1: {max(p1('calories.txt'))}")
print(f"p2: {p2('calories.txt')}")