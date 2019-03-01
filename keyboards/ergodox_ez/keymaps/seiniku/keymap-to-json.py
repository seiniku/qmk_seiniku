import re
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

print(clean_keymaps[1])
