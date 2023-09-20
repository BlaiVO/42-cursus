import sys
import os

os.system(f'python3 pyviz.py `ruby -e "puts ({sys.argv[1]}..{sys.argv[2]}).to_a.shuffle.join(\' \')"`')