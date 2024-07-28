#include "io_manager.h"

io_manager::io_manager(const std::string& inputFile_, const std::string& outputFile_)
	: inputFile(inputFile_), outputFile(outputFile_), graphic_points(20)
{
}

void io_manager::ReadDataFile(common_input& input, const std::string& inputFile_)
{
	if (inputFile_ != ".")
		inputFile = inputFile_;
	fileHandler.open(inputFile, std::ios::in);
	if (!fileHandler.is_open())
	{
		std::cout << "ERRO(IO_MANAGER): Nao foi possivel abrir o arquivo!\n";
		exit(-1);
	}

	std::string temp;
	
	for (unsigned int index = 0; std::getline(fileHandler, temp); index++)
	{
		double value = std::stod(temp);
		input.elem[index] = value;
	}

	fileHandler.close();
	/*
	//Gravidade
	std::getline();
	//Massa
	std::getline();
	//Coeficiente de arrasto
	std::getline();
	//Massa especifica do ar
	std::getline();
	//Area da seccao transversal
	std::getline();
	//Velocidade inicial de ascencao
	std::getline();
	//Altura inicial
	std::getline();
	*/

}

void io_manager::PrintDataFile(const common_output& output, const std::string& outputFile_)
{
	if (outputFile_ != ".")
		outputFile = outputFile_;
	fileHandler.open(outputFile, std::ios::out);
	if (!fileHandler.is_open())
	{
		std::cout << "ERRO(IO_MANAGER): Nao foi possivel abrir o arquivo!\n";
		exit(-1);
	}

	for (int index = 0; index < (sizeof(common_output::elem) / sizeof(double)); index++)
	{
		double a = output.elem[index];
		fileHandler << common_output_names[index] << ": " << output.elem[index] << std::endl;
	}
	fileHandler.close();
}

void io_manager::ReadDataCon(common_input& input)
{
	//Read from console
	std::cout << "Digite os dados que forem requisitados:\n";
	
	std::cout << "Gravidade (m s^-2): ";
	std::cin >> input.gravity;
	std::cout << "Massa (kg): ";
	std::cin >> input.mass;
	std::cout << "Coeficiente de arrasto (adim): ";
	std::cin >> input.drag_coeff;
	std::cout << "Massa especifica do ar (kg m^-3): ";
	std::cin >> input.air_specmass;
	std::cout << "Area da seccao transversal (m^2): ";
	std::cin >> input.area_ref;
	std::cout << "Velocidade inicial de ascencao (m/s): ";
	std::cin >> input.vel_ascent0;
	std::cout << "Altura inicial (m): ";
	std::cin >> input.h0;

	std::cout << "Todos os dados foram armazenados!" << std::endl;
}

void io_manager::PrintDataCon(const common_output& output)
{
	std::cout << "Calculos completos!\nResultados:\n";
	std::cout << "Tempo ate apogeu              (s): " << output.t_toApogee << "\n";
	std::cout << "Altura do apogeu              (m): " << output.h_ofApogee << "\n";
	std::cout << "Aceleracao maxima        (m s^-2): " << output.accel_max << "\n";
	std::cout << "Tempo para queda do apogeu    (t): " << output.t_toFall << "\n";
	std::cout << "Tempo total de voo            (t): " << output.t_flight << "\n";
	std::cout << "Velocidade de impacto       (m/s): " << output.vel_impact << "\n";
	std::cout << "Aceleracao no impacto    (m s^-2): " << output.accel_impact << "\n";
}

void io_manager::SetAmountPoints(int num)
{
	graphic_points = num;
}

