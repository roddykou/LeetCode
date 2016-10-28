""" Input:
Started name=dump_logs jobid=f863
Started name=dump_logs jobid=g301gas
...
Ended jobid=r0eas time=103
Ended jobid=f863 time=1021
Started name=grep_logs jobid=ac3de
Ended jobid=g301gas time=1343
Started name=read_logs jobid=r0eas
...
Started name=write_logs jobid=dg2dz
Ended jobid=ac3de time=52

Output:
Print out the names of the K distinct jobs (not job instance IDs, so de-dupe on
job name) with the longest running individual job instances (no totaling).
Note they can be out of order.

Example:
K=2
name 		Time
dump_logs 	1343
read_logs 	103
"""


log='''\
Started name=dump_logs jobid=g301gas
Ended jobid=g301gas time=1343
Started name=dump_logs jobid=f863
Ended jobid=f863 time=1021
Ended jobid=r0eas time=103
Started name=grep_logs jobid=ac3de
Started name=read_logs jobid=r0eas
Started name=write_logs jobid=dg2dz
Ended jobid=ac3de time=52'''

import re

def UpdateDictEntry(dictionary, key, value):
	if key in dictionary:
		dictionary[key] = max(dictionary[key], value)
	else:
		dictionary[key] = value

def ParseLogOnePass(log):
	id2name = {}
	name2time = {}
	wrong_ordered_jobs_id2time = {}
	lines = log.split('\n')
	for line in lines:
		words = re.split(' |=', line)
		if words[0] == 'Started':
			job_id = words[4]
			job_name = words[2]
			if job_id in wrong_ordered_jobs_id2time:
				job_time = wrong_ordered_jobs_id2time[job_id]
				# erase the entry from the wrong_ordered_jobs map
				UpdateDictEntry(name2time, job_name, int(job_time))
			else:
				id2name[job_id] = job_name
		else:
			job_id = words[2]
			job_time = words[4]
			if job_id in id2name:
				job_name = id2name[job_id]
				UpdateDictEntry(name2time, job_name, int(job_time))			
			else:
				wrong_ordered_jobs_id2time[job_id] = job_time

	name2time = sorted(name2time.iteritems(), key=lambda d:d[1], reverse = True)
	for n in range(0, 2):
		print name2time[n]


def ParseLogTwoPass(log):
	id2name = {}
	name2time = {}
	lines = log.split('\n')
	for line in lines:
		words = re.split(' |=', line)
		if words[0] == 'Started':
			job_id = words[4]
			job_name = words[2]
			id2name[job_id] = job_name

	for line in lines:
		words = re.split(' |=', line)
		if words[0] == 'Ended':
			job_id = words[2]
			job_time = words[4]
			job_name = id2name[job_id]
			UpdateDictEntry(name2time, job_name, int(job_time))


	print name2time

ParseLogOnePass(log)
ParseLogTwoPass(log)