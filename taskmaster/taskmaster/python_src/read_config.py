#!/usr/bin/python2.7

from Class.Application_Class import Application
import multiprocessing
import copy

def read_config_file(path):
	f_config = open(path, 'r')
	str = f_config.readlines()
	f_config.close()
	process_list = []
	process_num = {}

	for line in str:
		tab = line[0:line.find(':')].count('\t')
		if (tab == 1):
			instance = Application(line[1:line.find(':')])
			process_list.append(instance)
		elif (tab == 2):
			config = line.split(':')
			if (len(config) > 2):
				name_conf = config[0].strip()
				instance.data[name_conf] = {}
				index = line.find(':') + 1
				config = line[index:].split(',')
				for elem in config:
					nw_conf = elem.split(':') 
					instance.data[name_conf][nw_conf[0].strip()] = nw_conf[1].strip()
			elif (len(config) == 2):
				instance.data[config[0].strip()] = config[1].strip()

	numprocs = []
	for proc in process_list:
		proc_name = proc.data['name']
		nb = int(proc.data['numprocs']) if ('numprocs' in proc.data) else 1
		if (nb > 1):
			while (nb > 1):
				numprocs.append(copy.deepcopy(proc))
				nb -= 1
		elif (nb < 1):
			process_list.remove(proc)

	for tmp in numprocs:
		buf = next(job for job in process_list if job.data['name'] == tmp.data['name'])
		i = process_list.index(buf)
		process_list.insert(i, tmp)
	return (process_list)

def autostart(process_list):
	for inst in process_list:
		if ("autostart" in  inst.data.keys() and inst.data["autostart"] == "true"):
			multiprocessing.Process(target=inst.start_app())
