// Author: Zachary Obeid 
// Date: March 30 2017
// Reason Editied: Exam
//3350 midterm exam 3 framework
//Write a unit test to check the validity of the getPonderal function. 
//Program equations derived from the following source:
//  https://en.wikipedia.org/wiki/Corpulence_index
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;
double getPonderal(double mass, double height);

#ifdef UTEST
void unit_test(double tolerance); 
#endif

double m[160] = {135.000000, 
135.000000, 
135.000000, 
135.000000, 
135.000000, 
135.000000, 
135.000000, 
135.000000, 
135.000000, 
135.000000, 
135.000000, 
135.000000, 
135.000000, 
135.000000, 
135.000000, 
135.000000, 
136.918960, 
136.918960, 
136.918960, 
136.918960,
136.918960,
136.918960,
136.918960, 
136.918960, 
136.918960, 
136.918960, 
136.918960, 
136.918960, 
136.918960, 
136.918960, 
136.918960, 
136.918960, 
138.728600, 
138.728600, 
138.728600, 
138.728600, 
138.728600, 
138.728600, 
138.728600, 
138.728600, 
138.728600, 
138.728600, 
138.728600, 
138.728600, 
138.728600, 
138.728600, 
138.728600, 
138.728600, 
140.754928, 
140.754928, 
140.754928, 
140.754928, 
140.754928, 
140.754928, 
140.754928, 
140.754928, 
140.754928, 
140.754928, 
140.754928, 
140.754928, 
140.754928, 
140.754928, 
140.754928, 
140.754928, 
142.103320,
   
};

double height [160] = {
    50.000000,     
    51.591574,  
    53.789234,  
    55.085561,
    57.237906,
    59.068861,
    62.782269,
    65.156561,
    67.232507,
    69.142960,
    70.507290,
    72.713555,
    74.314972,  
    75.478185,
    76.805570,
    50.000000,
    51.956328,
    53.696703,
    55.135478,
    56.925596,
    58.525938,  
    59.950911,
    62.162497,
    63.267130,
    65.056123,
    66.344444,
    68.679793,
    69.776050,
    71.462603,
    72.820022,
    75.173335,
    50.000000,
    52.140373,
    54.141959,
    55.200879,
    57.598632,
    59.680060,
    61.787862,
    63.318935,  
    64.567896,
    66.888009,  
    68.383515,
    70.723573,
    72.753578,
    74.636538,
    76.924553,  
    79.310508,
    50.000000,
    51.723736,
    54.149115,
    55.370605,
    57.332225,
    59.261620, 
    61.440623, 
    63.111174,
    64.392473,
    66.227139,
    67.481550,
    68.636306,
    70.379473,
    72.856600,
    74.883268,
    77.007924,
    50.000000,
    51.366619,  
    53.464842,
    55.655047,
    57.772655,
    60.197811,
    61.980156,
    63.340249,
    65.439231,
    67.890339,  
    70.029941,

    };
double ponderal[160] = {
    13.572088,
    13.858594,
    14.259411,
    14.487443,
    14.862144,
    15.167211,
    15.806396,
    16.192184,
    16.534315,
    16.846072,
    17.066954,
    17.421154,
    17.676009,
    17.869980,
    18.068765,
    13.572088,
    13.923838,
    14.243064,
    14.486187,
    14.798069,
    15.074130,
    15.317828,
    15.702265,
    15.887621,
    16.175540,
    16.388393,
    16.770756,
    16.948747,
    17.220769,
    17.448155,
    17.811857,
    13.572088,
    13.956700,
    14.311637,
    14.497641,
    14.924480,
    15.271657,
    15.629153,
    15.886287,
    16.094510,
    16.477786,
    16.722490,
    17.101838,
    17.437546,
    17.726962,
    18.087421,
    18.459523,
    13.582088,
    13.882252,
    14.322898,
    14.527343,
    14.868456,
    15.200190,
    15.570542,
    15.851517,
    16.065346,
    16.369070,
    16.585121,
    16.763676,
    17.046321,
    17.453994,
    17.766008,
    18.100488,
    13.572088,
    13.818280,
    14.192063,
    14.577052,
    14.944505,
    15.359856,
    15.359856,
    15.661563,
    15.889852,
    16.238982,
    16.641992,
    16.989835,
        
    
};


int main(int argc, char *argv[])
{
#ifdef UTEST
    double t=0.01; 

	if (argc < 2) {
		cout << "No input was detected.                  \n";
		cout << "                                        \n";
		cout << "Program usage: ./program <tolerance>\n";
		cout << "(default values will be displayed)      \n";
	}
	if (argc > 1)
        t = atof(argv[1]);
    unit_test(t); 
#endif

	//Set default values
	double mass   = 1.0;
	double height = 1.0;
	//Get command-line arguments
	if (argc < 3) {
		cout << "No input was detected.                  \n";
		cout << "                                        \n";
		cout << "Program usage: ./program <mass> <height>\n";
		cout << "(default values will be displayed)      \n";
	}
	if (argc > 1)
		mass = atof(argv[1]);
	if (argc > 2)
		height = atof(argv[2]);
	cout << "Ponderal value is: ";
	//This formatting will help for your unit test output
	cout << setw(10) << left << fixed << setprecision(6);
	cout << getPonderal(mass, height) << endl;
	cout << endl;

	return 0;
}

double getPonderal(double mass, double height)
{
	double oneThird = 1.0 / 3.0;
	double cuberoot = pow(height, oneThird);
	double ponderal = height / cuberoot;
	return ponderal;
}

#ifdef UTEST
void unit_test(double tolerance) 
{
    double p; 

    cout << "unit test runnning..." << endl << endl; 
	cout << setw(10) << left << fixed << setprecision(6);
    cout << "mass";
	cout << setw(10) << left << fixed << setprecision(6);
    cout << "height"; 
	cout << setw(10) << left << fixed << setprecision(6);
    cout << "pondeal"; 
	cout << setw(10) << left << fixed << setprecision(6);
    cout << "returned" << endl; 
    for(int i =0; i<4; i++) {
        cout << setw(10) << left << fixed << setprecision(6);
        cout << "--------- ";
    }
    cout << endl; 

    for(int i =0; i<75; i++) {
        cout << setw(10) << left << fixed << setprecision(6);
        cout << m[i] << " ";
        cout << setw(10) << left << fixed << setprecision(6);
        cout << height[i] << " ";
        cout << setw(10) << left << fixed << setprecision(6);
        cout << ponderal[i]<< " ";
        cout << setw(10) << left << fixed << setprecision(6);
        p = getPonderal(m[i],height[i]);
        if( (ponderal[i]-p) >= tolerance ) {
            cout << setw(10) << left << fixed << setprecision(6);
            cout << p << " "; 
            cout << "<----- outside of tolerance"; 
        } 
        else {
            cout << setw(10) << left << fixed << setprecision(6);
            cout << p << " "; 

        }
        cout << endl;  

    } 
    cout << endl; 
    
}
#endif
