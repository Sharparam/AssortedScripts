
-- fibos kommer att innehålla alla fibonaccinummer
local fibos = {}

-- Skapa endast 1477 stycken nummer
local limit = 1477

-- Startvärden
local a = 0
local b = 1
local function fibonacci()

	-- Om vi har räknat ut 1477 st nummer, avsluta funktionen
	if #fibos >= limit then return end

	-- Sätt in värdet på a i vår samling av nummer
	fibos[#fibos + 1] = a

	-- Skriv ut numret i konsolen
	print(a)

	-- Sätt nya värden på a och b
	a, b = b, a + b
	
	-- Fortsätt räkna ut fler nummer (rekursion)
	return fibonacci(a, b)
end

-- Börja generera nummer, möjligt att ändra gränsen med parametern n
local function generate(n)
	limit = n or limit
	fibonacci()
end

generate()

-- Visa ett meddelande
print("Which fibonacci number do you want?")
local n
repeat
	-- Läs in ett nummer från användaren
	n = tonumber(io.read())

	-- Om det är ett giltigt nummer, skriv ut ett fibonacci-tal
	if n then
		print("The #" .. n .. " fibonacci number is " .. (fibos[n] or "undefined"))
	end

	-- Repetera tills användaren skriver in ett ogiltigt nummer
until not n
