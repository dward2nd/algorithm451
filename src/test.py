import os
import traceback

try:
    print(os.popen("cat output.txt"))
except Exception as e:
    print(e)
    print(traceback.format_exc())
