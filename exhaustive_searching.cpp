/*
Problem :

there are n people who need to be assigned to execute n jobs, one person per job. (That
is, each person is assigned to exactly one job and each job is assigned to exactly
one person.) The cost that would accure if the i-th person is assigned to the j-th job
is a known quantity C[i, j ] for each pair i, j = 1, 2, . . . , n. The problem is to find
an assignment with the minimum total cost. For instance:

	job1		job2		job3		job4
p1  	9		2		7		8
p2  	6		4		3		7
p3  	5		8		1		8
p4  	7		6		9		4

*/


#include <iostream>
#include <vector>
using namespace std;

short least_job(vector <short> costs) {
	short smallest_cost{1000}, job_number = 1; // 1000 represent infinite

	for (short i=0; i < 4; i++) {
		if (costs[i] < smallest_cost) {
			smallest_cost = costs[i];
			job_number = i;
		}
	}

	return (job_number + 1); // the job number (i.e. job 1, job 2)
}

// function to get the second least job
short least_job(vector <short> costs, short the_least) {
	short smallest_cost{1000}, job_number = 1;

	for (short i = 0; i < 4; i++) {
		if (costs[i] < smallest_cost && (i+1) != the_least) {
			smallest_cost = costs[i];
			job_number = i;
		}
	}

	return (job_number + 1);
}


bool is_contain(vector <short> costs, short cost) {
	for (short i = 0; i < 4; i++) {
		if (costs[i] == cost) {
			return true;
		}
	}
	return false;
}

int main() {

	vector < vector <short>> cost_matrix(4, vector<short>(4));
	for (short i = 0; i < 4; i++) {
		for (short j = 0; j < 4; j++) {
			cin >> cost_matrix[i][j];
		}
	}

	// a container to store the taken jobs
	vector <short> taken_jobs(4);

	for (short itr = 0; itr < 4; itr++) {
		short job_number = least_job(cost_matrix[itr]);

		// if the job is taken before --> get the 2nd least job
		if (is_contain(taken_jobs, job_number) == 1) {
			job_number = least_job(cost_matrix[itr], job_number) ;
			taken_jobs[itr] = job_number;
		}
		else {
			taken_jobs[itr] = job_number;
		}
	}

	for (short i = 0; i < 4; i++) {
		cout << "Person " << i + 1 << " takes job " << taken_jobs[i] << endl;
	}
}

