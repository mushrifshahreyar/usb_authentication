import os
import getpass
admin_pass = "admin"

t = 0

passw = True

while(t < 3):

    admin = getpass.getpass("Enter the admin password :\t")
    if(admin != admin_pass):
        passw = True
        print("Password not correct")
        print(str(2-t) + " Attempts remaining")
        t += 1
    else:
        passw = False
        break

if(passw):
    exit(0)

username = os.getlogin()
path = "/run/media/"
path = path + username
flag = False

while(1):
    pen_name = input("Enter the name of Pen drive :\t")
    files = os.listdir(path)
    if(len(files) == 0):
        print("No Pendrive connected")
        exit(0)
    for files in os.listdir(path):
        if(files == pen_name):
            print("Found")
            flag = True
            break
        else:    
            print("USB device not found")
            user_in = input("Exit (Y/N)  :\t")
            if(user_in == 'y' or user_in == 'Y'):
                exit(0)
    if(flag):
        break

path = path + "/" + pen_name
file_path = path + "/" + ".pass"
f = open(file_path,"w")

while(1):
    paswd = getpass.getpass("Enter the Password :\t")
    paswd_again = getpass.getpass("Enter the Password Again:\t")
    if(paswd == paswd_again):
        break
    else:
        print("Password did not match...\nPlease enter again\n")

# Encrypting Password
Str = "asdkSKD@&ad12313324687KJHsdk&^8912kjasndjasnja*@^n1223" + paswd + "!@87163AYSGDsdkjfhsfwieufh1318318237"
f.write(Str)

print("*******Password Successfully set*******")
f.close()
    



