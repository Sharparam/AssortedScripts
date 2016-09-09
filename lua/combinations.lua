local CONFIG = {
	{  true,  true,  true, false },
	{  true,  true,  true, false },
	{ false, false, false,  true },
	{ false, false, false,  true },
	{  true,  true,  true, false },
	{  true,  true,  true, false },
	{  true,  true,  true, false }
}

local function tcopy(t) local c = {} for k, v in pairs(t) do c[k] = v end return c end

local function gen(tier, acc)
	tier = tier or 1
	acc = acc or {}
	if tier == #CONFIG + 1 then
		coroutine.yield(acc)
	else
		for i, v in ipairs(CONFIG[tier]) do
			if v then
				cpy = tcopy(acc)
				cpy[#acc + 1] = i % 4
				gen(tier + 1, cpy)
			end
		end
	end
end

local function build()
	local co = coroutine.create(function() gen() end)
	
	return function()
		local _, res = coroutine.resume(co)
		return res
	end
end

for combination in build() do print(table.concat(combination)) end
