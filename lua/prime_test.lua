local function isPrime(num)
	for i = 2, math.sqrt(num) do
		if num % i == 0 then return false end
	end
	return true
end

print("Input the limit:")
local limit = io.read("*n")
if not limit then print("Invalid limit") return end

local primes = {}

for i = 1, limit do
	if isPrime(i) then
		primes[#primes + 1] = i
	end
end

print("Between 1 and " .. limit .. ", the following prime numbers were found:")
for _,v in pairs(primes) do
	print(v)
end
