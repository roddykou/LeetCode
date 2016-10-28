#include <iostream>
#include <vector>
#include <cstdlib>		// rand
#include <ctime>		// sleep
#include <list>			// list

using namespace std;

const int NUM_NODES = 5;
const int MAX_NODE_RESOURCE = 10;
const int MAX_JOB_RESOURCE = 10;
const int MAX_JOB_TIME = 10;
const int MAX_NEW_JOB_INTERVAL = 5;

struct Job {
	int id;
	int totalTimeToFinish;
	int timeToFinish;
	int resource;
	Job (int i, int t, int r) :
		id(i), totalTimeToFinish(t), timeToFinish(t), resource(r) {}
};

struct Node {
	int id;
	int totalResource;
	int availableResouce;
	list<Job> runningJobs;
	Node (int i, int r) : id(i), totalResource(r), availableResouce(r) {}
};

enum State {
	VOID, NEW_JOB, JOB_DONE
};

static list<Node> nodes;
static list<Job> unscheduledJobs;
static int jobId = 0;
static State currentState = VOID;
static int maxNodeResource = 0;

void printStatus() {
	cout << "-------------------------------------------------" << endl;
	cout << "Listing all nodes and their jobs:" << endl;
	for (auto it = nodes.begin(); it != nodes.end(); it++) {
		Node node = *it;
		cout << "Node # " << node.id << " Total: " << node.totalResource << ", "
								  	 "Available: " << node.availableResouce;
		for (auto itr = node.runningJobs.begin(); itr != node.runningJobs.end(); itr++) {
			Job job = *itr;
			cout << "\tJob # " << job.id << " (" << job.totalTimeToFinish << " , "
											     << job.timeToFinish << " , "
											     << job.resource << ")\t";	
		}
		cout << endl;
	}

	cout << "Listing all unscheduled jobs:" << endl;
	for (auto it = unscheduledJobs.begin(); it != unscheduledJobs.end(); it++) {
		Job job = *it;
		cout << "Job # " << job.id << " (" << job.totalTimeToFinish << " , "
										   << job.timeToFinish << " , "
										   << job.resource << ")\t";
	}
	cout << endl << "-------------------------------------------------" << endl;
}

void init() {
	// init all nodes.
	for (int i = 0; i < NUM_NODES; i++) {
		int nodeResource = rand() % MAX_NODE_RESOURCE;
		maxNodeResource = max(maxNodeResource, nodeResource);
		Node newNode (i, nodeResource);
		nodes.push_back(newNode);
	}
	printStatus();
}

int generateNewEvent() {
	int nextJobInterval = rand() % MAX_NEW_JOB_INTERVAL;

	int nextJobDone = INT_MAX;
	for (auto it = nodes.begin(); it != nodes.end(); it++) {
		list<Job> runningJobs = (*it).runningJobs;
		for (auto itr = runningJobs.begin(); itr != runningJobs.end(); itr++) {
			nextJobDone = min(nextJobDone, (*itr).timeToFinish);
		}
	}

	currentState = (nextJobInterval < nextJobDone ? NEW_JOB : JOB_DONE);
	cout << "current state is " << (currentState == NEW_JOB ? "NEW_JOB" : "JOB_DONE") << endl;
	return min(nextJobDone, nextJobInterval);
}

void timeFlies(int sleepTime) {
	cout << "Sleeping for " << sleepTime << " seconds" << endl;

	for (auto it = nodes.begin(); it != nodes.end(); it++)
		for (auto itr = (*it).runningJobs.begin(); itr != (*it).runningJobs.end(); itr++)
			(*itr).timeToFinish -= sleepTime;

	sleep(sleepTime);
}

void processEvent() {
	if (currentState == NEW_JOB) {
		int jobResource = rand() % MAX_JOB_RESOURCE;
		Job newJob (jobId++, rand() % MAX_JOB_TIME, jobResource);
		unscheduledJobs.push_back(newJob);
		if (jobResource > maxNodeResource) {
			cout << "Dropping over-sized Job # " << newJob.id <<
									" resource " << newJob.resource << endl;
		} else {
			cout << "Creating new Job # " << newJob.id <<
						     " resource " << newJob.resource << endl;
		}
	} else if (currentState == JOB_DONE) {
		for (auto it = nodes.begin(); it != nodes.end(); it++) {
			for (auto itr = (*it).runningJobs.begin(); itr != (*it).runningJobs.end(); itr++) {
				if ((*itr).timeToFinish == 0) {
					(*it).availableResouce += (*itr).resource;
					(*it).runningJobs.erase(itr);
					itr--;
				}
			}
		}
	}

	// schedule new job if possible.
	for (auto it = unscheduledJobs.begin(); it != unscheduledJobs.end(); it++) {
		for (auto itr = nodes.begin(); itr != nodes.end(); itr++) {
			if ((*it).resource <= (*itr).availableResouce) {
				cout << "inserting job " << (*it).id << " into node " << (*itr).id << endl;
				(*itr).runningJobs.push_back((*it));
				(*itr).availableResouce -= (*it).resource;
				unscheduledJobs.erase(it);
				it--;
				break;
			}
		}
	}
}


int main() {
	srand (time(NULL));
	init();
	while (true) {
		timeFlies(generateNewEvent());
		processEvent();
		printStatus();
	}
}