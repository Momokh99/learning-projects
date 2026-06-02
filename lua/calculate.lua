-- Define the function

local function calculate(a, b)
	-- Calculate sum
	local sum = a + b -- Add a and b

	-- Calculate difference
	local difference = a - b -- Subtract b from a

	-- Calculate product
	local product = a * b -- Multiply a and b

	-- Return all three values
	return sum, difference, product
end

-- Call the function with two numbers and store the results
local sumResult, diffResult, prodResult = calculate(100, 49) -- Pass two numbers

-- Print the results
print(sumResult) -- Print sum
print(diffResult) -- Print difference
print(prodResult) -- Print product
