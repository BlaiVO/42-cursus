import os

lst = os.popen("ls -Ra | grep .git").read()
lst = lst.split()

for item in lst:
    item = item[:-1]
    if item.endswith('.git'):
        os.system(f'rm -rf {item}')
        print( "removing: " + item)
