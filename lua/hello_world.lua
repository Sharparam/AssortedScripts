print("What's your name?")
local name = io.read()
if not name or name == "" then name = "No Name" end
print(("Hello, %s!"):format(name))
