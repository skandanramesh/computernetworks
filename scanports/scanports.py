import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

target = input('What you want to scan?: ')
target_ip = socket.gethostbyname(target)
print('Starting scan on host:', target_ip)

def port_scan(port):
	try:
		s.connect((target_ip, port))
		return True
	except:
		return False

for port in range(65536):
	if port_scan(port):
		print(f'port {port} is open')
	# else:
	# 	print(f'port {port} is closed')
