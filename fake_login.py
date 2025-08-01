# fake_login.py
correct_username = "admin"
correct_password = "1234"

username = input("Username: ")
password = input("Password: ")

if username == correct_username and password == correct_password:
    print("Login successful!")
else:
    print("Login failed.")
