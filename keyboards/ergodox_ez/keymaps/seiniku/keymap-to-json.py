#!/usr/bin/env python3

import re
import json
f = open('keymap.c','r')
with f:
  read_data = f.read()
split_data = re.split(';',read_data)

for item in split_data:
  if 'keymaps[]' in item:
    keymaps = item


keymaps = re.split(r'\[[0-9]{1,2}\] = LAYOUT_ergodox\(',keymaps)
clean_keymaps = []
for item in keymaps:
  if 'KC' in item:
    clean_keymaps.append(item)

layers = []
for thismap in clean_keymaps:
  layer = []
  keys = thismap.split(',')
  for key in keys:
    key = key.strip()
    if (')') in key and ('(') not in key:
      key = key.strip(')')
    if ('}') in key and ('{(}') not in key:
      key = key.strip('}')
    if key is not '':
      layer.append(key)
  layers.append(layer)

keyboarddict = {
      "keyboard": "ergodox_ez",
    "keymap": "defaultish_59dc31a",
    "layout": "LAYOUT_ergodox",
    "layers": layers
}
data = json.dumps(keyboarddict)
print(data)
