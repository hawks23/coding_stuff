import hashlib

username_trial = b"GOUGH"

print(str(hashlib.sha256(username_trial).hexdigest()[4])+str(hashlib.sha256(username_trial).hexdigest()[5])+str(hashlib.sha256(username_trial).hexdigest()[3])+str(hashlib.sha256(username_trial).hexdigest()[6])+str(hashlib.sha256(username_trial).hexdigest()[2])+str(hashlib.sha256(username_trial).hexdigest()[7])+str(hashlib.sha256(username_trial).hexdigest()[1])+hashlib.sha256(username_trial).hexdigest()[8])

# 4,5,3,6,2,7,1,8
# picoCTF{1n_7h3_|<3y_of_f911a486