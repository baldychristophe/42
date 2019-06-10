#!/usr/bin/python2.7

from read_config import read_config_file
import os
import socket
import subprocess

def get_socket():
	server_address = './server'
	s = socket.socket (socket.AF_UNIX, socket.SOCK_STREAM)
	s.connect(server_address)
	return (s)

def init():
	global c
	c = get_socket()
	global process_list
	process_list = read_config_file("config_file.conf")
