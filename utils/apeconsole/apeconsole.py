#!/bin/env python2

import socket
import sys
from datetime import datetime

UDP_IP = "0.0.0.0"
UDP_PORT = 6600

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.bind((UDP_IP, UDP_PORT))

print_prefix = True;
while True:
    data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
    chunks = data.split('\n')

    current_time = datetime.now().strftime("[%H:%M:%S] ")
    for idx, line in enumerate(chunks):
        line = line.rstrip()
        if idx <= len(chunks) - 2:
            if print_prefix:
                sys.stdout.write(current_time)
            sys.stdout.write(line + "\n")
            print_prefix = True
        elif len(line):
            if print_prefix:
                sys.stdout.write(current_time)
            sys.stdout.write(line)
            sys.stdout.flush()
            print_prefix = False
