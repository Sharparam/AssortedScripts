local myText = "Hello, World!"

print(myText)

print("What's your name?")
local name = io.read() or "No Name"

print(("Hello, %s!"):format(name))
