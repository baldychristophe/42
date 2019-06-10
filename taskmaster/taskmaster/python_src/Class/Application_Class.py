import multiprocessing
from threading import Thread
import subprocess
import time
import os
import signal
import sys
import threading
from multiprocessing import Process

class Application:
	def __init__(self, name):
		self.data = {'name':name}
		self.pid = None
		self.time = None
		self.ret = None
		self.proc = None
		self.curstatus = "Stopped"

	def print_info(self):
		print "Applications:"
		print "name: " + self.data['name']
		for config in self.data:
			if (config == "name"):
				continue
			elif isinstance(self.data[config], dict):
				to_write = "\t" + config + ": "
				for k in self.data[config]:
					to_write += k + ":" + self.data[config][k] + ", "
				print to_write[:-2]
			else:
				print "\t" + config + ": " + self.data[config]

	def monitoring_ft(self, fd):
		flag = 1
		while (flag == 1):
			if (self.proc.poll() <> None):
				self.curstatus = "Exited"
				flag = 0
			elif (time.time() - self.time > int(self.data["starttime"])
					and self.curstatus == "Starting"):
				self.curstatus = "Running"
			elif (self.pid == None):
				flag = 0
			else:
				time.sleep(0.2)
		self.pid = None
		self.ret = self.proc.wait()
		fd.close()
		self.ret_handler()
			
	def start_app(self):
		fd = open("/dev/null", 'w')
		self.curstatus = "Starting"
		i = 1
		while (i > 0 and i <= int(self.data["startretries"])): #boucle pour gerer les startretries
			try:
				self.proc = subprocess.Popen(self.data["cmd"][1:-1].split(), stdout=fd, stderr=fd)
			except OSError:
				print "Error: %s failed to start (%d)" % (self.data["name"], i)
				i += 1
			else:
				i = 0
				self.time = time.time()
				self.pid = self.proc.pid
				t = Thread(target=self.monitoring_ft, args=(fd,))
				t.daemon = True
				t.start()

	def ret_handler(self): #pour gerer la valeur de retour du subprocess
		if (self.data["autorestart"] == "always"):
			self.start_app()
		elif (self.data["autorestart"] == "unexpected"):
			exit = self.data["exitcodes"].split(',')
			if (self.ret not in exit):
				self.start_app()
	
	def graceful_kill(self):
		self.proc.kill()
		self.pid = None
	
	def get_uptime(self):
		if (self.pid < 0):
			return ("None")
		tmp = time.time() - self.time
		s = "%0d:%02d:%02d" % (tmp / 3600, tmp / 60, tmp % 60)
		return (s)
