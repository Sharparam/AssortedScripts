local fibos = {}
local limit = 1477

local a = 0
local b = 1
local function fibonacci()
	if #fibos >= limit then return end
	fibos[#fibos + 1] = a
	print(a)

	a, b = b, a + b
	
	return fibonacci(a, b)
end

local function generate(n)
	limit = n or limit
	fibonacci()
end

generate()

print("Which fibonacci number do you want?")
local n
repeat
	n = tonumber(io.read())
	if n then
		print("The #" .. n .. " fibonacci number is " .. (fibos[n] or "undefined"))
	end
until not n
