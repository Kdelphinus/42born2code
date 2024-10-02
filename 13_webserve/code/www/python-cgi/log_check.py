#!/usr/bin/env python3

import os
import http.cookies
import pickle
import sys
import urllib.parse

# Get the directory where the script is located
script_directory = os.path.dirname(os.path.abspath(__file__))

# Set the working directory to the script's directory
os.chdir(script_directory)

# Function to load the session dictionary from a file
def load_session():
    try:
        with open('./session.pickle', 'rb') as f:
            return pickle.load(f)
    except FileNotFoundError:
        return {}

# Function to save the session dictionary to a file
def save_session(session_dict):
    with open('./session.pickle', 'wb') as f:
        pickle.dump(session_dict, f)

# Read POST data from stdin
post_data = sys.stdin.read()
parsed_data = urllib.parse.parse_qs(post_data)

# Get the received cookie from the client
cookie = http.cookies.SimpleCookie()

# Check if the "HTTP_COOKIE" header is present in the request
if "HTTP_COOKIE" in os.environ:
    cookie.load(os.environ["HTTP_COOKIE"])

# Load the session dictionary from the file
session_dict = load_session()

# Get the value of the received cookie
received_cookie = parsed_data.get("cookie", [None])[0]

# Set the response content type to plain text
print("Content-type: text/plain\r")

if received_cookie is not None:
    # The user has sent a cookie, check if it exists in the session dictionary
    username = session_dict.get(received_cookie)
    if username is not None:
        # If the cookie exists in the dictionary, return the username
        print("\r")
        print(username, end="")
    else:
        # If the cookie doesn't exist in the dictionary, add it with a null value
        session_dict[received_cookie] = "null"
        save_session(session_dict)
        print("\r")
        print("null", end="")
else:
    # The user hasn't sent a cookie, generate a new one
    new_cookie = os.urandom(16).hex()
    session_dict[new_cookie] = "null"
    save_session(session_dict)
    print("Set-Cookie: cookie=" + new_cookie + "; path=/;\r")
    print("\r")
    print("null", end="")