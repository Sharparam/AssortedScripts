math.randomseed(os.time())

local number = math.random(1, 10)
local guess
local max_attempts = 5
local attempts = 0

repeat
	
	io.write(("Guess the number (%d): "):format(max_attempts - attempts))
	
	guess = tonumber(io.read())
	
	if not guess then
		print("Your guess was not a valid number")
		attempts = attempts - 1
	elseif guess > number then
		print("Too high!")
	elseif guess < number then
		print("Too ĺow!")
	end
	
	attempts = attempts + 1

until guess == number or attempts >= max_attempts

if guess == number then
	
	print("You guessed correctly in " .. attempts .. " guesses!")

else

	print("You have used up all your attempts and did not find the right number")
	print("The generated number was " .. number)

end
