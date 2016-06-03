#define pi 3.14159265358979323

struct Point {
	double x;
	double y;
};

double *cdf;
double dx;
int divi;
double min, max;

double getrand(void);
int inst(double (*pdf)(double x), double minx, double maxx, int divisions, unsigned seed);
struct Point search(double *array, int start, int end, double value);
