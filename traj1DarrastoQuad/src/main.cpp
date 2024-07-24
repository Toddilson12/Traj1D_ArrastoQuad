#include <iostream>
#include "common.h"
#include "trajectory.h"
#include "io_manager.h"




int main()
{
	common_input input_data;
	common_output output_data;
	
	io_manager io;
	
	io.ReadDataCon(input_data);

	analytic_trajectory inst(&input_data, &output_data);
	inst.CalculateTrajectoryData();

	io.PrintDataCon(output_data);
	

	std::cin.get();
	return 0;
}