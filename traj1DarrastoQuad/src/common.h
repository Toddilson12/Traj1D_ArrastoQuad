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


struct common_input
{
	double gravity;
	double mass;
	double drag_coeff;
	double air_specmass;
	double area_ref;
	double vel_ascent0;
	double h0;
};

struct common_output
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


