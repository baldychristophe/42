#!/usr/bin/python2.7

from Class.Application_Class import Application

import builtin
import settings

def com(nw_str):
	length = len(nw_str)
	le = str(length)
	settings.c.send(le + ";" + nw_str)

def prompt():
	data = settings.c.recv(1024)
	index = int(data.find(";"))
	leng = int(data[:index])
	index = index + 1
	leng = index + leng
	ndata = data[index:leng]
	to_read = []
	to_read = ndata.split()
	if (len(to_read) == 0):
		com("empty")
	elif (to_read[0] == "exit"):
		com("exit")
		return (1)
	elif (to_read[0] == "status"):
		builtin.status(to_read)
	elif (to_read[0] == "start"):
		builtin.start(to_read)
	elif (to_read[0] == "stop"):
		builtin.stop(to_read)
	elif (to_read[0] == "reload"):
		process_list = builtin.rload(to_read)
	elif (to_read[0] == "restart"):
		builtin.restart(to_read)
	elif (to_read[0] == "signal"):
		builtin.signal(to_read)
	else:
		com("err;taskmaster: command not found")
	return (0)
