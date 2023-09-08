import os

files = os.popen("ls").read()
files = files.split("\n")

print(files)

for fi in files:
    if fi.startswith("ft_lst"):
        name = fi[:-2]
        order = f'mv {file} {name}_bonus.c'
        print(order)
        os.system(order)
    print('loop')
