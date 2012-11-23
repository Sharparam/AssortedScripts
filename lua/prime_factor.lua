local function isPrime(num)
	for i = 2, math.sqrt(num) do
		if num % i == 0 then return false end
	end
	return true
end

local function getNextFactor(num)
	for i = 2, math.sqrt(num) do
		if num % i == 0 then return num / i end
	end
end

local function primeFactors(num)	
	if isPrime(num) then
		return {num}
	else
		local factors = {}
		local current = num
		local lastFactor = 0
		local limit = math.floor(math.sqrt(num))
		repeat
			for i = 2, limit do
				local result = current % i
				if result == 0 then
					factors[#factors + 1] = i
					current = current / i
					break
				end
			end
		until isPrime(current)
		factors[#factors + 1] = current
		table.sort(factors, function(a, b) return a < b end)
		return factors
	end
end

local out = "%s = %d"
local function printFactors(num)
	print(out:format(table.concat(primeFactors(num), " * "), num))
end

repeat
	local num = io.read("*n")
	if num then
		printFactors(num)
	end
until not num

--[[

12

12 / 2 = 6
     ^   ^

2 * 2 * 3 = 12

]]
