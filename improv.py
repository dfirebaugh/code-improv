import json
from pprint import pprint

print("you can code in every language")
print("You can even use python to code in json!")

with open("input.json") as f:
    output = json.load(f)

pprint(output)
