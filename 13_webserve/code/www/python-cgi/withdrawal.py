#!/usr/bin/env python3

import os
import pickle
import sys

# Get the directory where the script is located
script_directory = os.path.dirname(os.path.abspath(__file__))

# Set the working directory to the script's directory
os.chdir(script_directory)

# Function to load the session dictionary from a file
def load_session():
    try:
        with open('session.pickle', 'rb') as f:
            return pickle.load(f)
    except FileNotFoundError:
        return {}

# Function to save the session dictionary to a file
def save_session(session_dict):
    with open('session.pickle', 'wb') as f:
        pickle.dump(session_dict, f)

# Read POST data from stdin
post_data = sys.stdin.read()

# Parse the POST data to extract the received cookie
post_params = post_data.split('&')
received_cookie = None

for param in post_params:
    key, value = param.split('=')
    if key == 'cookie':
        received_cookie = value

# Set the response content type to plain text
print("Content-type: text/plain\r")

if received_cookie is not None:
    # Load the session dictionary from the file
    session_dict = load_session()
    
    # Check if the cookie exists in the session dictionary
    if received_cookie in session_dict:
        # Remove the cookie from the session dictionary
        del session_dict[received_cookie]
        save_session(session_dict)  # Save the updated session dictionary
        print("\r")
        print("Withdrawal successful")
    else:
        print("\r")
        print("Error: Invalid cookie")
else:
    print("\r")
    print("Error: No cookie received")