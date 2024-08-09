#include <iostream>
#include "common.h"
#include "trajectory.h"
#include "io_manager.h"


 
int main()
{
	common_input input_data;
	common_output output_data;
	
	io_manager io;
	int option;
	//int num_point;
	
	std::cout << "MODO DE ENTRADA E SAIDA:\nARQUIVOS: DIGITE 1\nTERMINAL/CONSOLE: DIGITE 2\n";
	
	std::cin >> option;

	analytic_trajectory inst(&input_data, &output_data);

	if (option == 1)
	{
		io.ReadDataFile(input_data, "input/input.txt");
		inst.CalculateTrajectoryData();
		io.PrintDataFile(output_data, "output/output.txt");
	}
	
	if (option == 2)
	{
		io.ReadDataCon(input_data);;
		inst.CalculateTrajectoryData();
		io.PrintDataCon(output_data);
	}

	//io.SetAmountPoints(num_point);
	//io.PlotDataInGraph<analytic_trajectory>(inst); //USE "|" para separar as configuracoes e.g. ...(inst, ASCENT_POS | ASCENT_VEL | ...);
	
	std::cout << "\nAperte Enter para sair do programa\n";
	std::cin.get();
	std::cin.get();
	return 0;
}
