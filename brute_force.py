# brute_force.py
import subprocess

username = "admin"
password_list = ["0000", "123", "admin", "1234", "pass", "root"]

for password in password_list:
    print(f"Trying password: {password}")
    # Run the fake login script with given input
    process = subprocess.Popen(
        ['python', 'fake_login.py'],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    output, _ = process.communicate(f"{username}\n{password}\n")

    if "Login successful!" in output:
        print(f"[+] Password found: {password}")
        break
else:
    print("[-] Password not found.")
