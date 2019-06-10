#!/usr/bin/python2.7

import time
import signal

import settings
import prompt
import read_config

def status(to_read):
	nw_str = "status;"
	for p in settings.process_list:
		if ((len(to_read) == 1 and p.pid > 0) or p.data['name'] in to_read or "all" in to_read):
			nw_str +=  p.data['name'] + "." + p.curstatus + "." + str(p.pid) + "." + p.get_uptime() + ";"
	prompt.com(nw_str)

def start(to_read):
	if (len(to_read) == 1):
		prompt.com("err;start requires a process name")
		return
	nw_str = "started;"
	if ("all" in to_read):
		for p in settings.process_list:
			if (p.curstatus != "running" and p.curstatus != "starting"):
				p.start_app()
				nw_str += p.data['name'] + ";"
	else:
		for name in to_read:
			flag = 0
			if name == to_read[0]:
				continue
			for p in settings.process_list:
				if (p.data['name'] == name and p.curstatus != "running"
						and p.curstatus != "starting"):
					p.start_app()
					nw_str += p.data['name'] + ";"
					flag = 1
			if flag == 0:
				nw_str += (";err;ERROR (no such process) " + name)
	prompt.com(nw_str)

def stop(to_read):
	if (len(to_read) == 1):
		prompt.com("err;stop requires a process name")
		return
	nw_str = "stopped;"
	if ("all" in to_read):
		for p in settings.process_list:
			if (p.curstatus == "running" or p.curstatus == "starting"):
				p.proc.kill()
				p.proc.wait()
				p.curstatus = "Stopped"
				p.pid = None
				nw_str += p.data['name'] + ";"
	else:
		for name in to_read:
			flag = 0
			if name == to_read[0]:
				continue
			for p in settings.process_list:
				if (p.data['name'] == name
						and (p.curstatus == "running" or p.curstatus == "starting")):
					p.proc.kill()
					p.proc.wait()
					p.curstatus = "Stopped"
					p.pid = None
					nw_str += p.data['name'] + ";"
					flag = 1
			if flag == 0:
				nw_str += (";err;ERROR (no such process) " + name)
	prompt.com(nw_str)

def rload(to_read):
	tmp = read_config.read_config_file("config_file.conf")
	settings.process_list = read_config.read_config_file("config_file.conf")
	read_config.autostart(process_list)
	status("all")

def restart(to_read):
	if (len(to_read) == 1):
		prompt.com("err;restart requires a process name", c)
		return 
	stop(to_read)
	start(to_read)

def signal(to_read):
	for p in settings.process_list:
		if (p.pid <> None and p.proc <> None):
			p.graceful_kill()
	nw_str = "err;signal: %s" % p.proc
	prompt.com(nw_str)
