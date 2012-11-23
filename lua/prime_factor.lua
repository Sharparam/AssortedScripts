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
			print("calculate " .. current)
			for i = 2, limit do
				print("testing " .. current .. " against " .. i)
				local result = current % i
				if result == 0 then
					print(current .. " % " .. i .. " = 0")
					factors[#factors + 1] = i
					current = current / i
				end
			end
		until isPrime(current)
		factors[#factors + 1] = current
		table.sort(factors, function(a, b) return a < b end)
		return factors
	end
end

local number = 16
local out = "%s = %d"
print(out:format(table.concat(primeFactors(number), " * "), number))

--[[

12

12 / 2 = 6
     ^   ^

2 * 2 * 3 = 12

]]
