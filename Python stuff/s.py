#!/bin/python3

import socket

HOST = '127.0.0.1'
PORT = 7777

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# AF_INET is ipv4. SOCK_STREAM is a port

s.connect((HOST,PORT))

# You've gotta open the port using netcat on kali.
# >> nc -nvlp 7777