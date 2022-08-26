import socket
import threading
my_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
broadcast_list = []
PORT = 8000
ADDRESS = "0.0.0.0"
my_socket.bind((ADDRESS, PORT))
def broadcast(message):
    for client in broadcast_list:
        try:
            client.send(message.encode())
        except:
            broadcast_list.remove(client)
            print(f"Client removed : {client}")
def listen_thread(client, client_address):
    while True:
        message = client.recv(1024).decode()
        if message:
            print(f"Received message : {message}")
            broadcast(message)
        else:
            print(f"client has been disconnected : {client_address[0]}")
            broadcast(f"{client_address[0]} has left the chat")
            return
def accept_loop():
    while True:
        my_socket.listen()
        client, client_address = my_socket.accept()
        broadcast_list.append(client)
        client_thread = threading.Thread( target=listen_thread, args=(client,client_address) )
        client_thread.start()
accept_loop()
