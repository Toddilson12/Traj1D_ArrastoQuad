#include <iostream>
#include "common.h"
#include "trajectory.h"
#include "io_manager.h"


 
int main()
{
	common_input input_data;
	common_output output_data;
	
	io_manager io;
	
	//io.ReadDataCon(input_data);
	io.ReadDataFile(input_data, "INSIRA DIRETORIO DO ARQUIVO DE ENTRADA COM O .txt");

	analytic_trajectory inst(&input_data, &output_data);
	inst.CalculateTrajectoryData();

	io.PrintDataFile(output_data, "INSIRA DIRETORIO DO ARQUIVO DE SAIDA COM O .txt");
	
	//io.PrintDataCon(output_data);
	io.SetAmountPoints(50);
	io.PlotDataInGraph<analytic_trajectory>(inst); //USE "|" para separar as configuracoes e.g. ASCENT_POS | ASCENT_VEL | ...
	
	std::cout << "Aperte Enter para sair do programa\n";
	std::cin.get();
	return 0;
}
