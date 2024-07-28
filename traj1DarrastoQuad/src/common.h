#pragma once

// Data structures
// Input file structure:
/*
[gravity]
[drag_coeff]
[air_specmas]
[ref_area]
[vel_ascent0]
[h0]
*/



union common_input
{
	struct 
	{
		double gravity;
		double mass;
		double drag_coeff;
		double air_specmass;
		double area_ref;
		double vel_ascent0;
		double h0;
	};
	double elem[7];
};

union common_output
{
	struct
	{
		// Ascent
		double t_toApogee;
		double h_ofApogee;
		// Descent
		double accel_max;
		double t_toFall; // From apogee
		// Final
		double t_flight; // Total flight time
		double vel_impact;
		double accel_impact;
	};
	double elem[7];
};

const std::string common_input_names[] = {
	"Gravidade (m s^-2)",
	"Massa (kg)",
	"Coeficiente de arrasto (adim)",
	"Massa especifica do ar (kg m^-3)",
	"Area da seccao transversal (m^2)",
	"Velocidade inicial de ascencao (m/s)",
	"Altura inicial (m)"
};


const std::string common_output_names[] = {
	"Tempo ate apogeu(s)",
	"Altura do apogeu(m)",
	"Aceleracao maxima(m s ^ -2)",
	"Tempo para queda do apogeu(t)",
	"Tempo total de voo(t)",
	"Velocidade de impacto(m / s)",
	"Aceleracao no impacto(m s ^ -2)"
};

