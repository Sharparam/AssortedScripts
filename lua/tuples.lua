local cache = setmetatable({}, { __mode = 'v' })

local function tostring(tbl)
    return ('(%s)'):format(table.concat(tbl, ', '))
end

local function exists(tbl, value)
    for i, v in ipairs(tbl) do
        if v == value then return true end
    end
    return false
end

local function unique(tbl)
    local res = {}
    for i, v in ipairs(tbl) do if not exists(res, v) then res[#res + 1] = v end end
    return res
end

local function create(tbl)
    return setmetatable({}, {
        __index = tbl,
        __newindex = function() end,
        __tostring = function()
            return tostring(tbl)
        end,
        __len = function() return #tbl end,
        __eq = function(a, b)
            if #a ~= #b then return false end
            for i, v in ipairs(a) do
                if v ~= b[i] then return false end
            end
            return true
        end,
        __call = function() return unpack(tbl) end
    })
end

local function tuple(...)
    local args = {...}
    local cache_key = tostring(args)
    if cache[cache_key] then return cache[cache_key] end
    cache[cache_key] = create(unique(args))
    return cache[cache_key]
end

return setmetatable({}, { __call = function(_, ...) return tuple(...) end })
