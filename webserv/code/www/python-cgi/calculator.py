#!/usr/bin/env python3

import cgi

# Function to perform addition
def add_numbers(num1, num2):
    try:
        num1 = float(num1)
        num2 = float(num2)
        result = num1 + num2
        return result
    except ValueError:
        return "Please enter valid numbers."

# Print the HTTP header
print("Content-Type: text/html\r")
print("\r")

# Start the HTML content
print("<html>")
print("<head><title>Addition Calculator</title></head>")
print("<body>")

# Get data from the HTML form
form = cgi.FieldStorage()

# Check if the form was submitted with POST method
if "num1" in form and "num2" in form:
    num1 = form["num1"].value
    num2 = form["num2"].value

    # Perform addition and display the result
    result = add_numbers(num1, num2)
    print("<h1>Addition Calculator Result:</h1>")
    print(f"<p>{num1} + {num2} = {result}</p>")

# End the HTML content
print("</body>")
print("</html>")
