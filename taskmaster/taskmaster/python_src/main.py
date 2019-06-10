#!/usr/bin/python2.7

from read_config import autostart
from prompt import prompt
import settings

settings.init()

autostart(settings.process_list)

loop = 0
while (loop == 0):
	loop = prompt()

#exit
for p in settings.process_list:
	if (p.pid <> None and p.pid > 0):
		p.proc.kill()
settings.c.close()
