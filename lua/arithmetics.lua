local funcs = {
	add = function(a, b) return a + b end,
	sub = function(a, b) return a - b end,
	div = function(a, b) return a / b end,
	mul = function(a, b) return a * b end,
	pow = function(a, b) return a ^ b end
}

local nums = {
	{'add', 1, 1},
	{'add', 5, 4},
	{'sub', 8, 3},
	{'div', 10.0, 2.0},
	{'mul', 5, 5},
	{'pow', 2, 32}
}

local map = {
	add = '%d + %d',
	sub = '%d - %d',
	div = '%.1f / %.1f',
	mul = '%d * %d',
	pow = '%d ^ %d'
}

local out = "%s = %.1f"

print("Some arithmetics\n")

for _, v in pairs(nums) do
	method = funcs[v[1]]
	text = map[v[1]]
	result = method(v[2], v[3])
	print(out:format(text:format(v[2], v[3]), result))
end
