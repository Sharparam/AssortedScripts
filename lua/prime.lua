local function isPrime(num)
	for i = 2, math.sqrt(num) do
		if num % i == 0 then return false end
	end
	return true
end

while true do
	local num = tonumber(io.read())
	if isPrime(num) then
		print(num .. " is a prime number")
	else
		print(num .. " is not a prime number")
	end
end
